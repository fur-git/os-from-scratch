#include "printing.h"
#include "globals.h"
#include "utilities.h"

void clear(void) { for (unsigned short i = 0; i < 2000; i++) { vga[i] = 0x0F20; } cursor = 0; }

void printChar(char* character) {
    if (cursor == 2000) {
        for (unsigned short i = 1920; i < 2000; i++) { vga[i] = 0x0F00; }
        cursor = 1920;
    }
    if (*character == '\n') { cursor = cursor + (80 - cursor % 80); }
    else { vga[cursor] = 0x0F00 | *character; cursor++; }
}

void printString(char* string) {
    unsigned long stringLen = getStrLen(string);
    for (unsigned long i = 0; i < stringLen; i++) { printChar(string + i); }
}

void backspace(void) {
    if (cursor == 0) { return; }
    cursor--;
    vga[cursor] = 0x0F20;
}
