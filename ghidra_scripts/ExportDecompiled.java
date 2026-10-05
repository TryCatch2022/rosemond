// Move functions of game.exe from translated assembly to decompiled C++.
//
// Each run does two things:
//
//  1. For every function asked for, writes Ghidra's decompilation of it to
//     src/game/decomp/<name>_<address>.cpp and records it in
//     src/game/decomp/registry.json. From then on the disassembler emits a stub
//     for that address instead of translating its body. The .cpp belongs to the
//     project: a later run overwrites it only while it is still what the last
//     export wrote. Once edited, the GUI asks first; headless, the fresh
//     decompilation goes to <file>.ghidra beside it, unless --force is given.
//
//  2. Regenerates, wholesale, what stays Ghidra's: src/game/ghidra/types.h
//     (structures, unions, enums, typedefs), globals.h (every defined data item
//     as a reference to its address in the loaded image), functions.h (a C++
//     prototype for every function) and prototypes.json (where each function's
//     parameters and return value live, which the stub generator reads).
//
// Every run also brings the decompiled files already in the registry up to
// date: one still exactly as an export wrote it is written again, and in one
// that has been edited, whatever was renamed in Ghidra since the last run
// (functions, globals, types; names.json remembers them) is renamed too.
//
// From the GUI it exports the function under the cursor; bind it to a key in
// the Script Manager. Headless, it takes the entry points as arguments, or
// none to only refresh the generated headers. Each decompiled function is
// written with the instructions it came from in comments above each line;
// pass --no-asm to leave them out:
//
//   analyzeHeadless <projdir> <projname> -process game.exe -noanalysis -readOnly \
//       -scriptPath ghidra_scripts -postScript ExportDecompiled.java 0x409840
//
// decompile.py in the repository root wraps that. Then build: the entry points
// and stubs between translated and decompiled code are generated at build time
// from what this writes, so the disassembler need not run again.
//
//@category Rosemond
//@keybinding
//@menupath
//@toolbar

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonNull;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import ghidra.app.decompiler.ClangFieldToken;
import ghidra.app.decompiler.ClangFuncNameToken;
import ghidra.app.decompiler.ClangLine;
import ghidra.app.decompiler.ClangSyntaxToken;
import ghidra.app.decompiler.ClangToken;
import ghidra.app.decompiler.ClangTypeToken;
import ghidra.app.decompiler.ClangVariableToken;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.component.DecompilerUtils;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.AbstractStringDataType;
import ghidra.program.model.data.Array;
import ghidra.program.model.data.BitFieldDataType;
import ghidra.program.model.data.BuiltInDataType;
import ghidra.program.model.data.Composite;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.DataTypeComponent;
import ghidra.program.model.data.DataTypeManager;
import ghidra.program.model.data.Enum;
import ghidra.program.model.data.FunctionDefinition;
import ghidra.program.model.data.ParameterDefinition;
import ghidra.program.model.data.Pointer;
import ghidra.program.model.data.SourceArchive;
import ghidra.program.model.data.Structure;
import ghidra.program.model.data.TypeDef;
import ghidra.program.model.data.Union;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.data.VoidDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.VariableStorage;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.pcode.FunctionPrototype;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.pcode.HighVariable;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.Varnode;
import ghidra.program.model.symbol.ExternalLocation;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

public class ExportDecompiled extends GhidraScript {

    // Where the files go, relative to the repository root.
    private static final String OWNED_DIR = "src/game/decomp";
    private static final String GENERATED_DIR = "src/game/ghidra";
    private static final String REGISTRY = OWNED_DIR + "/registry.json";

    // Memory blocks whose data items are globals. The PE headers and the TEB
    // block Ghidra adds are not the game's data.
    private static final Set<String> SKIPPED_BLOCKS = new HashSet<>(Arrays.asList("Headers", "tdb"));

    private static final Set<String> CALLING_CONVENTIONS = new HashSet<>(Arrays.asList(
        "__cdecl", "__stdcall", "__fastcall", "__thiscall", "__vectorcall", "__pascal", "__regcall"));

    // Not usable as a C++ identifier: keywords, and what <windows.h> defines as
    // a macro under a name a function, parameter or field might plausibly get.
    private static final Set<String> RESERVED = new HashSet<>(Arrays.asList(
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break",
        "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr",
        "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast",
        "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto",
        "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
        "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register",
        "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "true",
        "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
        "volatile", "wchar_t", "while", "xor", "xor_eq",
        "min", "max", "near", "far", "small", "hyper", "interface", "pascal", "cdecl", "IN", "OUT",
        "OPTIONAL", "CALLBACK", "WINAPI", "CONST", "VOID", "TRUE", "FALSE", "NULL", "errno",
        "game", "win32", "x86", "ghidra", "std"));

    // Ghidra builtins ghidra_compat.h (or C++ itself) gives a definition.
    private static final Set<String> COMPAT_TYPES = new HashSet<>(Arrays.asList(
        "void", "undefined", "undefined1", "undefined2", "undefined3", "undefined4", "undefined5",
        "undefined6", "undefined7", "undefined8", "byte", "sbyte", "uchar", "schar", "char",
        "word", "sword", "ushort", "short", "dword", "sdword", "uint", "int", "ulong", "long",
        "qword", "sqword", "ulonglong", "longlong", "uint3", "int3", "uint5", "uint6", "uint7",
        "int5", "int6", "int7", "float", "double", "float10", "longdouble", "bool", "wchar_t",
        "wchar16", "wchar32", "code"));

    private File root;
    private DataTypeManager dtm;

    // The project's own data types, in the order they can be defined.
    private List<DataType> userTypes = new ArrayList<>();
    private Set<String> userTypePaths = new HashSet<>();
    private Map<String, String> typeNames = new HashMap<>();             // path -> C++ name
    private Map<String, Map<Integer, String>> fieldNames = new HashMap<>(); // path -> offset -> field
    private Map<String, String> enumValueNames = new HashMap<>();         // Ghidra name -> C++ name
    private Map<Address, String> functionNames = new HashMap<>();
    private Map<String, Function> externals;
    // Whether a decompiled function is written with its machine code in
    // comments, for checking the C against it. --no-asm leaves them out.
    private boolean withAssembly = true;
    // Overwrite a decompiled file even if it was edited since its export.
    private boolean force = false;
    private Map<Address, String> globalNames = new HashMap<>();
    private Set<String> taken = new HashSet<>();
    private List<String> warnings = new ArrayList<>();

