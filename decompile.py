"""Move functions from translated assembly to decompiled C++.

    python decompile.py 0x407690 0x4098a0   # decompile these, refresh the rest
    python decompile.py                     # only refresh the generated headers

Each decompiled function is written with the instructions it came from in
comments above each line, to check the C against; --no-asm leaves them out.

Runs ghidra_scripts/ExportDecompiled.java headless against the Ghidra project
(read-only: nothing is saved to it), then the disassembler, which replaces the
decompiled routines with stubs into the C++ functions. What is written where:

    src/game/decomp/<name>_<address>.cpp   the decompiled function; yours to edit
    src/game/decomp/registry.json          which functions are decompiled
    src/game/ghidra/*                      types, globals, prototypes; Ghidra's
    src/game/disassembly/game.cstubs.cpp   the stubs between the two worlds

A decompiled file is only overwritten while it has no uncommitted changes;
otherwise the fresh decompilation goes to <file>.ghidra beside it. To give a
function back to the translator, delete its file and its registry entry.

Headless Ghidra cannot open a project the GUI has open, so close it first --
or run the same script from the GUI (Script Manager, category Rosemond, on the
function under the cursor) and then just `python disassemble_ghidra.py`.
"""

import argparse
import os
import subprocess
import sys


GHIDRA_HOME = os.environ.get('GHIDRA_HOME', '/opt/ghidra_12.1.4_PUBLIC')
PROJECT = 'ghidra project/RosemondHill'
PROGRAM = 'game.exe'


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    parser.add_argument('addresses', nargs='*', help='entry points to decompile (0x...)')
    parser.add_argument('--no-asm', action='store_true',
                        help='leave the machine code out of the decompiled files')
    parser.add_argument('--project', default=PROJECT,
                        help='Ghidra project, as <directory>/<name> (default: %(default)s)')
    parser.add_argument('--ghidra', default=GHIDRA_HOME,
                        help='Ghidra installation (default: $GHIDRA_HOME or %(default)s)')
    args = parser.parse_args()

    root = os.path.dirname(os.path.abspath(__file__))
    project_dir, project_name = os.path.split(os.path.join(root, args.project))
    # The .gpr is only a marker Ghidra looks for next to the .rep directory;
    # a project checked in without one opens fine once it exists.
    marker = os.path.join(project_dir, project_name + '.gpr')
    if not os.path.exists(marker) and os.path.isdir(os.path.join(project_dir, project_name + '.rep')):
        open(marker, 'w').close()

    headless = os.path.join(args.ghidra, 'bin', 'support', 'analyzeHeadless')
    if not os.path.exists(headless):
        headless = os.path.join(args.ghidra, 'support', 'analyzeHeadless')
    command = [headless, project_dir, project_name,
               '-process', PROGRAM, '-noanalysis', '-readOnly',
               '-scriptPath', os.path.join(root, 'ghidra_scripts'),
               '-postScript', 'ExportDecompiled.java'] + args.addresses + (
                   ['--no-asm'] if args.no_asm else [])
    result = subprocess.run(command, cwd=root, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, universal_newlines=True)
    failed = result.returncode != 0
    for line in result.stdout.splitlines():
        if 'ExportDecompiled.java>' in line:
            print(line.split('ExportDecompiled.java>', 1)[1].replace('(GhidraScript)', '').strip())
        elif 'ERROR' in line or 'Exception' in line:
            failed = True
            print(line)
    if 'NotOwnerException' in result.stdout:
        print('\nThe project belongs to another user. Either change OWNER in\n'
              '  %s\nto your user name, or run with\n'
              '  GHIDRA_HEADLESS_JAVA_OPTIONS=-Duser.name=<its owner>'
              % os.path.join(project_dir, project_name + '.rep', 'project.prp'))
    if failed:
        sys.exit(1)

    sys.exit(subprocess.call([sys.executable, 'disassemble_ghidra.py'], cwd=root))


if __name__ == '__main__':
    main()
