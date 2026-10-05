import os
from .bounds import Bounds
from .module import Module

class Application(Module):
    def __init__(self, application_name, exe_path, rebase_after):
        Module.__init__(self, application_name, exe_path, rebase_after)

    def write(self, thread_segments=[], skip_instructions=[], dlls=[], function_names={},
              decompiled=frozenset()):
        try:
            os.makedirs('src/%s/disassembly' % (self.application_name))
        except OSError:
            pass
        with open('src/%s/disassembly/%s.cpp' % (self.application_name, self.application_name), 'w') as src:
            with open('src/%s/disassembly/%s.h' % (self.application_name,  self.application_name), 'w') as h:
                app_name = self.application_name
                APP_NAME = self.application_name.upper()
                src.write('#include "%s.h"\n'
                          '#include <x86.h>\n'
                          '#include <winapi/wrapper.h>\n' % (app_name))
                for dll in dlls:
                    src.write('#include "%s.h"\n' % (dll.application_name))
                for dll_name, dll_methods in self.dll_imports:
                    src.write('#include <winapi/%s.h>\n' % dll_name.decode())
                for dll in dlls:
                    for dll_name, dll_methods in dll.dll_imports:
                        src.write('#include <winapi/%s.h>\n' % dll_name.decode())
                src.write('\nnamespace %s\n'
                            '{\n\n' % (app_name))
                h.write('#ifndef %s_H_\n'
                        '#define %s_H_\n'
                        '#include <x86.h>\n'
                        '#include <lib/winapp.h>\n'
                        '#include <map>\n'  % (APP_NAME, APP_NAME))
                h.write('\nnamespace %s\n'
                        '{\n\n' % (app_name))
                # The segments are sections of the stub executable, mapped by the
                # loader at the addresses the original binary used, so nothing
                # here declares them -- the generated code reaches them through
                # those addresses directly.
                h.write('// Called by the stub executable through its import table.\n'
                        'extern "C" __declspec(dllexport) int %s();\n' % self.entry_symbol())
                h.write('\n'
                        'class Application : public win32::WinApplication\n'
                        '{\n'
                        'public:\n'
                        '    Application();\n'
                        '    void execute();\n'
                        '    // Public so the stubs to and from decompiled functions\n'
                        '    // (%s.cstubs.cpp) can reach them.\n' % app_name)
                self.build_stub_exe()
                src.write('Application::Application()\n'
                            '{\n')
                for dll in dlls:
                    print(dll)
                    src.write('        %s::s_registry->registerSymbols(this);\n' % dll.application_name)
                for subroutine in self.subroutines:
                    function_entry = subroutine.get_entry_point()
                    name = function_names.get(function_entry, 'sub_%x' % function_entry)
                    src.write('    registerMethod(0x%08x, {"<Application>%s", &Application::%s});\n' % (function_entry, name, name))
                for dll in dlls:
                    for subroutine in dll.subroutines:
                        function_entry = subroutine.get_entry_point()
                        name = function_names.get(function_entry, 'sub_%x' % function_entry)
                        src.write('    registerMethod(0x%08x, {"<%s>%s", &%s::%s});\n' % (function_entry, dll.application_name, name, dll.application_name, name))
                for dll_name, dll_methods in self.dll_imports:
                    for method, address in dll_methods:
                        src.write('    registerMethod(0x%08x, {"<%s>%s", &win32::Wrapper<decltype(&win32::%s::%s), &win32::%s::%s>::stdcall});\n' % (address, dll_name.decode(), method.decode(), dll_name.decode(), method.decode(), dll_name.decode(), method.decode()))
                for dll in dlls:
                    for dll_name, dll_methods in dll.dll_imports:
                        for method, address in dll_methods:
                            src.write('    registerMethod(0x%08x, {"<%s>%s", &win32::Wrapper<decltype(&win32::%s::%s), &win32::%s::%s>::stdcall});\n' % (address, dll_name.decode(), method.decode(), dll_name.decode(), method.decode(), dll_name.decode(), method.decode()))

                src.write('}\n\n')
                src.write('// The stub executable\'s entry point calls this; the segments it\n'
                          '// carries are mapped before anything here runs.\n'
                          'extern "C" __declspec(dllexport) int %s()\n'
                          '{\n'
                          '    Application application;\n'
                          '    application.execute();\n'
                          '    return 0;\n'
                          '}\n\n' % (self.entry_symbol(),))
                src.write('void Application::execute()\n'
                            '{\n'
                            '    x86::CPU cpu{};\n'
                            '    runThread(cpu, 0x%x);\n'
                            '}\n\n' % (self.entry_point))
                src.write('}\n')

                entry_points = set(s.get_entry_point() for s in self.subroutines)
                for index in range(0, 1+int(len(self.subroutines)/100)):
                    methods = open('src/%s/disassembly/%s.%d.cpp' % (app_name, app_name, index), 'w')
                    methods.write('#include "%s.h"\n'
                                  'namespace %s\n'
                                  '{\n\n' % (app_name, app_name))
                    for subroutine in self.subroutines[100*index:100*(index+1)]:

                        function_start = subroutine.get_start_address()
                        function_end = subroutine.get_end_address()
                        # A function split into disjoint ranges needs real
                        # membership, not just the enclosing interval.
                        function_bounds = subroutine.bounds or Bounds([(function_start, function_end)])
                        # codegen only jumps into the switch when every
                        # destination of an indirect jump lands inside this
                        # function; otherwise it emits a dynamic_call and the
                        # scaffold would be an unused label.
                        uses_dynamic_jump = any(
                            instruction.mnemonic[0] == 'j'
                            and getattr(instruction, 'potential_destinations', None)
                            and all(dest in function_bounds
                                    for dest in instruction.potential_destinations)
                            for instruction in subroutine.instructions)
                        function_entry = subroutine.get_entry_point()
                        name = function_names.get(function_entry, 'sub_%x' % function_entry)
                        if function_entry in decompiled:
                            # Decompiled: the routine under this name is the stub
                            # into the C++ function, in the cstubs file.
                            h.write('    static void %s(WinApplication* app, x86::CPU& cpu);\n' % name)
                            methods.write('/* 0x%08x %s: decompiled, see %s.cstubs.cpp */\n\n'
                                          % (function_entry, name, app_name))
                            continue
                        fallthrough = False
                        methods.write('/* align: skip %s */\n' % (' '.join(['0x%02x'%c for c in subroutine.skipped_blob])))
                        if subroutine.data_blob:
                            methods.write('/* data blob: %s */\n' % (''.join(['%02x'%c for c in subroutine.data_blob])))
                        for jump_entry in subroutine.jump_table:
                            methods.write('/* jump table: 0x%08x */\n' % jump_entry)
                        h.write('    static void %s(WinApplication* app, x86::CPU& cpu);\n' % name)
                        methods.write('void Application::%s(WinApplication* app, x86::CPU& cpu)\n'
                                      '{\n'
                                      '  NFS2_USE(cpu);\n'
                                      '  NFS2_USE(app);\n' % name)
                        if uses_dynamic_jump:
                            methods.write('  goto start;\n'
                                            'dynamic_jump:\n'
                                            '  switch(cpu.ip)\n'
                                            '  {\n'
                                            'start:\n')
                        if function_entry != function_start:
                            methods.write('    goto L_entry_0x%08x;\n' % function_entry)
                        for instruction in subroutine.instructions:
                            if uses_dynamic_jump and instruction.address in [x for _, x in subroutine.dynamic_labels]:
                                if fallthrough:
                                    methods.write('  [[fallthrough]];\n')
                                methods.write('  case 0x%08x:\n' % (instruction.address))
                            if instruction.address in [x for _, x in subroutine.static_labels]:
                                methods.write('L_0x%08x:\n' % (instruction.address))
                            if function_entry != function_start and instruction.address == function_entry:
                                methods.write('L_entry_0x%08x:\n' % (instruction.address))
                            if instruction.address in thread_segments:
                                methods.write('    win32::Thread::sleep(0);\n')
                            methods.write('    // %s\n'
                                          '    %s%s\n'  % (self._raw(subroutine.section, instruction),
                                                           (instruction.address in skip_instructions) and '//' or '',
                                                           '\n    '.join(self.generate(instruction, function_bounds, function_names))))
                            fallthrough = instruction.mnemonic not in ['jmp', 'ret']
                        if fallthrough:
                            # The last instruction runs off the end of the body,
                            # so control continues at the next address. Where that
                            # is a routine of its own, that is a tail call; where
                            # it is not, there is nothing to continue into.
                            if function_end in entry_points:
                                methods.write('    return %s(app, cpu);\n'
                                              % function_names.get(function_end,
                                                                   'sub_%x' % function_end))
                            else:
                                methods.write('    NFS2_ASSERT(false);  '
                                              '// falls off the end of the routine\n')
                            fallthrough = False
                        if uses_dynamic_jump:
                            methods.write('  default:\n'
                                          '    NFS2_ASSERT(false);\n'
                                          '  }\n')
                        methods.write('}\n\n')
                    methods.write('}\n')
                h.write('};\n\n'
                        '}\n\n'
                        '#endif /* !%s_H_ */\n' % (APP_NAME))
        for dll in dlls:
            dll.write(self.application_name, thread_segments, function_names)