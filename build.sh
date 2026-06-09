#!/bin/bash
set -e

ASM_DIR="src/GAS"
C_DIR="src/C"
MODULES_DIR="$C_DIR/modules"

as --32 "$ASM_DIR/bootloader.S" -o bootloader.o
ld -m elf_i386 -Ttext 0x7C00 --oformat binary bootloader.o -o bootloader.bin
truncate -s 512 bootloader.bin

rm -f bootloader.o

CFLAGS="-m32 -ffreestanding -nostdlib -fno-pic -fno-stack-protector -mno-red-zone -mno-sse -Wno-discarded-qualifiers -c -I$MODULES_DIR"

gcc $CFLAGS "$C_DIR/main.c" -o main.o

for cfile in "$MODULES_DIR"/*.c; do
    base=$(basename "$cfile" .c)
    gcc $CFLAGS "$cfile" -o "$base.o"
done

as --32 "$ASM_DIR/boot.S" -o boot.o

ld -m elf_i386 -T linker.ld *.o -o kernel.bin

cat bootloader.bin kernel.bin > os.img
truncate -s 1440k os.img

echo "Run with: qemu-system-i386 -fda os.img"
