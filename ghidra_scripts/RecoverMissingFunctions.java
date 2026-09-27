// Create functions over executable code that Ghidra decoded but left outside
// any function body, then let its switch-table and reference analysis run over
// the result.  Run this before ExportFunctionMap so the exported map actually
// covers .text.
//
// Iterates to a fixed point: creating one function claims a body that may
// swallow several orphan runs, and the new function's flow can reach code that
// was previously unreferenced.
//
// Headless (note: no -readOnly, this modifies the program):
//   analyzeHeadless <projdir> <projname> -process game.exe -noanalysis \
//       -scriptPath /usr/src/rosemond/ghidra_scripts \
//       -postScript RecoverMissingFunctions.java
//
//@category Rosemond
//@keybinding
//@menupath
//@toolbar

import java.util.ArrayList;
import java.util.List;

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
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;

public class RecoverMissingFunctions extends GhidraScript {

    private static final int MAX_PASSES = 12;

    // Instructions a 32-bit compiler does not emit. Seeing one means the bytes
    // were never code.
    private static final String[] IMPLAUSIBLE = {
        "SLDT", "LLDT", "SGDT", "LGDT", "STR", "LTR", "LMSW", "SMSW", "CLTS",
        "LDS", "LES", "LFS", "LGS", "LSS", "ARPL", "BOUND", "INTO", "IN", "OUT",
        "INSB", "INSD", "OUTSB", "OUTSD", "HLT", "INVD", "WBINVD", "RSM",
        "LCALL", "LJMP", "LRET", "ICEBP", "UD2", "UD0", "UD1", "SALC", "AAA",
        "AAS", "AAM", "AAD", "DAA", "DAS", "XLAT", "LOADALL", "VERR", "VERW"
    };

    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();

