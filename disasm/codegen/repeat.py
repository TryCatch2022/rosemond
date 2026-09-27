from . import arguments
from capstone import x86


def cg_cld(instruction, function_bounds, function_names):
    return ['cpu.flags.df = 0;']

def cg_std(instruction, function_bounds, function_names):
    return ['cpu.flags.df = 1;']

def cg_rep(instruction, code):
    return ['while (cpu.ecx)', '{'] + ['    %s'%c for c in code] + [
                '    --cpu.ecx;',
                '}'
           ]


def cg_repe(instruction, code):
    return ['while (cpu.ecx)', '{'] + ['    %s'%c for c in code] + [
                '    --cpu.ecx;',
                '    if (!cpu.flags.zf)',
                '        break;',
                '}',
           ]
cg_repz = cg_repe


def cg_repne(instruction, code):
    return ['while (cpu.ecx)', '{'] + ['    %s'%c for c in code] + [
                '    --cpu.ecx;',
                '    if (cpu.flags.zf)',
                '        break;',
                '}',
           ]
cg_repnz = cg_repne


def cg_lock(instruction, code):
    """Other threads really run alongside, so locked read-modify-writes are atomic."""
    mnemonic = instruction.mnemonic.split()[1]
    destination = instruction.operands[0]
    if mnemonic in ('inc', 'dec') and destination.type == x86.X86_OP_MEM and destination.size in (2, 4):
        size = destination.size * 8
        operation = {'inc': 'x86::atomic_increment', 'dec': 'x86::atomic_decrement'}[mnemonic]
        overflow = {'inc': 1 << (size - 1), 'dec': (1 << (size - 1)) - 1}[mnemonic]
        result = '%s(reinterpret_cast<x86::reg%d *>(%s))' % (
            operation, size, arguments.get_address(instruction, destination))
        if not instruction.precious_flags:
            return ['%s;' % result]
        return ['{',
                '    x86::reg%d tmp = %s;' % (size, result),
                '    cpu.flags.of = (tmp == %#x);' % overflow,
                '    cpu.set_szp(tmp);',
                '}']
    print('Warning: lock %s at 0x%08x is not atomic' % (mnemonic, instruction.address))
    return code