    @Override
    public void run() throws Exception {
        // The repository is the directory above this script's own. Resolved,
        // so that reaching the script through a link (~/ghidra_scripts linked
        // to the repository's, or a junction on Windows) still finds the
        // repository, not the home.
        root = getSourceFile().getFile(false).toPath().toRealPath().getParent().getParent().toFile();
        dtm = currentProgram.getDataTypeManager();

        List<Function> targets = new ArrayList<>();
        List<String> args = new ArrayList<>();
        for (String arg : getScriptArgs()) {
            if (arg.equals("--no-asm")) {
                withAssembly = false;
            }
            else if (arg.equals("--force")) {
                force = true;
            }
            else {
                args.add(arg);
            }
        }
        if (!args.isEmpty()) {
            for (String arg : args) {
                Address address = toAddr(arg.startsWith("0x") ? arg.substring(2) : arg);
                Function f = address == null ? null : getFunctionAt(address);
                if (f == null) {
                    throw new IllegalArgumentException("no function starts at " + arg);
                }
                targets.add(f);
            }
        }
        else if (!isRunningHeadless()) {
            Function f = currentLocation == null ? null
                : getFunctionContaining(currentLocation.getAddress());
            if (f == null) {
                throw new IllegalArgumentException("put the cursor in the function to export");
            }
            targets.add(f);
        }

        nameEverything();
        new File(root, GENERATED_DIR).mkdirs();
        new File(root, OWNED_DIR).mkdirs();
        writeTypes();
        writeGlobals();

        // Every function the project owns is decompiled again, so that its
        // declaration and stubs follow what the decompiler makes of it now.
        JsonObject registry = readRegistry();
        Map<Address, DecompileResults> results = new LinkedHashMap<>();
        List<Function> owned = new ArrayList<>(targets);
        for (String entry : registry.getAsJsonObject("functions").keySet()) {
            Function f = getFunctionAt(toAddr(entry.substring(2)));
            if (f == null) {
                warnings.add("registry entry " + entry + " is no longer a function in Ghidra");
            }
            else if (!owned.contains(f)) {
                owned.add(f);
            }
        }
        if (!owned.isEmpty()) {
            DecompInterface decompiler = new DecompInterface();
            try {
                decompiler.setOptions(new DecompileOptions());
                decompiler.toggleCCode(true);
                decompiler.toggleSyntaxTree(true);
                decompiler.setSimplificationStyle("decompile");
                if (!decompiler.openProgram(currentProgram)) {
                    throw new IllegalStateException("decompiler: " + decompiler.getLastMessage());
                }
                for (Function f : owned) {
                    if (f.isThunk() || f.isExternal()) {
                        throw new IllegalArgumentException(f.getName() + " is a thunk; export what it calls");
                    }
                    DecompileResults r = decompiler.decompileFunction(f, 120, monitor);
                    if (!r.decompileCompleted() || r.getCCodeMarkup() == null || r.getHighFunction() == null) {
                        throw new IllegalStateException("decompiling " + f.getName() + ": " + r.getErrorMessage());
                    }
                    results.put(f.getEntryPoint(), r);
                    decompiled.put(f.getEntryPoint(), r.getHighFunction());
                }
            }
            finally {
                decompiler.dispose();
            }
        }
        writeFunctions();

        // The decompiled files follow Ghidra too. One still exactly as an export
        // wrote it is simply written again; one that has been edited keeps the
        // edits, and only has the functions, globals and types renamed in Ghidra
        // since the last run renamed in it as well.
        Map<String, String> renames = renames();
        writeNames();
        JsonObject functions = registry.getAsJsonObject("functions");
        int refreshed = 0;
        for (Function f : owned) {
            String entry = String.format("0x%08x", f.getEntryPoint().getOffset());
            if (targets.contains(f) || !functions.has(entry)) {
                continue;
            }
            JsonObject item = functions.getAsJsonObject(entry);
            File file = new File(root, item.get("file").getAsString());
            if (!file.exists()) {
                warnings.add(item.get("file").getAsString() + " is in the registry but missing");
                continue;
            }
            String content = Files.readString(file.toPath(), StandardCharsets.UTF_8);
            if (item.has("hash") && item.get("hash").getAsString().equals(sha256(content))) {
                exportFunction(f, results.get(f.getEntryPoint()), registry);
                refreshed++;
            }
            else {
                String renamed = applyRenames(content, renames);
                if (!renamed.equals(content)) {
                    Files.writeString(file.toPath(), renamed, StandardCharsets.UTF_8);
                    println("renamed in " + item.get("file").getAsString() + " (edited, so not re-exported)");
                }
                item.addProperty("name", functionNames.get(f.getEntryPoint()));
            }
        }
        for (Function f : targets) {
            exportFunction(f, results.get(f.getEntryPoint()), registry);
        }
        writeRegistry(registry);
        if (refreshed > 0) {
            println("refreshed " + refreshed + " unedited decompiled file(s)");
        }

        for (String warning : warnings) {
            println("warning: " + warning);
        }
        println("ExportDecompiled: " + userTypes.size() + " types, " + globalNames.size()
            + " globals, " + functionNames.size() + " functions; exported " + targets.size());
    }

    // ------------------------------------------------------------------
    // Names
    // ------------------------------------------------------------------

    private static String ident(String name) {
        StringBuilder b = new StringBuilder();
        for (char c : name.toCharArray()) {
            b.append((c < 128 && Character.isLetterOrDigit(c)) || c == '_' ? c : '_');
        }
        String s = b.toString().replaceAll("_{2,}", "_");
        while (s.length() > 1 && s.endsWith("_")) {
            s = s.substring(0, s.length() - 1);
        }
        if (s.isEmpty() || s.equals("_")) {
            s = "anonymous";
        }
        if (Character.isDigit(s.charAt(0))) {
            s = "n" + s;
        }
        if (RESERVED.contains(s)) {
            s = s + "_";
        }
        return s;
    }

    // Assigns every name the generated headers declare in namespace game. The
    // order decides who keeps a contested name: types, then functions, then
    // globals, then enum constants. A name more than one item wants is given
    // to none of them; each gets its address (or a counter) appended instead.
    private void nameEverything() {
        collectUserTypes();

        Map<String, List<DataType>> typesByName = new HashMap<>();
        for (DataType dt : userTypes) {
            typesByName.computeIfAbsent(ident(dt.getName()), k -> new ArrayList<>()).add(dt);
        }
        for (Map.Entry<String, List<DataType>> e : typesByName.entrySet()) {
            List<DataType> list = e.getValue();
            for (int i = 0; i < list.size(); i++) {
                String name = list.size() == 1 && !COMPAT_TYPES.contains(e.getKey())
                    ? e.getKey() : e.getKey() + "_" + (i + 1);
                typeNames.put(list.get(i).getPathName(), claim(name));
            }
        }

        Map<String, List<Function>> functionsByName = new HashMap<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            functionsByName.computeIfAbsent(ident(f.getName()), k -> new ArrayList<>()).add(f);
        }
        for (Map.Entry<String, List<Function>> e : new TreeMap<>(functionsByName).entrySet()) {
            for (Function f : e.getValue()) {
                String name = e.getValue().size() == 1 && !taken.contains(e.getKey())
                    ? e.getKey() : e.getKey() + "_" + f.getEntryPoint().toString(false);
                functionNames.put(f.getEntryPoint(), claim(name));
            }
        }

        Map<String, List<Data>> globalsByName = new HashMap<>();
        for (Data d : globalData()) {
            globalsByName.computeIfAbsent(ident(dataName(d)), k -> new ArrayList<>()).add(d);
        }
        for (Map.Entry<String, List<Data>> e : new TreeMap<>(globalsByName).entrySet()) {
            for (Data d : e.getValue()) {
                String name = e.getValue().size() == 1 && !taken.contains(e.getKey())
                    ? e.getKey() : e.getKey() + "_" + d.getAddress().toString(false);
                globalNames.put(d.getAddress(), claim(name));
            }
        }