        AddressSet executable = new AddressSet();
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (b.isExecute()) {
                executable.addRange(b.getStart(), b.getEnd());
            }
        }

        // Routines a compiler only ever reaches through a table -- virtual
        // dispatch, a jump table in .data, a thunk whose address is stored and
        // called later -- have nothing in the code pointing at them, so the
        // analysis never decodes them at all. Their addresses are sitting in the
        // data sections, which is where to go looking.
        int fromData = createFunctionsFromDataPointers(listing, executable);

        int totalCreated = fromData;
        for (int pass = 1; pass <= MAX_PASSES; pass++) {
            monitor.checkCancelled();
            List<Address> starts = findOrphanCodeStarts(listing, executable);
            if (starts.isEmpty()) {
                println(String.format(
                        "pass %d: no orphan code left", pass));
                break;
            }

            int created = 0;
            int failed = 0;
            monitor.initialize(starts.size());
            monitor.setMessage("Pass " + pass + ": creating functions");
            for (Address a : starts) {
                monitor.checkCancelled();
                monitor.incrementProgress(1);
                // Re-check: an earlier createFunction in this pass may already
                // have claimed this address.
                if (getFunctionContaining(a) != null) {
                    continue;
                }
                Function f = createFunction(a, null);
                if (f != null) {
                    created++;
                } else {
                    failed++;
                }
            }
            totalCreated += created;
            println(String.format(
                    "pass %d: %d orphan code runs, created %d functions (%d refused)",
                    pass, starts.size(), created, failed));
            if (created == 0) {
                break;
            }
        }

        int count = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            it.next();
            count++;
        }

        long claimed = 0;
        AddressSet covered = new AddressSet();
        it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            covered.add(it.next().getBody());
        }
        claimed = covered.getNumAddresses();
        long execSize = executable.getNumAddresses();

        println(String.format(
                "RecoverMissingFunctions: created %d functions (%d of them from "
                + "data pointers); %d total; "
                + "coverage %d/%d bytes (%.1f%%) of executable memory",
                totalCreated, fromData, count, claimed, execSize,
                100.0 * claimed / execSize));
    }

    // Every aligned dword in the data sections that points into executable
    // memory is a candidate function. Most are real -- tables of function
    // pointers are how this kind of code is dispatched -- but a value that
    // happens to fall in range is not, so a candidate is only accepted if it
    // disassembles and is not already part of something.
    private int createFunctionsFromDataPointers(Listing listing,
            AddressSet executable) throws Exception {
        long lowest = executable.getMinAddress().getOffset();
        long highest = executable.getMaxAddress().getOffset();

        List<Address> candidates = new ArrayList<>();
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            if (block.isExecute() || !block.isInitialized()) {
                continue;
            }
            monitor.checkCancelled();
            monitor.setMessage("Scanning " + block.getName() + " for code pointers");

            long start = block.getStart().getOffset();
            long end = block.getEnd().getOffset() + 1;
            // Aligned only: a compiler emits these tables dword aligned, and
            // scanning every offset would mostly turn up coincidences.
            for (long at = (start + 3) & ~3L; at + 4 <= end; at += 4) {
                monitor.checkCancelled();
                int value;
                try {
                    value = currentProgram.getMemory().getInt(toAddr(at));
                } catch (Exception e) {
                    continue;
                }
                long target = value & 0xffffffffL;
                if (target < lowest || target > highest) {
                    continue;
                }
                Address a = toAddr(target);
                if (!executable.contains(a) || getFunctionContaining(a) != null) {
                    continue;
                }
                candidates.add(a);
            }
        }

        int created = 0;
        int refused = 0;
        monitor.initialize(candidates.size());
        monitor.setMessage("Creating functions from data pointers");
        for (Address a : candidates) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            if (getFunctionContaining(a) != null) {
                continue;
            }
            CodeUnit cu = listing.getCodeUnitContaining(a);
            // Landing inside an existing instruction means the value is not a
            // function pointer; leave it alone rather than carve up real code.
            if (cu instanceof Instruction && !cu.getMinAddress().equals(a)) {
                refused++;
                continue;
            }
            // Landing on data the analysis has already typed means the value is
            // an entry in a table rather than the address of one: switch tables
            // live in the code section too, and almost any byte sequence will
            // disassemble into something, so decoding here would invent a
            // function out of a jump table.
            if (cu instanceof Data && ((Data) cu).isDefined()) {
                refused++;
                continue;
            }
            if (listing.getInstructionAt(a) == null) {
                disassemble(a);
                if (listing.getInstructionAt(a) == null) {
                    refused++;       // not decodable: not code
                    continue;
                }
            }
            Function created_ = createFunction(a, null);
            if (created_ == null) {
                refused++;
                continue;
            }
            // Almost any byte sequence disassembles into something, so the fact
            // that it decoded proves nothing. What settles it is what it decoded
            // into: a table of small values and zeros produces instructions a
            // compiler never emits, so if the body reads like that the region was
            // data and the function has to go again.
            if (!plausibleCode(created_)) {
                // Undo the decoding as well, not just the function. Instructions
                // left behind would be picked up as orphan code by the passes
                // below and turned straight back into a function.
                AddressSetView body = created_.getBody();
                removeFunctionAt(a);
                clearListing(body);
                refused++;
                continue;
            }
            created++;
        }

        println(String.format(
                "data pointers: %d candidates, created %d functions (%d refused)",
                candidates.size(), created, refused));
        return created;
    }

    // Does this function body read like compiled code?
    //
    // Segment-register and system instructions do not appear in 32-bit
    // application code, and an instruction whose bytes are all zero is a run of
    // padding or table entries rather than anything anyone emitted.
    private boolean plausibleCode(Function function) throws Exception {
        InstructionIterator instructions =
                currentProgram.getListing().getInstructions(function.getBody(), true);
        int count = 0;
        while (instructions.hasNext()) {
            monitor.checkCancelled();
            Instruction insn = instructions.next();
            count++;

            String mnemonic = insn.getMnemonicString().toUpperCase();
            for (String bogus : IMPLAUSIBLE) {
                if (mnemonic.equals(bogus)) {
                    return false;
                }
            }

            boolean allZero = true;
            for (byte b : insn.getBytes()) {
                if (b != 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero) {
                return false;
            }
        }
        return count > 0;
    }

    // Start address of every maximal run of instructions that belongs to no
    // function.  Only runs something references are returned: an unreferenced
    // run is usually the tail of a function whose body Ghidra got wrong, and
    // forcing a function there just entrenches the mistake.
    private List<Address> findOrphanCodeStarts(Listing listing,
            AddressSet executable) throws Exception {
        AddressSet orphans = new AddressSet(executable);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            monitor.checkCancelled();
            orphans.delete(it.next().getBody());
        }

        List<Address> starts = new ArrayList<>();
        for (AddressRange range : orphans.getAddressRanges()) {
            monitor.checkCancelled();
            long end = range.getMaxAddress().getOffset() + 1;
            long at = range.getMinAddress().getOffset();
            boolean inRun = false;
            while (at < end) {
                Address a = toAddr(at);
                CodeUnit cu = listing.getCodeUnitContaining(a);
                if (cu instanceof Instruction) {
                    if (!inRun) {
                        inRun = true;
                        if (currentProgram.getReferenceManager()
                                .hasReferencesTo(a)) {
                            starts.add(a);
                        }
                    }
                    long len = cu.getLength()
                            - (at - cu.getMinAddress().getOffset());
                    at += len > 0 ? len : 1;
                } else {
                    inRun = false;
                    at++;
                }
            }
        }
        return starts;
    }
}
