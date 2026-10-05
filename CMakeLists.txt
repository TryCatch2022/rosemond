cmake_minimum_required(VERSION 3.15)
project(nfs_recompiled LANGUAGES C CXX ASM)

# Generates the entry points of the translated routines at build time.
find_package(Python3 COMPONENTS Interpreter REQUIRED)

# options
option(WITH_PEDANTIC_FPU "Compile pedantic FPU implementation" OFF)
option(WITH_MMX "Enable MMX support" ON)

# add compile definitions based on options
if(WITH_PEDANTIC_FPU)
    add_compile_definitions(WITH_PEDANTIC_FPU)
endif()
if(WITH_MMX)
    add_compile_definitions(WITH_MMX)
endif()

# Detect Windows target: covers native Windows (WIN32/MINGW), an explicit
# -DCMAKE_SYSTEM_NAME=Windows, and cross-compilation via a MinGW toolchain
# supplied directly with -DCMAKE_C_COMPILER=…/x86_64-w64-mingw32-gcc (in
# which case WIN32/MINGW may not yet be set if no toolchain file is used).
if(WIN32 OR MINGW OR CMAKE_SYSTEM_NAME STREQUAL "Windows"
        OR CMAKE_C_COMPILER MATCHES "mingw"
        OR CMAKE_CXX_COMPILER MATCHES "mingw")
    set(TARGET_WINDOWS TRUE)
else()
    set(TARGET_WINDOWS FALSE)
endif()

if (MSVC)
    # Cmake is cancer.
    add_compile_options(
        $<$<COMPILE_LANGUAGE:CXX>:/W4>
        $<$<COMPILE_LANGUAGE:CXX>:/WX>
        $<$<COMPILE_LANGUAGE:CXX>:/wd4201>
        $<$<COMPILE_LANGUAGE:CXX>:/wd4245>
        $<$<COMPILE_LANGUAGE:CXX>:/wd4310>
        $<$<COMPILE_LANGUAGE:CXX>:/wd4702>
        $<$<COMPILE_LANGUAGE:CXX>:/wd4996>
        $<$<COMPILE_LANGUAGE:CXX>:/std:c++17>
    )
    add_link_options($<$<COMPILE_LANGUAGE:CXX>:/SAFESEH:NO>)
else()
    add_compile_options(-Wall -Wextra -Werror -Wstrict-aliasing=2 -msse4.2 -std=c++17)
    add_link_options(-static)
endif()

# On 32-bit x86 neither MMX nor SSE is on by default, but x86::regmmx converts
# to __m64/__m128i, and returning an SSE vector without SSE enabled changes the
# ABI (-Werror=psabi). The emulated CPU needs both anyway.
if(NOT MSVC AND CMAKE_SYSTEM_PROCESSOR MATCHES "^(i.86|x86)$")
    add_compile_options(-mmmx -msse -msse2)
endif()

file(GLOB GAME_DISASM_SOURCES
     "${CMAKE_SOURCE_DIR}/src/game/disassembly/*.cpp")
file(GLOB GAME_DISASM_HEADERS
     "${CMAKE_SOURCE_DIR}/src/game/disassembly/*.h")

# ---------------------------------------------------------------------------
# core static library
# ---------------------------------------------------------------------------

file(GLOB LIB_CPP_SOURCES
     "${CMAKE_SOURCE_DIR}/src/lib/*.cpp"
)

# Entering real machine code means standing on the emulated stack for the length
# of one call, which has to be written by hand. The two files are the same
# routine in the two assembler dialects.
if(MSVC)
    enable_language(ASM_MASM)
    list(APPEND LIB_CPP_SOURCES "${CMAKE_SOURCE_DIR}/src/lib/trampoline_masm.asm")
else()
    list(APPEND LIB_CPP_SOURCES "${CMAKE_SOURCE_DIR}/src/lib/trampoline.S")
endif()

# x87.asm provides 80-bit extended-precision FPU helpers and is only needed
# (and only supported) on Linux with WITH_PEDANTIC_FPU=ON.
if(WITH_PEDANTIC_FPU AND TARGET_WINDOWS)
    message(FATAL_ERROR
        "WITH_PEDANTIC_FPU is not supported on Windows: the x87 NASM helper "
        "relies on Linux-specific 80-bit long double ABI conventions.")
endif()

if(WITH_PEDANTIC_FPU AND NOT TARGET_WINDOWS)
    set(X87_OBJ "${CMAKE_CURRENT_BINARY_DIR}/x87.o")
    add_custom_command(
        OUTPUT ${X87_OBJ}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND nasm -f elf64 -o ${X87_OBJ} ${CMAKE_SOURCE_DIR}/src/lib/x87.asm
        DEPENDS ${CMAKE_SOURCE_DIR}/src/lib/x87.asm
        COMMENT "Assembling x87.asm (elf64, pedantic FPU)"
        VERBATIM
    )
    list(APPEND LIB_CPP_SOURCES ${X87_OBJ})
endif()

add_library(game_core STATIC ${LIB_CPP_SOURCES})
target_include_directories(game_core PRIVATE
    ${CMAKE_SOURCE_DIR}/include)
# target_link_libraries(game_core PRIVATE ...)

