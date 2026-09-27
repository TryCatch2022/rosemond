import sys
sys.path.append('disasm')
from disasm import disassembler, dll


DATA_SEGMENTS = [(0x40E21E, 0x40E2A0), (0x456636, 0x456650), (0x465026, 0x465040), (0x46ff00, 0x471230)]


MERGE_ROUTINES = [(0x47CD30, 0x47CD8C)]

KNOWN_SUBROUTINES = []

SKIP_INSTRUCTIONS = []


SPLIT_INSTRUCTIONS = []


THREAD_ROUTINES = []
THREAD_SEGMENTS = []

if __name__ == '__main__':
    application = disassembler.disassemble('game', 'afrh/game.exe', DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, SPLIT_INSTRUCTIONS,
                                           THREAD_ROUTINES, THREAD_SEGMENTS, MERGE_ROUTINES)
    application.write(THREAD_SEGMENTS, skip_instructions=SKIP_INSTRUCTIONS, dlls=[])
