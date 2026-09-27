// Export Ghidra's analysis results as a JSON function map for the rosemond
// disassembler.  Emits, for every function Ghidra found: its entry point, the
// exact address ranges of its body, an authoritative code/data byte map, the
// resolved destinations of computed (switch-table / vtable) jumps and calls,
// and its symbol name.  Also emits the executable bytes that belong to no
// function at all, which is the list of things to go look at by hand.
//
// Run from the GUI Script Manager, or headless:
//   analyzeHeadless <projdir> <projname> -process game.exe -noanalysis \
//       -scriptPath /usr/src/rosemond/ghidra_scripts \
//       -postScript ExportFunctionMap.java /usr/src/rosemond/afrh/functions.json
//
//@category Rosemond
//@keybinding
//@menupath
//@toolbar

import java.io.PrintWriter;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

public class ExportFunctionMap extends GhidraScript {

    private PrintWriter out;

    @Override
    public void run() throws Exception {
        String path;
        String[] args = getScriptArgs();
        if (args.length > 0) {
            path = args[0];
        } else {
            File f = askFile("Export function map", "Save");
            path = f.getAbsolutePath();
        }

        out = new PrintWriter(path);
        try {
            emit();
        } finally {
            out.close();
        }
        println("ExportFunctionMap: wrote " + path);
    }

    private void emit() throws Exception {
        Listing listing = currentProgram.getListing();
        long imageBase = currentProgram.getImageBase().getOffset();

        out.println("{");
        out.println("  \"program\": " + quote(currentProgram.getName()) + ",");
        out.println("  \"image_base\": " + imageBase + ",");

        // ---- memory blocks -------------------------------------------------
        AddressSet executable = new AddressSet();
        out.println("  \"blocks\": [");
        MemoryBlock[] blocks = currentProgram.getMemory().getBlocks();
        for (int i = 0; i < blocks.length; i++) {
            MemoryBlock b = blocks[i];
            out.print("    {\"name\": " + quote(b.getName())
                    + ", \"start\": " + b.getStart().getOffset()
                    + ", \"end\": " + (b.getEnd().getOffset() + 1)
                    + ", \"r\": " + b.isRead()
                    + ", \"w\": " + b.isWrite()
                    + ", \"x\": " + b.isExecute()
                    + ", \"initialized\": " + b.isInitialized() + "}");
            out.println(i + 1 < blocks.length ? "," : "");
            if (b.isExecute()) {
                executable.addRange(b.getStart(), b.getEnd());
            }
        }
        out.println("  ],");

        // ---- functions -----------------------------------------------------
        AddressSet covered = new AddressSet();
        List<Function> functions = new ArrayList<>();
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            functions.add(it.next());
        }

        monitor.initialize(functions.size());
        monitor.setMessage("Exporting function map");