# Everything the disassembler generates compiles into a DLL. The program is the
# generated stub executable, which carries the original binary's segments at
# their own addresses and calls one exported function here.
function(add_game_target name)
    # script and directories
    set(game_src_dir "${CMAKE_SOURCE_DIR}/src/${name}")

    # collect sources
    file(GLOB GAME_SOURCES "${game_src_dir}/*.cpp")

    # Functions moved from translated assembly to C++ (see
    # ghidra_scripts/ExportDecompiled.java), and the stubs between the two.
    # Decompiled code reinterprets memory freely, the way the machine code
    # did, so it is built without strict aliasing; it converts between integers
    # and pointers the way C lets it (-fpermissive); and it is not warning-free
    # until someone has cleaned it up, so warnings are not errors there.
    file(GLOB DECOMP_SOURCES CONFIGURE_DEPENDS "${game_src_dir}/decomp/*.cpp")
    set(DECOMP_BRIDGE_SOURCES ${DECOMP_SOURCES})

    # The entry point of every translated routine, which runs either its
    # translation or its decompiled C++ function, and the C++ side of every
    # routine still in assembly. Generated here rather than by the disassembler
    # because it follows what Ghidra says (names, signatures, what is
    # decompiled), which changes all the time: an export from Ghidra and a build
    # are all a change there needs.
    set(routines "${game_src_dir}/disassembly/${name}.routines.json")
    if(EXISTS ${routines})
        set(stubs "${CMAKE_CURRENT_BINARY_DIR}/${name}.cstubs.cpp")
        set(registry "${game_src_dir}/decomp/registry.json")
        set(prototypes "${game_src_dir}/ghidra/prototypes.json")
        set(stub_inputs ${routines} "${CMAKE_SOURCE_DIR}/disasm/cstubs.py")
        foreach(input ${registry} ${prototypes})
            if(EXISTS ${input})
                list(APPEND stub_inputs ${input})
            endif()
        endforeach()
        add_custom_command(
            OUTPUT ${stubs}
            COMMAND ${Python3_EXECUTABLE} "${CMAKE_SOURCE_DIR}/disasm/cstubs.py"
                    ${routines} ${registry} ${prototypes} ${stubs}
            DEPENDS ${stub_inputs}
            COMMENT "Generating the entry points and stubs to decompiled C++"
            VERBATIM)
        list(APPEND DECOMP_BRIDGE_SOURCES ${stubs})
        list(APPEND DECOMP_SOURCES ${stubs})
    endif()
    if(DECOMP_BRIDGE_SOURCES)
        if(MSVC)
            set_source_files_properties(${DECOMP_BRIDGE_SOURCES} PROPERTIES
                COMPILE_OPTIONS "/WX-")
        else()
            set_source_files_properties(${DECOMP_BRIDGE_SOURCES} PROPERTIES
                COMPILE_OPTIONS "-fno-strict-aliasing;-fpermissive;-Wno-error;-Wno-unused-variable;-Wno-unused-but-set-variable;-Wno-unused-label;-Wno-unused-parameter")
        endif()
    endif()

    # pick the hardcoded disasm set for this game
    if(name STREQUAL "game")
        set(DISASM_SOURCES ${GAME_DISASM_SOURCES})
        set(DISASM_HEADERS ${GAME_DISASM_HEADERS})
    else()
        set(DISASM_SOURCES "")
        set(DISASM_HEADERS "")
    endif()

    # adding the headers to the executable source list is what makes CMake
    # aware that the custom command must run before compilation starts.
    add_library(${name} SHARED ${GAME_SOURCES} ${DECOMP_SOURCES} ${DISASM_SOURCES} ${DISASM_HEADERS})
    # The stub imports this by name, so the file name is fixed.
    set_target_properties(${name} PROPERTIES PREFIX "" OUTPUT_NAME "${name}_code")
    set_source_files_properties(${DISASM_HEADERS} PROPERTIES HEADER_FILE_ONLY TRUE)
    target_include_directories(${name} PRIVATE
        ${game_src_dir}
        ${CMAKE_SOURCE_DIR}/src/${name}/disassembly
        ${CMAKE_SOURCE_DIR}/src/${name}/ghidra
        ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${name} PRIVATE game_core)
    if(TARGET_WINDOWS)
        # The recompiled code calls the real Win32 API through the bridge in
        # include/winapi/wrapper.h, so the imports the executable had must be
        # satisfied for real. binkw32/smackw32 are RAD's codecs rather than
        # system DLLs, so their import libraries ship in lib/.
        target_link_libraries(${name} PRIVATE
            winmm ddraw dsound gdi32 user32 kernel32
            ${CMAKE_SOURCE_DIR}/lib/dinput.lib
            ${CMAKE_SOURCE_DIR}/lib/binkw32.lib
            ${CMAKE_SOURCE_DIR}/lib/SMACKW32.LIB)
    endif()

    # The generated stub executable is the program. It has to sit beside the DLL,
    # which it imports by name, so stage it into the output directory.
    set(stub_script "${game_src_dir}/disassembly/${name}.link.cmake")
    if(EXISTS ${stub_script})
        include(${stub_script})
        if(NOT TARGET_WINDOWS)
            message(FATAL_ERROR
                "${name} is generated for 32-bit Windows: its stub executable "
                "places the original binary's segments at fixed addresses. "
                "Configure with -DCMAKE_TOOLCHAIN_FILE=cmake/i686-w64-mingw32.cmake")
        endif()
        add_custom_command(TARGET ${name} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${game_src_dir}/disassembly/${${name}_STUB_EXE}"
                    $<TARGET_FILE_DIR:${name}>
            COMMENT "Staging ${${name}_STUB_EXE} beside ${${name}_CODE_DLL}"
            VERBATIM)
    endif()

    if(WITH_PEDANTIC_FPU)
        target_compile_definitions(${name} PRIVATE WITH_PEDANTIC_FPU)
    endif()
    if(WITH_MMX)
        target_compile_definitions(${name} PRIVATE WITH_MMX)
    endif()
endfunction()

add_game_target(game)
