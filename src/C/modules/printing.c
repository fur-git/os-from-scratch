#include "printing.h"
#include "globals.h"
#include "utilities.h"

static void writeCrtc(unsigned char index, unsigned char value) {
    outb(0x3D4, index);
    outb(0x3D5, value);
}

static void syncHardwareCursor(void) {
    writeCrtc(0x0E, (unsigned char)(cursor >> 8));
    writeCrtc(0x0F, (unsigned char)(cursor & 0xFF));
}

void initCursor(void) {
    writeCrtc(0x0A, 0x0E);
    writeCrtc(0x0B, 0x0F);
    syncHardwareCursor();
}

void clear(void) {
    for (unsigned short i = 0; i < 2000; i++) { vga[i] = 0x0F20; }
    cursor = 0;
    syncHardwareCursor();
}

void printChar(char* character) {
    if (cursor == 2000) {
        for (unsigned short i = 1920; i < 2000; i++) { vga[i] = 0x0F00; }
        cursor = 1920;
    }
    if (*character == '\n') { cursor = cursor + (80 - cursor % 80); }
    else { vga[cursor] = 0x0F00 | *character; cursor++; }
    syncHardwareCursor();
}

void printString(char* string) {
    unsigned long stringLen = getStrLen(string);
    for (unsigned long i = 0; i < stringLen; i++) { printChar(string + i); }
}

void backspace(void) {
    if (cursor == 0) { return; }
    cursor--;
    vga[cursor] = 0x0F20;
    syncHardwareCursor();
}
