from . import arguments



def cg_sete(instruction, function_bounds, function_names, destination):
    return ['%s = cpu.flags.zf;' % arguments.get_value(instruction, destination)]
cg_setz = cg_sete


def cg_setne(instruction, function_bounds, function_names, destination):
    return ['%s = !cpu.flags.zf;' % arguments.get_value(instruction, destination)]
cg_setnz = cg_setne


def cg_setnbe(instruction, function_bounds, function_names, destination):
    return ['%s = (!cpu.flags.cf && !cpu.flags.zf);' % arguments.get_value(instruction, destination)]
cg_seta = cg_setnbe


# The signed comparisons, on the same conditions the matching jcc use.
def cg_setl(instruction, function_bounds, function_names, destination):
    return ['%s = (cpu.flags.sf != cpu.flags.of);' % arguments.get_value(instruction, destination)]
cg_setnge = cg_setl


def cg_setnl(instruction, function_bounds, function_names, destination):
    return ['%s = (cpu.flags.sf == cpu.flags.of);' % arguments.get_value(instruction, destination)]
cg_setge = cg_setnl


def cg_setle(instruction, function_bounds, function_names, destination):
    return ['%s = (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of));' % arguments.get_value(instruction, destination)]
cg_setng = cg_setle


def cg_setnle(instruction, function_bounds, function_names, destination):
    return ['%s = (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of));' % arguments.get_value(instruction, destination)]
cg_setg = cg_setnle


def cg_test(instruction, function_bounds, function_names, destination, operand):
    return ['cpu.clear_co();',
            'cpu.set_szp(static_cast<x86::reg%s>(%s & %s));' % (destination.size*8,
                                                                arguments.get_value(instruction, destination),
                                                                arguments.get_value(instruction, operand))]


def cg_cmp(instruction, function_bounds, function_names, destination, operand):
    return ['{',
            '    x86::reg%d tmp1 = %s;' % (destination.size * 8,
                                           arguments.get_value(instruction, destination)),
            '    x86::reg%d tmp2 = x86::reg%d(%s);' % (destination.size * 8, destination.size * 8,
                                                       arguments.sign_extend(instruction, operand, destination.size)),
            '    x86::reg%d result = tmp1 - tmp2;' % (destination.size * 8),
            '    cpu.flags.cf = tmp1 < tmp2;',
            '    cpu.flags.of = 1 & (tmp1 >> %d);' % (destination.size * 8 - 1),
            '    cpu.flags.of ^= 1 & (result >> %d);' % (destination.size * 8 - 1),
            '    cpu.flags.of &= (1 & (tmp1 >> %d)) != (1 & (tmp2 >> %d));' % ((destination.size * 8 - 1), (destination.size * 8 - 1)),
            '    cpu.set_szp(result);',
            '}']
