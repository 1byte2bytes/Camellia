cmake_minimum_required(VERSION 3.10)
project(Camellia C)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Setup C compiler
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_C_FLAGS "--target=i686-pc-none-elf -march=i686 -ffreestanding -fno-builtin -nostdlib -nostdinc")
# Setup ASM assembler
set(CMAKE_ASM_COMPILER /usr/local/opt/nasm/bin/nasm)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf32)
enable_language(ASM_NASM)
# Setup linker
# STUPID HACK WARNING!
set(CMAKE_C_LINK_EXECUTABLE "/usr/bin/ld.gold --script=../linker.ld -o kernel.sys \
    CMakeFiles/kernel.sys.dir/boot.asm.o CMakeFiles/kernel.sys.dir/main.c.o CMakeFiles/kernel.sys.dir/vga.c.o \
    CMakeFiles/kernel.sys.dir/serial.c.o CMakeFiles/kernel.sys.dir/io.c.o CMakeFiles/kernel.sys.dir/string.c.o \
    CMakeFiles/kernel.sys.dir/stdio.c.o")

add_executable(kernel.sys boot.asm main.c vga.c serial.c io.c string.c stdio.c config.h vga.h stdint.h io.h string.h serial.h stdio.h)