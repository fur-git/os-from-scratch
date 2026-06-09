#include "utilities.h"

unsigned long getStrLen(char* strArg) {
    unsigned long i = 0;
    for (unsigned long j = 0; j < 4294967295; j++) { if (*(strArg + j) != 0) { i++; } else { break; } }
    return i;
}

void reverseArray(char* strArg, unsigned long length) {
    unsigned long currentElement = 0;
    unsigned long lastElement = length - 1;
    while (currentElement < lastElement) {
        char tmp = strArg[currentElement];
        strArg[currentElement] = strArg[lastElement];
        strArg[lastElement] = tmp;
        currentElement++;
        lastElement--;
    }
}

void itoa(unsigned long intArg, char* buffer) {
    if (intArg == 0) { buffer[0] = '0'; return; }
    unsigned char counter = 0;
    for (unsigned long j = 0; j < 255; j++) {
        if (intArg / 10 == 0 && intArg % 10 == 0 && intArg == 0) { break; }
        buffer[j] = intArg % 10 + 48;
        intArg /= 10;
        counter++;
    }
    reverseArray(buffer, counter);
}

char toAscii(unsigned char code) {
    char parsed;
    switch (code) {
        case 0x1F: parsed = 'S'; break;
        case 0x16: parsed = 'U'; break;
        case 0x31: parsed = 'N'; break;
        case 0x14: parsed = 'T'; break;
        case 0x30: parsed = 'B'; break;
        case 0x11: parsed = 'W'; break;
        case 0x20: parsed = 'D'; break;
        case 0x23: parsed = 'H'; break;
        case 0x12: parsed = 'E'; break;
        case 0x18: parsed = 'O'; break;
        case 0x2E: parsed = 'C'; break;
        case 0x26: parsed = 'L'; break;
        case 0x1E: parsed = 'A'; break;
        case 0x13: parsed = 'R'; break;
        case 0x17: parsed = 'I'; break;
        case 0x19: parsed = 'P'; break;
        case 0x21: parsed = 'F'; break;
        case 0x15: parsed = 'Y'; break;
        case 0x32: parsed = 'M'; break;
        case 0x2B: parsed = '\\'; break;
        case 0x0B: parsed = '0'; break;
        case 0x02: parsed = '1'; break;
        case 0x03: parsed = '2'; break;
        case 0x04: parsed = '3'; break;
        case 0x05: parsed = '4'; break;
        case 0x06: parsed = '5'; break;
        case 0x07: parsed = '6'; break;
        case 0x08: parsed = '7'; break;
        case 0x09: parsed = '8'; break;
        case 0x0A: parsed = '9'; break;
        case 0x39: parsed = ' '; break;
        case 0x0E: parsed = '~'; break;
        case 0x1C: parsed = '!'; break;
        default: parsed = '?'; break;
    };
    return parsed;
}

bool isEqual(char* originMsg, char* comparisonMsg) {
    bool isValid = true;
    unsigned char originMsgLen = getStrLen(originMsg);
    unsigned char comparisonMsgLen = getStrLen(comparisonMsg);
    if (originMsgLen != comparisonMsgLen) { isValid = false; }
    if (isValid) { for (unsigned char i = 0; i < originMsgLen; i++) { if (originMsg[i] != comparisonMsg[i]) { isValid = false; } } }
    return isValid;
}

char getFileDescriptorFromInput(char originChar) {
    char fileDescriptor;
    switch (originChar) {
        case '0': fileDescriptor = 0; break;
        case '1': fileDescriptor = 1; break;
        case '2': fileDescriptor = 2; break;
        case '3': fileDescriptor = 3; break;
        case '4': fileDescriptor = 4; break;
        case '5': fileDescriptor = 5; break;
        case '6': fileDescriptor = 6; break;
        case '7': fileDescriptor = 7; break;
        case '8': fileDescriptor = 8; break;
        case '9': fileDescriptor = 9; break;
        default: fileDescriptor = -1; break;
    }
    return fileDescriptor;
}

char inb(unsigned short port) {
    char value;
    __asm__ volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

void outb(unsigned short port, unsigned char value) { __asm__ volatile ("outb %0, %1" : : "a"(value), "Nd"(port)); }
void outw(unsigned short port, unsigned short value) { __asm__ volatile ("outw %0, %1" : : "a"(value), "Nd"(port)); }

void halt(void) { while (1) {} }
