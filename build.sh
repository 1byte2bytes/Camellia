set -e

rm -rf *.o

clang --target=i686-pc-none-elf -march=i686 -I. -Imain -Istdlib -ffreestanding -fno-builtin -nostdlib -nostdinc -c main/io.c -o io.o
clang --target=i686-pc-none-elf -march=i686 -I. -Imain -Istdlib -ffreestanding -fno-builtin -nostdlib -nostdinc -c main/main.c -o main.o
clang --target=i686-pc-none-elf -march=i686 -I. -Imain -Istdlib -ffreestanding -fno-builtin -nostdlib -nostdinc -c modules/serial/serial.c -o serial.o
clang --target=i686-pc-none-elf -march=i686 -I. -Imain -Istdlib -ffreestanding -fno-builtin -nostdlib -nostdinc -c modules/vga/vga.c -o vga.o
clang --target=i686-pc-none-elf -march=i686 -I. -Imain -Istdlib -ffreestanding -fno-builtin -nostdlib -nostdinc -c stdlib/stdio.c -o stdio.o
clang --target=i686-pc-none-elf -march=i686 -I. -Imain -Istdlib -ffreestanding -fno-builtin -nostdlib -nostdinc -c stdlib/string.c -o string.o

nasm -f elf main/boot.asm -o boot.o

clang --target=i686-pc-none-elf -ffreestanding -O2 -nostdlib -T linker.ld -o kernel.sys *.o

# Make GRUB disc
grub-file --is-x86-multiboot kernel.sys

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
 
cp kernel.sys isodir/boot/kernel.sys
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "myos" {
	multiboot /boot/kernel.sys
}
EOF
grub-mkrescue -o build.iso isodir