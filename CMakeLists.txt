cmake_minimum_required(VERSION 3.15)
project(KernelTest C)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Setup C compiler
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /Users/lotteerickson/pkg/clang-9.0.0/bin/clang)
set(CMAKE_C_FLAGS "--target=i686-pc-none-elf -march=i686 -ffreestanding -fno-builtin -nostdlib -nostdinc -nostdinc++")
# Setup ASM assembler
set(CMAKE_ASM_COMPILER /usr/local/bin/nasm)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf32)
enable_language(ASM_NASM)
# Setup linker
# STUPID HACK WARNING!
set(CMAKE_C_LINK_EXECUTABLE "/Users/lotteerickson/pkg/clang-9.0.0/bin/ld.lld CMakeFiles/kernel.sys.dir/main.c.o \
    CMakeFiles/kernel.sys.dir/boot.asm.o -T ../linker.ld -o kernel.sys")

add_executable(kernel.sys main.c boot.asm)