        out.println("  \"functions\": [");
        for (int i = 0; i < functions.size(); i++) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            Function f = functions.get(i);
            emitFunction(listing, f, covered);
            out.println(i + 1 < functions.size() ? "," : "");
        }
        out.println("  ],");

        // ---- executable bytes claimed by no function -----------------------
        // These are what your sweep currently has to guess at: unreached code,
        // data parked in .text, and alignment padding between functions.  Each
        // gap is split into homogeneous runs so a "code" entry means genuinely
        // missed code rather than a big range that merely contains some.
        AddressSet orphans = new AddressSet(executable);
        orphans.delete(covered);
        List<String> gaps = new ArrayList<>();
        for (AddressRange r : orphans.getAddressRanges()) {
            collectGaps(listing, r, gaps);
        }
        out.println("  \"unclaimed\": [");
        for (int i = 0; i < gaps.size(); i++) {
            out.print("    " + gaps.get(i));
            out.println(i + 1 < gaps.size() ? "," : "");
        }
        out.println("  ]");
        out.println("}");
    }

    private void emitFunction(Listing listing, Function f, AddressSet covered)
            throws Exception {
        AddressSetView body = f.getBody();
        covered.add(body);

        Symbol sym = f.getSymbol();
        boolean defaultName = sym == null
                || sym.getSource() == SourceType.DEFAULT;

        out.println("    {");
        out.println("      \"entry\": " + f.getEntryPoint().getOffset() + ",");
        out.println("      \"name\": " + quote(f.getName()) + ",");
        out.println("      \"default_name\": " + defaultName + ",");
        out.println("      \"thunk\": " + f.isThunk() + ",");
        out.println("      \"noreturn\": " + f.hasNoReturn() + ",");
        out.println("      \"external\": " + f.isExternal() + ",");
        out.println("      \"stack_purge\": " + f.getStackPurgeSize() + ",");
        out.println("      \"calling_convention\": "
                + quote(f.getCallingConventionName()) + ",");

        // Body ranges, each with an authoritative code/data byte map: a run of
        // lengths where a positive number is an instruction of that many bytes
        // and a negative number is that many bytes of non-code.  Replaying
        // these from the range start reproduces every instruction boundary
        // Ghidra found, so capstone never has to re-derive them.
        out.println("      \"ranges\": [");
        AddressRange[] ranges = toArray(body);
        TreeSet<String> computedJumps = new TreeSet<>();
        TreeSet<String> computedCalls = new TreeSet<>();
        TreeSet<Long> callees = new TreeSet<>();

        for (int i = 0; i < ranges.length; i++) {
            AddressRange r = ranges[i];
            long start = r.getMinAddress().getOffset();
            long end = r.getMaxAddress().getOffset() + 1;
            List<Long> items = new ArrayList<>();

            long at = start;
            while (at < end) {
                monitor.checkCancelled();
                Address a = toAddr(at);
                CodeUnit cu = listing.getCodeUnitContaining(a);
                long len;
                boolean code = false;
                if (cu == null) {
                    len = 1;
                } else {
                    // A code unit may start before the range (shared tails);
                    // only consume the part inside this range.
                    long cuStart = cu.getMinAddress().getOffset();
                    len = cu.getLength() - (at - cuStart);
                    code = cu instanceof Instruction;
                }
                if (len <= 0) {
                    len = 1;
                }
                if (at + len > end) {
                    len = end - at;
                }

                if (code) {
                    Instruction insn = (Instruction) cu;
                    collectComputed(insn, computedJumps, computedCalls, callees);
                    items.add(len);
                } else {
                    items.add(-len);
                }
                at += len;
            }

            out.print("        {\"start\": " + start + ", \"end\": " + end
                    + ", \"items\": [");
            for (int k = 0; k < items.size(); k++) {
                out.print(items.get(k));
                if (k + 1 < items.size()) {
                    out.print(", ");
                }
            }
            out.print("]}");
            out.println(i + 1 < ranges.length ? "," : "");
        }
        out.println("      ],");

        out.println("      \"computed_jumps\": {" + String.join(", ", computedJumps) + "},");
        out.println("      \"computed_calls\": {" + String.join(", ", computedCalls) + "},");
        out.print("      \"callees\": [");
        int k = 0;
        for (Long c : callees) {
            out.print(c);
            if (++k < callees.size()) {
                out.print(", ");
            }
        }
        out.println("]");
        out.print("    }");
    }

    // Resolved destinations of indirect jumps/calls, keyed by the address of
    // the instruction.  For an indirect jmp these are the switch-table cases
    // Ghidra recovered; the disassembler's dynamic_labels want exactly this.
    private void collectComputed(Instruction insn, TreeSet<String> jumps,
            TreeSet<String> calls, TreeSet<Long> callees) {
        List<Long> j = new ArrayList<>();
        List<Long> c = new ArrayList<>();
        for (Reference ref : insn.getReferencesFrom()) {
            RefType t = ref.getReferenceType();
            Address target = ref.getToAddress();
            // Imports live in Ghidra's EXTERNAL space, where offsets are small
            // indices rather than addresses; the disassembler resolves those
            // through the rewritten IAT instead.
            if (!currentProgram.getMemory().contains(target)) {
                continue;
            }
            long to = target.getOffset();
            if (t.isJump()) {
                if (t.isComputed() || t.isIndirect()) {
                    j.add(to);
                }
            } else if (t.isCall()) {
                callees.add(to);
                if (t.isComputed() || t.isIndirect()) {
                    c.add(to);
                }
            }
        }
        if (!j.isEmpty()) {
            jumps.add(entry(insn.getAddress().getOffset(), j));
        }
        if (!c.isEmpty()) {
            calls.add(entry(insn.getAddress().getOffset(), c));
        }
    }

    private String entry(long address, List<Long> targets) {
        StringBuilder sb = new StringBuilder();
        sb.append('"').append(address).append("\": [");
        for (int i = 0; i < targets.size(); i++) {
            sb.append(targets.get(i));
            if (i + 1 < targets.size()) {
                sb.append(", ");
            }
        }
        return sb.append(']').toString();
    }

    // Split one unclaimed range into runs of a single kind, so each emitted
    // gap is homogeneous.  "padding" goes straight onto the ignore list,
    // "data" onto DATA_SEGMENTS, and "code" means Ghidra decoded instructions
    // there but never made a function of them -- those are the real boundary
    // problems worth looking at, especially the ones marked referenced.
    private void collectGaps(Listing listing, AddressRange range,
            List<String> gaps) throws Exception {
        long start = range.getMinAddress().getOffset();
        long end = range.getMaxAddress().getOffset() + 1;

        long runStart = start;
        String runKind = null;
        long at = start;
        while (at < end) {
            monitor.checkCancelled();
            Address a = toAddr(at);
            CodeUnit cu = listing.getCodeUnitContaining(a);
            String kind;
            long len;
            if (cu instanceof Instruction) {
                kind = "code";
                len = cu.getLength() - (at - cu.getMinAddress().getOffset());
            } else if (cu instanceof Data && ((Data) cu).isDefined()) {
                kind = "data";
                len = cu.getLength() - (at - cu.getMinAddress().getOffset());
            } else {
                kind = isPadding(a) ? "padding" : "undefined";
                len = 1;
            }
            if (len <= 0) {
                len = 1;
            }
            if (at + len > end) {
                len = end - at;
            }
            if (runKind == null) {
                runKind = kind;
            } else if (!runKind.equals(kind)) {
                gaps.add(gap(runStart, at, runKind));
                runStart = at;
                runKind = kind;
            }
            at += len;
        }
        if (runKind != null) {
            gaps.add(gap(runStart, end, runKind));
        }
    }

    private boolean isPadding(Address a) {
        try {
            byte b = currentProgram.getMemory().getByte(a);
            return b == 0 || b == (byte) 0x90 || b == (byte) 0xcc;
        } catch (Exception e) {
            return false;
        }
    }

    private String gap(long start, long end, String kind) {
        // Referenced gaps are the interesting ones: something jumps or calls
        // into them, so they are almost certainly function entries Ghidra
        // declined to create.
        boolean referenced = false;
        try {
            referenced = currentProgram.getReferenceManager()
                    .hasReferencesTo(toAddr(start));
        } catch (Exception e) {
            // leave false
        }
        return "{\"start\": " + start + ", \"end\": " + end
                + ", \"kind\": " + quote(kind)
                + ", \"referenced\": " + referenced + "}";
    }

    private AddressRange[] toArray(AddressSetView set) {
        List<AddressRange> list = new ArrayList<>();
        for (AddressRange r : set.getAddressRanges()) {
            list.add(r);
        }
        return list.toArray(new AddressRange[0]);
    }

    private static String quote(String s) {
        if (s == null) {
            return "null";
        }
        StringBuilder sb = new StringBuilder("\"");
        for (char ch : s.toCharArray()) {
            switch (ch) {
                case '"':  sb.append("\\\""); break;
                case '\\': sb.append("\\\\"); break;
                case '\n': sb.append("\\n");  break;
                case '\r': sb.append("\\r");  break;
                case '\t': sb.append("\\t");  break;
                default:
                    if (ch < 0x20 || ch > 0x7e) {
                        sb.append(String.format("\\u%04x", (int) ch));
                    } else {
                        sb.append(ch);
                    }
            }
        }
        return sb.append('"').toString();
    }
}
