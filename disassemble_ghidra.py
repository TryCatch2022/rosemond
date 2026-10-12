"""Disassemble using Ghidra's analysis for function boundaries.

    python disassemble_ghidra.py            # game.exe
    python disassemble_ghidra.py menu       # or black, or several at once

Each target has its own Ghidra project for the analysis, next to the original
executable and the map exported from it (see TARGETS). Prepare the map first
(with the Ghidra GUI closed, so the project is unlocked):

    GHIDRA=/opt/ghidra_12.1.4_PUBLIC/bin/support/analyzeHeadless

    # once, to turn every referenced-but-orphaned code run into a function
    $GHIDRA afrh afrh -process game.exe -noanalysis \
        -scriptPath ghidra_scripts -postScript RecoverMissingFunctions.java

    # then, whenever the analysis changes
    $GHIDRA afrh afrh -process game.exe -noanalysis -readOnly \
        -scriptPath ghidra_scripts \
        -postScript ExportFunctionMap.java afrh/functions.json

and the same with `menu menu -process menu.exe ... menu/functions.json`, or
`black black -process black.exe ... black/functions.json`.

Both scripts also run from the GUI's Script Manager under the Rosemond
category, which is easier while iterating on the analysis.
"""

import glob
import os
import re
import sys
sys.path.append('disasm')
from disasm import ghidra


# target: (original executable, function map exported from its Ghidra project)
# The target's name is also the generated code's: src/<name>, namespace <name>,
# <name>.exe and <name>_code.dll.
TARGETS = {
    'game': ('afrh/game.exe', 'afrh/functions.json'),
    'black': ('black/black.exe', 'black/functions.json'),
    'menu': ('menu/menu.exe', 'menu/functions.json'),
}

THREAD_ROUTINES = []
THREAD_SEGMENTS = []
SKIP_INSTRUCTIONS = []

# DATA_SEGMENTS, KNOWN_SUBROUTINES, MERGE_ROUTINES and SPLIT_INSTRUCTIONS are
# all derived from the map now, so there is nothing to maintain by hand here.

def clear_generated(application_name):
    """Drop the numbered method files from a previous run.

    write() emits one file per 100 subroutines and never removes the ones a
    shorter run leaves behind, so switching pipelines otherwise leaves stale
    definitions in the build and the link fails on duplicate symbols.
    """
    pattern = re.compile(r'%s\.\d+\.cpp$' % re.escape(application_name))
    directory = 'src/%s/disassembly' % application_name
    for path in glob.glob('%s/%s.*.cpp' % (directory, application_name)):
        if pattern.search(os.path.basename(path)):
            os.remove(path)


def disassemble(name):
    exe_path, map_path = TARGETS[name]
    clear_generated(name)
    function_map = ghidra.FunctionMap(map_path)
    application = ghidra.disassemble(name, exe_path, function_map,
                                     thread_routines=THREAD_ROUTINES)
    # Routines are named after their address, not after Ghidra's names, so that
    # renaming a function in Ghidra changes nothing here. The names, and which
    # routines are decompiled, only matter to the entry points and stubs the
    # build generates (disasm/cstubs.py).
    application.write(THREAD_SEGMENTS,
                      skip_instructions=SKIP_INSTRUCTIONS,
                      dlls=[],
                      function_names={})


if __name__ == '__main__':
    names = sys.argv[1:] or ['game']
    for name in names:
        if name not in TARGETS:
            sys.exit('unknown target %s; one of %s' % (name, ', '.join(sorted(TARGETS))))
    for name in names:
        disassemble(name)