        Map<String, Integer> valueCounts = new HashMap<>();
        for (DataType dt : userTypes) {
            if (dt instanceof Enum) {
                for (String n : ((Enum) dt).getNames()) {
                    valueCounts.merge(ident(n), 1, Integer::sum);
                }
            }
        }
        for (DataType dt : userTypes) {
            if (dt instanceof Enum) {
                for (String n : ((Enum) dt).getNames()) {
                    String base = ident(n);
                    String name = valueCounts.get(base) == 1 && !taken.contains(base)
                        ? base : typeNames.get(dt.getPathName()) + "_" + base;
                    name = claim(name);
                    // The decompiler prints the bare Ghidra name; only one that
                    // is unambiguous can be mapped back.
                    if (valueCounts.get(base) == 1) {
                        enumValueNames.put(n, name);
                    }
                    fieldNames.computeIfAbsent(dt.getPathName(), k -> new HashMap<>())
                        .put((int) ((Enum) dt).getValue(n), name);
                }
            }
        }
    }

    private String claim(String name) {
        String result = name;
        for (int i = 2; taken.contains(result); i++) {
            result = name + "_" + i;
        }
        taken.add(result);
        return result;
    }

    private String dataName(Data d) {
        Symbol s = d.getPrimarySymbol();
        return s != null ? s.getName() : "DAT_" + d.getAddress().toString(false);
    }

    private List<Data> globalData() {
        List<Data> result = new ArrayList<>();
        for (Data d : currentProgram.getListing().getDefinedData(true)) {
            MemoryBlock block = currentProgram.getMemory().getBlock(d.getAddress());
            if (block == null || block.isExecute() || SKIPPED_BLOCKS.contains(block.getName())
                || d.getLength() <= 0) {
                continue;
            }
            result.add(d);
        }
        return result;
    }

    // ------------------------------------------------------------------
    // Types
    // ------------------------------------------------------------------

    // Categories of the Windows archive whose types <windows.h> and
    // <mmsystem.h> declare, so they are named rather than defined. Everything
    // else that is not a builtin is defined in types.h: the project's own
    // types, and archive types no system header declares (the CRT's exception
    // handling structures in ehdata.h, for one).
    private static final Set<String> SYSTEM_CATEGORIES = new HashSet<>(Arrays.asList(
        "/WinDef.h", "/basetsd.h", "/crtdefs.h", "/excpt.h", "/mbstring.h", "/mmsystem.h",
        "/winbase.h", "/wingdi.h", "/winnls.h", "/winnt.h", "/winuser.h", "/winerror.h",
        "/windef.h", "/minwindef.h", "/minwinbase.h", "/guiddef.h", "/vadefs.h", "/stddef.h",
        "/ddraw.h", "/dinput.h", "/dsound.h", "/mmreg.h", "/objbase.h", "/unknwn.h",
        "/wtypes.h", "/wtypesbase.h", "/rpcndr.h", "/PE", "/DOS"));

    private boolean isUserType(DataType dt) {
        if (dt == null || dt instanceof BuiltInDataType || dt instanceof Pointer
            || dt instanceof Array || dt instanceof BitFieldDataType) {
            return false;
        }
        if (!(dt instanceof Composite || dt instanceof Enum || dt instanceof TypeDef
            || dt instanceof FunctionDefinition)) {
            return false;
        }
        String category = dt.getCategoryPath().getPath();
        for (String system : SYSTEM_CATEGORIES) {
            if (category.equals(system) || category.startsWith(system + "/")) {
                return false;
            }
        }
        return true;
    }

    private void collectUserTypes() {
        List<DataType> all = new ArrayList<>();
        Iterator<DataType> it = dtm.getAllDataTypes();
        while (it.hasNext()) {
            DataType dt = it.next();
            if (isUserType(dt)) {
                all.add(dt);
            }
        }
        all.sort((a, b) -> a.getPathName().compareTo(b.getPathName()));
        Set<String> done = new HashSet<>();
        Set<String> visiting = new HashSet<>();
        for (DataType dt : all) {
            userTypePaths.add(dt.getPathName());
        }
        for (DataType dt : all) {
            order(dt, done, visiting);
        }
    }

    // Depth first, so that whatever a type holds by value is defined before it.
    // Structures and enums are forward-declared up front, so what is reached
    // only through a pointer, or named in a function type, needs nothing.
    private void order(DataType dt, Set<String> done, Set<String> visiting) {
        if (!userTypePaths.contains(dt.getPathName()) || done.contains(dt.getPathName())) {
            return;
        }
        if (!visiting.add(dt.getPathName())) {
            warnings.add("types contain themselves by value: " + dt.getPathName());
            return;
        }
        if (dt instanceof Composite) {
            for (DataTypeComponent c : ((Composite) dt).getDefinedComponents()) {
                orderValue(c.getDataType(), done, visiting);
            }
        }
        else if (dt instanceof TypeDef) {
            orderValue(((TypeDef) dt).getDataType(), done, visiting);
        }
        else if (dt instanceof FunctionDefinition) {
            FunctionDefinition fd = (FunctionDefinition) dt;
            orderNamed(fd.getReturnType(), done, visiting);
            for (ParameterDefinition p : fd.getArguments()) {
                orderNamed(p.getDataType(), done, visiting);
            }
        }
        visiting.remove(dt.getPathName());
        done.add(dt.getPathName());
        userTypes.add(dt);
    }

    private void orderValue(DataType dt, Set<String> done, Set<String> visiting) {
        while (dt instanceof Array) {
            dt = ((Array) dt).getDataType();
        }
        if (dt instanceof BitFieldDataType) {
            dt = ((BitFieldDataType) dt).getBaseDataType();
        }
        if (dt instanceof Pointer) {
            orderNamed(((Pointer) dt).getDataType(), done, visiting);
            return;
        }
        order(dt, done, visiting);
    }

    // Only typedefs and function types have to come first when merely named.
    private void orderNamed(DataType dt, Set<String> done, Set<String> visiting) {
        while (dt instanceof Pointer || dt instanceof Array) {
            dt = dt instanceof Pointer ? ((Pointer) dt).getDataType() : ((Array) dt).getDataType();
        }
        if (dt instanceof TypeDef || dt instanceof FunctionDefinition) {
            order(dt, done, visiting);
        }
    }

    private String typeName(DataType dt) {
        String mine = typeNames.get(dt.getPathName());
        if (mine != null) {
            return mine;
        }
        String name = dt.getName();
        if (COMPAT_TYPES.contains(name)) {
            return name;
        }
        if (dt instanceof VoidDataType) {
            return "void";
        }
        // Something declared by <windows.h>, presumably: its archive copy or a
        // system-header type filed in the program.
        return name;
    }

    // Renders a declaration of `inner` (a name, "*", "&name", or "" for a bare
    // type) as a `dt`. `length` is what a string type holds, which the type
    // itself does not know.
    private String decl(DataType dt, String inner, int length) {
        String sep = inner.isEmpty() || inner.startsWith("[") || inner.startsWith("(") ? "" : " ";
        if (dt == null) {
            return "undefined" + sep + inner;
        }
        if (dt instanceof Pointer) {
            DataType target = ((Pointer) dt).getDataType();
            if (target == null) {
                return "void *" + inner;
            }
            return decl(target, "*" + inner, -1);
        }
        if (dt instanceof Array) {
            Array a = (Array) dt;
            String wrapped = inner.startsWith("*") || inner.startsWith("&") ? "(" + inner + ")" : inner;
            return decl(a.getDataType(), wrapped + "[" + a.getNumElements() + "]", a.getElementLength());
        }
        if (dt instanceof BitFieldDataType) {
            return decl(((BitFieldDataType) dt).getBaseDataType(), inner, length);
        }
        if (dt instanceof AbstractStringDataType) {
            String element = dt.getName().startsWith("unicode32") ? "wchar32"
                : dt.getName().startsWith("unicode") ? "wchar16" : "char";
            int size = element.equals("char") ? 1 : element.equals("wchar16") ? 2 : 4;
            int count = length > 0 ? length / size : (dt.getLength() > 0 ? dt.getLength() / size : 1);
            String wrapped = inner.startsWith("*") || inner.startsWith("&") ? "(" + inner + ")" : inner;
            if (inner.startsWith("*") && length < 0) {
                return element + " " + inner;  // a pointer to a string is a pointer to its first char
            }
            return element + (wrapped.startsWith("(") ? " " : sep) + wrapped + "[" + count + "]";
        }
        if (dt instanceof Composite || dt instanceof Enum || dt instanceof FunctionDefinition
            || dt instanceof TypeDef || COMPAT_TYPES.contains(dt.getName())
            || dt instanceof VoidDataType) {
            return typeName(dt) + sep + inner;
        }
        // Ghidra's other builtins (ImageBaseOffset32, GUID, pointer32, ...):
        // the bytes are all a decompiled function could rely on.
        if (dt.getLength() > 0 && !inner.startsWith("*")) {
            String wrapped = inner.startsWith("&") ? "(" + inner + ")" : inner;
            return "undefined1" + (wrapped.startsWith("(") ? " " : sep) + wrapped + "[" + dt.getLength() + "]";
        }
        return "void" + sep + inner;
    }

    private void writeTypes() throws IOException {
        StringBuilder out = new StringBuilder();
        out.append(header("types.h", "the data types the project has defined"));
        out.append("#ifndef GHIDRA_TYPES_H_\n#define GHIDRA_TYPES_H_\n\n#include <ghidra_compat.h>\n\n");
        // <windows.h> spells much of its API as macros (CreateWindow,
        // PlaySound, ...). A name declared here that is one of them would be
        // rewritten wherever it appears, so the macro goes.
        Set<String> names = new java.util.TreeSet<>(taken);
        names.removeIf(n -> n.matches("(FUN|DAT|PTR|LAB|s|u|switchD|caseD)_.*"));
        for (String n : names) {
            out.append("#ifdef ").append(n).append("\n#undef ").append(n).append("\n#endif\n");
        }
        out.append("\nnamespace game\n{\n\n");
        out.append("#pragma pack(push, 1)\n\n");
        for (DataType dt : userTypes) {
            if (dt instanceof Structure) {
                out.append("struct ").append(typeName(dt)).append(";\n");
            }
            else if (dt instanceof Union) {
                out.append("union ").append(typeName(dt)).append(";\n");
            }
            else if (dt instanceof Enum) {
                out.append("enum ").append(typeName(dt)).append(" : ")
                    .append(enumBase((Enum) dt)).append(";\n");
            }
        }
        out.append("\n");
        List<String> asserts = new ArrayList<>();
        for (DataType dt : userTypes) {
            String name = typeName(dt);
            if (dt instanceof Enum) {
                Enum e = (Enum) dt;
                out.append("enum ").append(name).append(" : ").append(enumBase(e)).append("\n{\n");
                for (String n : e.getNames()) {
                    out.append("    ").append(fieldNames.get(dt.getPathName()).get((int) e.getValue(n)))
                        .append(" = ").append(e.getValue(n)).append(",\n");
                }
                out.append("};\n\n");
            }
            else if (dt instanceof TypeDef) {
                out.append("typedef ").append(decl(((TypeDef) dt).getDataType(), name, -1)).append(";\n\n");
            }
            else if (dt instanceof FunctionDefinition) {
                FunctionDefinition fd = (FunctionDefinition) dt;
                List<String> params = new ArrayList<>();
                Set<String> used = new HashSet<>();
                for (ParameterDefinition p : fd.getArguments()) {
                    params.add(decl(p.getDataType(), uniqueLocal(p.getName(), used, params.size()), -1));
                }
                if (fd.hasVarArgs()) {
                    params.add("...");
                }
                out.append("typedef ").append(decl(fd.getReturnType(), name, -1)).append("(")
                    .append(params.isEmpty() ? "void" : String.join(", ", params)).append(");\n\n");
            }
            else if (dt instanceof Composite) {
                writeComposite(out, (Composite) dt, name);
                if (dt.getLength() > 0 && !dt.isZeroLength()) {
                    asserts.add("static_assert(sizeof(" + name + ") == " + dt.getLength()
                        + ", \"" + name + " does not have the size Ghidra gives it\");");
                }
            }
        }
        out.append("#pragma pack(pop)\n\n");
        for (String a : asserts) {
            out.append(a).append("\n");
        }
        out.append("\n}\n\n#endif /* !GHIDRA_TYPES_H_ */\n");
        write(GENERATED_DIR + "/types.h", out.toString());
    }

    private static String enumBase(Enum e) {
        switch (e.getLength()) {
            case 1: return "uint8_t";
            case 2: return "uint16_t";
            case 8: return "uint64_t";
            default: return "uint32_t";
        }
    }

    // Every member at its Ghidra offset under #pragma pack(1), with the bytes
    // between them spelled out, so the layout never depends on the compiler's
    // idea of alignment. A run of bit fields is kept as the bytes it occupies;
    // the field names are left in a comment.
    private void writeComposite(StringBuilder out, Composite c, String name) {
        boolean isUnion = c instanceof Union;
        out.append(isUnion ? "union " : "struct ").append(name).append("\n{\n");
        Map<Integer, String> fields = fieldNames.computeIfAbsent(c.getPathName(), k -> new HashMap<>());
        Set<String> used = new HashSet<>();
        int offset = 0;
        // All components, including the undefined bytes of a structure nobody
        // has filled in yet: the decompiler names those too (field_0x4a).
        DataTypeComponent[] components = c.getComponents();
        for (int i = 0; i < components.length; i++) {
            DataTypeComponent comp = components[i];
            if (comp.getLength() == 0 || comp.getDataType().isZeroLength()) {
                out.append("    // ").append(comp.getFieldName() == null ? "" : comp.getFieldName())
                    .append(" at 0x").append(Integer.toHexString(comp.getOffset()))
                    .append(" has no size\n");
                continue;
            }
            if (!isUnion && comp.getOffset() < offset) {
                continue;  // inside a bit field run already emitted
            }
            if (!isUnion && comp.getOffset() > offset) {
                out.append("    undefined1 _gap_0x").append(Integer.toHexString(offset)).append("[")
                    .append(comp.getOffset() - offset).append("];\n");
                offset = comp.getOffset();
            }
            if (comp.isBitFieldComponent()) {
                int end = comp.getOffset() + comp.getLength();
                List<String> names = new ArrayList<>();
                int j = i;
                for (; j < components.length && components[j].isBitFieldComponent()
                    && (isUnion ? components[j].getOffset() == comp.getOffset()
                        : components[j].getOffset() < end); j++) {
                    end = Math.max(end, components[j].getOffset() + components[j].getLength());
                    names.add(components[j].getFieldName());
                    if (isUnion) {
                        break;
                    }
                }
                String field = "_bits_0x" + Integer.toHexString(comp.getOffset());
                out.append("    undefined1 ").append(field).append("[").append(end - comp.getOffset())
                    .append("];  // bit fields: ").append(String.join(", ", names)).append("\n");
                if (!isUnion) {
                    offset = end;
                    i = j - 1;
                }
                continue;
            }
            String raw = comp.getFieldName() != null ? comp.getFieldName()
                : "field_0x" + Integer.toHexString(comp.getOffset());
            String field = uniqueLocal(raw, used, comp.getOffset());
            if (isUnion) {
                fields.putIfAbsent(comp.getOrdinal() * -1 - 1, field);
            }
            else {
                fields.put(comp.getOffset(), field);
            }
            DataType ctype = comp.getDataType();
            boolean fits = ctype.getLength() == comp.getLength() || ctype instanceof AbstractStringDataType
                || (ctype instanceof Array && ctype.getLength() == comp.getLength());
            if (fits && !(ctype instanceof VoidDataType) && !ctype.getName().equals("-BAD-")) {
                out.append("    ").append(decl(ctype, field, comp.getLength())).append(";");
            }
            else {
                // A type that was deleted, or does not have the size the slot
                // has: the bytes keep the layout.
                out.append("    undefined1 ").append(field).append("[").append(comp.getLength()).append("];");
            }
            if (comp.getComment() != null) {
                out.append("  // ").append(comp.getComment().replace("\n", " "));
            }
            out.append("\n");
            if (!isUnion) {
                offset = comp.getOffset() + comp.getLength();
            }
        }
        if (!isUnion && c.getLength() > offset && !c.isZeroLength()) {
            out.append("    undefined1 _gap_0x").append(Integer.toHexString(offset)).append("[")
                .append(c.getLength() - offset).append("];\n");
        }
        if (isUnion && components.length == 0 && c.getLength() > 0) {
            out.append("    undefined1 _bytes[").append(c.getLength()).append("];\n");
        }
        out.append("};\n\n");
    }

    private static String uniqueLocal(String raw, Set<String> used, int index) {
        String base = raw == null || raw.isEmpty() ? "param_" + (index + 1) : ident(raw);
        String name = base;
        for (int i = 2; used.contains(name); i++) {
            name = base + "_" + i;
        }
        used.add(name);
        return name;
    }

    // ------------------------------------------------------------------
    // Globals
    // ------------------------------------------------------------------

    private void writeGlobals() throws IOException {
        StringBuilder out = new StringBuilder();
        out.append(header("globals.h", "every defined data item of the image"));
        out.append("#ifndef GHIDRA_GLOBALS_H_\n#define GHIDRA_GLOBALS_H_\n\n#include \"types.h\"\n\n");
        out.append("// The image's sections are mapped at the addresses the game was linked\n"
            + "// for, so each of these refers to the very bytes translated code reads and\n"
            + "// writes at that address.\n\n");
        out.append("namespace game\n{\n\n");
        for (Data d : globalData()) {
            String name = globalNames.get(d.getAddress());
            out.append(globalDefinition("inline ", d.getDataType(), name, d.getLength(),
                d.getAddress().getOffset())).append("\n");
        }
        out.append("\n}\n\n#endif /* !GHIDRA_GLOBALS_H_ */\n");
        write(GENERATED_DIR + "/globals.h", out.toString());
    }

    private String globalDefinition(String prefix, DataType dt, String name, int length, long address) {
        return prefix + decl(dt, "&" + name, length) + " = *reinterpret_cast<"
            + decl(dt, "*", length) + ">(0x" + Long.toHexString(address) + ");";
    }

    // ------------------------------------------------------------------
    // Functions
    // ------------------------------------------------------------------

    private static class Prototype {
        String declaration;
        JsonObject json;
    }

    // A signature as the stubs need it: types, and where each piece lives.
    private static class Slot {
        String name;
        DataType type;
        VariableStorage storage;

        Slot(String name, DataType type, VariableStorage storage) {
            this.name = name;
            this.type = type;
            this.storage = storage;
        }
    }

    // What the decompiler made of a function's signature. A decompiled function
    // is printed with the prototype the decompiler settled on, which fills in
    // what Ghidra leaves undefined (most often the return type), so for those the
    // declaration and the stubs have to follow the decompiler, not the database.
    private Map<Address, HighFunction> decompiled = new HashMap<>();

    private Prototype prototype(Function f) {
        HighFunction high = decompiled.get(f.getEntryPoint());
        List<Slot> params = new ArrayList<>();
        Slot ret;
        if (high != null) {
            FunctionPrototype proto = high.getFunctionPrototype();
            ret = new Slot("return", proto.getReturnType(), proto.getReturnStorage());
            for (int i = 0; i < proto.getNumParams(); i++) {
                HighSymbol param = proto.getParam(i);
                params.add(new Slot(param.getName(), param.getDataType(), param.getStorage()));
            }
        }
        else {
            ret = new Slot("return", f.getReturn().getDataType(), f.getReturn().getVariableStorage());
            for (Parameter param : f.getParameters()) {
                params.add(new Slot(param.getName(), param.getDataType(), param.getVariableStorage()));
            }
        }
        return prototype(f, ret, params, high != null);
    }

    private Prototype prototype(Function f, Slot ret, List<Slot> parameters, boolean fromDecompiler) {
        Prototype p = new Prototype();
        JsonObject json = new JsonObject();
        JsonArray problems = new JsonArray();
        String name = functionNames.get(f.getEntryPoint());
        json.addProperty("entry", f.getEntryPoint().getOffset());
        json.addProperty("name", name);
        json.addProperty("cc", f.getCallingConventionName());
        json.addProperty("varargs", f.hasVarArgs());
        json.addProperty("decompiled", fromDecompiler);
        int purge = f.getStackPurgeSize();
        if (purge == Function.UNKNOWN_STACK_DEPTH_CHANGE || purge == Function.INVALID_STACK_DEPTH_CHANGE) {
            json.add("purge", JsonNull.INSTANCE);
        }
        else {
            json.addProperty("purge", purge);
        }
        if (!fromDecompiler && f.getSignatureSource() == SourceType.DEFAULT) {
            problems.add("the signature is Ghidra's default guess; commit one");
        }

        DataType returnType = ret.type;
        JsonObject r = new JsonObject();
        boolean isVoid = returnType == null || returnType instanceof VoidDataType;
        if (!isVoid && returnType == DataType.DEFAULT) {
            // Ghidra does not know what, if anything, comes back. Handing the
            // caller all of eax costs nothing and is right whenever it is used.
            returnType = Undefined4DataType.dataType;
            r.addProperty("type", "undefined4");
            r.addProperty("size", 4);
            JsonArray eax = new JsonArray();
            JsonObject piece = new JsonObject();
            piece.addProperty("reg", "eax");
            piece.addProperty("shift", 0);
            piece.addProperty("size", 4);
            eax.add(piece);
            r.add("storage", eax);
        }
        else {
            r.addProperty("type", decl(returnType, "", -1));
            r.addProperty("size", isVoid ? 0 : returnType.getLength());
            r.add("storage", isVoid ? new JsonArray() : storage(ret.storage, problems, "return"));
            if (!isVoid && ret.storage != null && ret.storage.isForcedIndirect()) {
                problems.add("returns through a hidden pointer");
            }
        }
        json.add("ret", r);

        JsonArray params = new JsonArray();
        List<String> paramDecls = new ArrayList<>();
        Set<String> used = new HashSet<>();
        for (Slot param : parameters) {
            JsonObject pj = new JsonObject();
            String pname = uniqueLocal(param.name, used, paramDecls.size());
            pj.addProperty("name", pname);
            pj.addProperty("type", decl(param.type, "", -1));
            pj.addProperty("size", param.type.getLength());
            pj.add("storage", storage(param.storage, problems, pname));
            if (param.storage != null && param.storage.isForcedIndirect()) {
                problems.add(pname + " is passed through a hidden pointer");
            }
            params.add(pj);
            paramDecls.add(decl(param.type, pname, -1));
        }
        if (f.hasVarArgs()) {
            // The stubs pass a fixed number of dwords for "...", which is what
            // the stack holds for any cdecl variadic call on 32-bit x86.
            paramDecls.add("...");
            if (parameters.isEmpty()) {
                problems.add("takes only variable arguments, which C++ cannot reach");
            }
        }
        json.add("params", params);
        json.add("problems", problems);
        p.declaration = decl(isVoid ? VoidDataType.dataType : returnType, name, -1) + "("
            + (paramDecls.isEmpty() ? "void" : String.join(", ", paramDecls)) + ")";
        json.addProperty("declaration", p.declaration);
        p.json = json;
        return p;
    }

    private JsonArray storage(VariableStorage storage, JsonArray problems, String what) {
        JsonArray result = new JsonArray();
        if (storage == null || storage.isUnassignedStorage() || storage.isBadStorage()) {
            problems.add(what + " has no storage");
            return result;
        }
        for (Varnode v : storage.getVarnodes()) {
            JsonObject piece = new JsonObject();
            piece.addProperty("size", v.getSize());
            if (v.isRegister()) {
                Register reg = currentProgram.getRegister(v);
                if (reg == null) {
                    problems.add(what + " is in an unknown register");
                    continue;
                }
                Register base = reg.getBaseRegister();
                if (base.getBitLength() > 32 && !base.getName().startsWith("ST")) {
                    base = reg;
                    while (base.getParentRegister() != null && base.getParentRegister().getBitLength() <= 32) {
                        base = base.getParentRegister();
                    }
                }
                piece.addProperty("reg", base.getName().toLowerCase());
                piece.addProperty("shift", (int) (reg.getOffset() - base.getOffset()));
            }
            else if (v.getAddress().isStackAddress()) {
                piece.addProperty("stack", v.getOffset());
            }
            else {
                problems.add(what + " is in " + v);
            }
            result.add(piece);
        }
        return result;
    }

    private void writeFunctions() throws IOException {
        StringBuilder out = new StringBuilder();
        out.append(header("functions.h", "a C++ prototype for every function of the image"));
        out.append("#ifndef GHIDRA_FUNCTIONS_H_\n#define GHIDRA_FUNCTIONS_H_\n\n#include \"types.h\"\n\n");
        out.append("// Each is defined either by a decompiled function in src/game/decomp, or by\n"
            + "// a stub that runs the translated routine (game.cstubs.cpp). The calling\n"
            + "// convention is not part of it: only the stubs need to know where the\n"
            + "// original code kept the arguments, and that is in prototypes.json.\n\n");
        out.append("namespace game\n{\n\n");
        JsonArray all = new JsonArray();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            Prototype p = prototype(f);
            all.add(p.json);
            out.append(p.declaration).append(";  // 0x")
                .append(f.getEntryPoint().toString(false)).append("\n");
        }
        out.append("\n}\n\n#endif /* !GHIDRA_FUNCTIONS_H_ */\n");
        write(GENERATED_DIR + "/functions.h", out.toString());

        JsonObject doc = new JsonObject();
        doc.addProperty("program", currentProgram.getName());
        doc.addProperty("md5", currentProgram.getExecutableMD5());
        doc.add("functions", all);
        write(GENERATED_DIR + "/prototypes.json", gson().toJson(doc) + "\n");
    }

    // ------------------------------------------------------------------
    // Decompiled functions
    // ------------------------------------------------------------------

    private static final Pattern LABEL = Pattern.compile("LAB_[0-9a-fA-F]{8}");

    // The last part with any text, dropping the empty spacer tokens the
    // decompiler puts between the real ones.
    private static String last(List<String> parts) {
        while (!parts.isEmpty() && parts.get(parts.size() - 1).isEmpty()) {
            parts.remove(parts.size() - 1);
        }
        return parts.isEmpty() ? "" : parts.get(parts.size() - 1);
    }

    private static boolean followedByCall(List<ClangToken> tokens, int index) {
        for (int i = index + 1; i < tokens.size(); i++) {
            String t = tokens.get(i).getText();
            if (!t.trim().isEmpty()) {
                return t.equals("(");
            }
        }
        return false;
    }

    private static final Pattern ADDRESS_SUFFIX = Pattern.compile("_([0-9a-fA-F]{8})$");

    private void exportFunction(Function f, DecompileResults results, JsonObject registry)
            throws Exception {

        Map<String, String> locals = new LinkedHashMap<>();  // untyped globals the body touches
        List<ClangLine> lines = DecompilerUtils.toLines(results.getCCodeMarkup());
        // Where the "..." of a variadic function starts on the stack, which is
        // where the decompiler's &stack0x... for the va_list points.
        int vaOffset = -1;
        String lastNamed = null;
        boolean usesVaList = false;
        if (f.hasVarArgs()) {
            vaOffset = 4;
            for (HighSymbol param : paramSymbols(results.getHighFunction())) {
                lastNamed = param.getName();
                for (Varnode v : param.getStorage().getVarnodes()) {
                    if (v.getAddress().isStackAddress()) {
                        vaOffset = Math.max(vaOffset, (int) v.getOffset() + ((v.getSize() + 3) & ~3));
                    }
                }
            }
        }
        List<String> rendered = new ArrayList<>();
        for (ClangLine line : lines) {
            List<String> parts = new ArrayList<>();
            List<ClangToken> tokens = line.getAllTokens();
            for (int i = 0; i < tokens.size(); i++) {
                ClangToken token = tokens.get(i);
                String t = token.getText();
                if (CALLING_CONVENTIONS.contains(t)) {
                    if (i + 1 < tokens.size() && tokens.get(i + 1).getText().trim().isEmpty()) {
                        i++;
                    }
                    continue;
                }
                boolean isFunction = token instanceof ClangFuncNameToken;
                if (isFunction || LABEL.matcher(t).matches()) {
                    // Ghidra prints a method with its class (Entity::SetPosition);
                    // the C++ function is a plain one.
                    while (isFunction && last(parts).equals("::")) {
                        parts.remove(parts.size() - 1);
                        if (!last(parts).isEmpty()) {
                            parts.remove(parts.size() - 1);
                        }
                    }
                    if (!followedByCall(tokens, i)) {
                        // Code used as a value -- a callback stored for translated
                        // code to call through dynamic_call -- has to be the
                        // routine's address in the game, not a C++ function's.
                        Address address = null;
                        if (isFunction) {
                            Function target = callee((ClangFuncNameToken) token, f);
                            address = target == null || target.isExternal() ? null : target.getEntryPoint();
                        }
                        else {
                            address = toAddr(t.substring(4));
                        }
                        if (address != null) {
                            if (last(parts).equals("&")) {
                                parts.remove(parts.size() - 1);
                            }
                            parts.add("ghidra::code_address(0x" + address.toString(false) + ")");
                            continue;
                        }
                    }
                }
                if (vaOffset >= 0 && t.equals(String.format("stack0x%08x", vaOffset))) {
                    // The address of the first variable argument: what va_start
                    // gives. The decompiler takes it with & and casts it.
                    if (last(parts).equals("&")) {
                        parts.remove(parts.size() - 1);
                    }
                    parts.add("variadic");
                    usesVaList = true;
                    continue;
                }
                parts.add(render(token, f, locals));
            }
            rendered.add(line.getIndentString() + String.join("", parts));
        }

        List<List<Instruction>> assembly = withAssembly ? assignInstructions(f, lines) : null;
        StringBuilder body = new StringBuilder();
        for (int i = 0; i < rendered.size(); i++) {
            if (assembly != null) {
                String indent = lines.get(i).getIndentString();
                for (Instruction instruction : assembly.get(i)) {
                    body.append(indent).append("// ").append(listing(instruction)).append("\n");
                }
            }
            body.append(rendered.get(i)).append("\n");
        }

        if (usesVaList && lastNamed != null) {
            String name = RESERVED.contains(lastNamed) ? lastNamed + "_" : lastNamed;
            locals.put(" va", "va_list variadic;\n  va_start(variadic, " + name + ");");
        }

        // Globals Ghidra has no data item for have no definition in globals.h.
        // They are declared right inside the function instead, with the type the
        // decompiler gave them, so that typing the item in Ghidra later (which
        // puts it in globals.h) does not clash with them.
        String code = body.toString();
        if (!locals.isEmpty()) {
            StringBuilder decls = new StringBuilder();
            String va = locals.remove(" va");
            if (va != null) {
                decls.append("  ").append(va).append("\n\n");
            }
            if (!locals.isEmpty()) {
                decls.append("  // Untyped in Ghidra, so not in globals.h; typed as the decompiler saw them.\n");
                for (String d : locals.values()) {
                    decls.append("  ").append(d).append("\n");
                }
                decls.append("\n");
            }
            int brace = code.indexOf("\n{\n");
            if (brace >= 0) {
                code = code.substring(0, brace + 3) + decls + code.substring(brace + 3);
            }
        }

        String entry = String.format("0x%08x", f.getEntryPoint().getOffset());
        String name = functionNames.get(f.getEntryPoint());
        JsonObject functions = registry.getAsJsonObject("functions");
        String path = functions.has(entry)
            ? functions.getAsJsonObject(entry).get("file").getAsString()
            : OWNED_DIR + "/" + (name.endsWith(f.getEntryPoint().toString(false)) ? name
                : name + "_" + f.getEntryPoint().toString(false)) + ".cpp";

        StringBuilder out = new StringBuilder();
        out.append("// ").append(f.getName()).append(" at ").append(entry).append(", decompiled by Ghidra.\n");
        out.append("//\n// This file belongs to the project now: edit it freely. Until you do, every\n"
            + "// export rewrites it, so it follows what changes in Ghidra; once edited, an\n"
            + "// export only renames in it what was renamed in Ghidra. Its signature still\n"
            + "// belongs to Ghidra (functions.h, and the stub translated code calls it\n"
            + "// through), so change that in Ghidra.\n\n");
        out.append("#include <decomp.h>\n\nnamespace game\n{\n\n");
        out.append(code.trim()).append("\n\n}\n");

        // The file is the project's once written, so it is only replaced while
        // it is still exactly what the last export wrote (the registry keeps a
        // hash of that). That keeps the loop of fixing types and names in
        // Ghidra and exporting again friction-free, without ever losing an edit
        // made to the file: those get asked about in the GUI, and headless the
        // fresh decompilation goes beside the file unless --force is given.
        String content = out.toString();
        File target = new File(root, path);
        JsonObject previous = functions.has(entry) ? functions.getAsJsonObject(entry) : null;
        String lastHash = previous != null && previous.has("hash") ? previous.get("hash").getAsString() : null;
        String written = path;
        if (target.exists() && !force) {
            String current = sha256(Files.readString(target.toPath(), StandardCharsets.UTF_8));
            if (!current.equals(lastHash) && !current.equals(sha256(content))) {
                String why = lastHash == null
                    ? path + " was not written by this version of the export, so edits to it cannot be told apart"
                    : path + " has been edited since it was exported";
                boolean overwrite = !isRunningHeadless()
                    && askYesNo("Overwrite " + target.getName() + "?", why + ".\n\nOverwrite it with the fresh "
                        + "decompilation? (No writes it to " + target.getName() + ".ghidra instead.)");
                if (!overwrite) {
                    written = path + ".ghidra";
                    warnings.add(why + "; wrote " + written + " instead (--force overwrites)");
                }
            }
        }
        write(written, content);

        JsonObject item = new JsonObject();
        item.addProperty("name", name);
        item.addProperty("file", path);
        if (written.equals(path)) {
            item.addProperty("hash", sha256(content));
            // A side file left by an earlier refusal is stale now.
            new File(root, path + ".ghidra").delete();
        }
        else if (lastHash != null) {
            item.addProperty("hash", lastHash);
        }
        functions.add(entry, item);
        println("exported " + f.getName() + " -> " + written);
    }

    // Which C line each machine instruction of the function belongs to, so the
    // instructions can be shown above the code they turned into. The decompiler
    // ties every token to the instruction it came from; an instruction the
    // output kept nothing of (a push, a stack adjustment) goes with the next
    // one. Every instruction is listed exactly once, under the first line
    // that uses it.
    private List<List<Instruction>> assignInstructions(Function f, List<ClangLine> lines) {
        List<List<Instruction>> result = new ArrayList<>();
        for (int i = 0; i < lines.size(); i++) {
            result.add(new ArrayList<>());
        }
        // Nothing goes above the opening brace: the signature's tokens point at
        // the entry, but the instructions there belong to the body.
        int bodyStart = 0;
        for (int i = 0; i < lines.size(); i++) {
            if (lines.get(i).toString().trim().endsWith("{")) {
                bodyStart = i + 1;
                break;
            }
        }
        // Tokens for values, operators and calls name their instruction
        // precisely; keywords and braces (an `if` stands for its conditional
        // jump, a `}` for the jump closing a loop) only claim what is left.
        Map<Address, Integer> owner = new HashMap<>();
        for (int pass = 0; pass < 2; pass++) {
            for (int i = bodyStart; i < lines.size(); i++) {
                for (ClangToken token : lines.get(i).getAllTokens()) {
                    boolean precise = !(token instanceof ClangSyntaxToken);
                    if (precise != (pass == 0)) {
                        continue;
                    }
                    for (Address address : new Address[] { token.getMinAddress(), token.getMaxAddress() }) {
                        if (address == null) {
                            continue;
                        }
                        Instruction instruction = getInstructionContaining(address);
                        if (instruction != null && f.getBody().contains(instruction.getAddress())) {
                            owner.putIfAbsent(instruction.getAddress(), i);
                        }
                    }
                }
            }
        }
        // An instruction no line kept anything of mostly sets up what comes
        // next (pushing a call's arguments), so it goes with the next one that
        // has a line; what trails the last of them goes with that.
        List<Instruction> pending = new ArrayList<>();
        int previous = Math.min(bodyStart, lines.size() - 1);
        for (Instruction instruction : currentProgram.getListing().getInstructions(f.getBody(), true)) {
            Integer line = owner.get(instruction.getAddress());
            if (line == null) {
                pending.add(instruction);
                continue;
            }
            result.get(line).addAll(pending);
            pending.clear();
            result.get(line).add(instruction);
            previous = line;
        }
        result.get(previous).addAll(pending);
        for (List<Instruction> list : result) {
            list.sort((a, b) -> a.getAddress().compareTo(b.getAddress()));
        }
        return result;
    }

    // The same columns as the translated code's comments: address, bytes,
    // then the instruction as Ghidra shows it.
    private static String listing(Instruction instruction) {
        StringBuilder bytes = new StringBuilder();
        try {
            for (byte b : instruction.getBytes()) {
                bytes.append(String.format("%02x", b & 0xff));
            }
        }
        catch (ghidra.program.model.mem.MemoryAccessException e) {
            bytes.append("??");
        }
        return String.format("%s  %-22s %s", instruction.getAddress().toString(false), bytes,
            instruction.toString());
    }

    private static List<HighSymbol> paramSymbols(HighFunction high) {
        List<HighSymbol> result = new ArrayList<>();
        FunctionPrototype proto = high.getFunctionPrototype();
        for (int i = 0; i < proto.getNumParams(); i++) {
            result.add(proto.getParam(i));
        }
        return result;
    }

    private String render(ClangToken token, Function current, Map<String, String> locals) {
        String text = token.getText();
        if (token instanceof ClangFuncNameToken) {
            return functionReference((ClangFuncNameToken) token, current, text);
        }
        if (token instanceof ClangTypeToken) {
            DataType dt = ((ClangTypeToken) token).getDataType();
            if (dt != null && typeNames.containsKey(dt.getPathName())) {
                return typeNames.get(dt.getPathName());
            }
            return text;
        }
        if (token instanceof ClangFieldToken) {
            ClangFieldToken field = (ClangFieldToken) token;
            DataType dt = field.getDataType();
            while (dt instanceof TypeDef) {
                dt = ((TypeDef) dt).getBaseDataType();
            }
            if (dt != null && fieldNames.containsKey(dt.getPathName())) {
                String mapped = fieldNames.get(dt.getPathName()).get(field.getOffset());
                if (mapped != null) {
                    return mapped;
                }
            }
            return ident(text);
        }
        if (token instanceof ClangVariableToken) {
            HighVariable high = token.getHighVariable();
            HighSymbol symbol = high == null ? null : high.getSymbol();
            Address address = null;
            DataType type = high == null ? null : high.getDataType();
            if (symbol != null && symbol.isGlobal() && symbol.getStorage() != null
                && symbol.getStorage().getMinAddress() != null
                && symbol.getStorage().getMinAddress().isMemoryAddress()) {
                address = symbol.getStorage().getMinAddress();
                // The type the decompiler inferred from the use, unless the
                // symbol has a real one.
                DataType declared = symbol.getDataType();
                if (declared != null && declared != DataType.DEFAULT
                    && !(declared instanceof ghidra.program.model.data.Undefined)) {
                    type = declared;
                }
            }
            else if (symbol == null) {
                Matcher m = ADDRESS_SUFFIX.matcher(text);
                if (m.find() && (text.startsWith("DAT_") || text.startsWith("PTR_")
                    || text.startsWith("s_") || text.startsWith("u_"))) {
                    address = toAddr(m.group(1));
                }
            }
            if (address != null) {
                String global = globalNames.get(address);
                if (global != null) {
                    return global;
                }
                String local = ident(text);
                if (!locals.containsKey(local)) {
                    locals.put(local, globalDefinition("", type, local,
                        type == null ? 1 : type.getLength(), address.getOffset()));
                }
                return local;
            }
            if (enumValueNames.containsKey(text)) {
                return enumValueNames.get(text);
            }
            if (symbol != null && !symbol.isGlobal() && RESERVED.contains(text)) {
                return text + "_";
            }
            return text;
        }
        return text;
    }

    private Function callee(ClangFuncNameToken token, Function current) {
        String text = token.getText();
        Function callee = null;
        PcodeOp op = token.getPcodeOp();
        if (op == null && text.equals(current.getName())) {
            callee = current;
        }
        else if (op != null && (op.getOpcode() == PcodeOp.CALL || op.getOpcode() == PcodeOp.CALLIND)
            && op.getInput(0) != null && op.getInput(0).isAddress()) {
            callee = getFunctionAt(op.getInput(0).getAddress());
        }
        if (callee == null) {
            // A call through the import table is indirect; the decompiler names
            // the import, so find it by that name.
            if (externals == null) {
                externals = new HashMap<>();
                for (Function ext : currentProgram.getFunctionManager().getExternalFunctions()) {
                    externals.putIfAbsent(ext.getName(), ext);
                }
            }
            callee = externals.get(text);
        }
        if (callee == null) {
            List<Function> named = getGlobalFunctions(text);
            if (named != null && named.size() == 1) {
                callee = named.get(0);
            }
        }
        if (callee == null) {
            Matcher m = ADDRESS_SUFFIX.matcher(text);
            if (m.find()) {
                callee = getFunctionAt(toAddr(m.group(1)));
            }
        }
        return callee;
    }

    private String functionReference(ClangFuncNameToken token, Function current, String text) {
        Function callee = callee(token, current);
        if (callee == null) {
            return text;
        }
        if (callee.isThunk()) {
            Function thunked = callee.getThunkedFunction(true);
            if (thunked != null) {
                callee = thunked;
            }
        }
        if (callee.isExternal()) {
            ExternalLocation location = callee.getExternalLocation();
            String library = location == null || location.getLibraryName() == null ? ""
                : location.getLibraryName().toLowerCase().replaceAll("\\.dll$", "");
            String label = location == null ? callee.getName() : location.getLabel();
            if (new File(root, "include/winapi/" + library + ".h").exists()) {
                // The same declarations the translated code's imports go through,
                // which replace the few the game cannot call directly
                // (CreateThread, for one).
                return "win32::" + library + "::" + label;
            }
            return "::" + label;
        }
        String mine = functionNames.get(callee.getEntryPoint());
        return mine != null ? mine : text;
    }

    // ------------------------------------------------------------------
    // Files
    // ------------------------------------------------------------------

    // ------------------------------------------------------------------
    // Renames
    // ------------------------------------------------------------------

    private static final String NAMES = GENERATED_DIR + "/names.json";

    // The C++ name of everything that has an identity Ghidra keeps across a
    // rename: functions and globals by address, types by their universal ID.
    private JsonObject currentNames() {
        JsonObject names = new JsonObject();
        for (Map.Entry<Address, String> e : functionNames.entrySet()) {
            names.addProperty("f" + e.getKey().toString(false), e.getValue());
        }
        for (Map.Entry<Address, String> e : globalNames.entrySet()) {
            names.addProperty("g" + e.getKey().toString(false), e.getValue());
        }
        for (DataType dt : userTypes) {
            if (dt.getUniversalID() != null) {
                names.addProperty("t" + dt.getUniversalID().getValue(), typeNames.get(dt.getPathName()));
            }
        }
        return names;
    }

    // Old name -> new name, for everything renamed since the last run.
    private Map<String, String> renames() throws IOException {
        Map<String, String> result = new HashMap<>();
        File file = new File(root, NAMES);
        if (!file.exists()) {
            return result;
        }
        JsonObject previous;
        try (FileReader reader = new FileReader(file, StandardCharsets.UTF_8)) {
            previous = JsonParser.parseReader(reader).getAsJsonObject();
        }
        JsonObject current = currentNames();
        for (Map.Entry<String, JsonElement> e : previous.entrySet()) {
            if (current.has(e.getKey())) {
                String before = e.getValue().getAsString();
                String after = current.get(e.getKey()).getAsString();
                if (!before.equals(after)) {
                    result.put(before, after);
                }
            }
        }
        return result;
    }

    private void writeNames() throws IOException {
        write(NAMES, gson().toJson(currentNames()) + "\n");
    }

    // Renames whole identifiers only, all at once, so that two names trading
    // places come out right.
    private static String applyRenames(String content, Map<String, String> renames) {
        if (renames.isEmpty()) {
            return content;
        }
        List<String> names = new ArrayList<>(renames.keySet());
        names.sort((a, b) -> b.length() - a.length());
        StringBuilder alternation = new StringBuilder();
        for (String name : names) {
            alternation.append(alternation.length() == 0 ? "" : "|").append(Pattern.quote(name));
        }
        Matcher m = Pattern.compile("(?<![A-Za-z0-9_])(" + alternation + ")(?![A-Za-z0-9_])").matcher(content);
        StringBuilder out = new StringBuilder();
        while (m.find()) {
            m.appendReplacement(out, Matcher.quoteReplacement(renames.get(m.group(1))));
        }
        m.appendTail(out);
        return out.toString();
    }

    private static String sha256(String text) {
        try {
            byte[] digest = java.security.MessageDigest.getInstance("SHA-256")
                .digest(text.getBytes(StandardCharsets.UTF_8));
            StringBuilder hex = new StringBuilder();
            for (byte b : digest) {
                hex.append(String.format("%02x", b & 0xff));
            }
            return hex.toString();
        }
        catch (java.security.NoSuchAlgorithmException e) {
            throw new IllegalStateException(e);
        }
    }

    private JsonObject readRegistry() throws IOException {
        File file = new File(root, REGISTRY);
        JsonObject registry = new JsonObject();
        if (file.exists()) {
            try (FileReader reader = new FileReader(file, StandardCharsets.UTF_8)) {
                JsonElement parsed = JsonParser.parseReader(reader);
                if (parsed.isJsonObject()) {
                    registry = parsed.getAsJsonObject();
                }
            }
        }
        if (!registry.has("functions")) {
            registry.add("functions", new JsonObject());
        }
        return registry;
    }

    private void writeRegistry(JsonObject registry) throws IOException {
        // Sorted by address, so the file diffs well.
        JsonObject functions = registry.getAsJsonObject("functions");
        TreeMap<String, JsonElement> sorted = new TreeMap<>();
        for (Map.Entry<String, JsonElement> e : functions.entrySet()) {
            sorted.put(e.getKey(), e.getValue());
        }
        JsonObject ordered = new JsonObject();
        for (Map.Entry<String, JsonElement> e : sorted.entrySet()) {
            ordered.add(e.getKey(), e.getValue());
        }
        registry.add("functions", ordered);
        write(REGISTRY, gson().toJson(registry) + "\n");
    }

    private static Gson gson() {
        return new GsonBuilder().setPrettyPrinting().disableHtmlEscaping().create();
    }

    private String header(String file, String what) {
        return "// " + file + ": " + what + ", as Ghidra knows it.\n"
            + "// Generated by ghidra_scripts/ExportDecompiled.java from "
            + currentProgram.getDomainFile().getPathname() + " -- do not edit;\n"
            + "// change it in Ghidra and export again.\n\n";
    }

    private void write(String path, String content) throws IOException {
        File file = new File(root, path);
        file.getParentFile().mkdirs();
        Files.writeString(file.toPath(), content, StandardCharsets.UTF_8);
    }
}
