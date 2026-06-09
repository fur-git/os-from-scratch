#include "misc.h"
#include "globals.h"
#include "memory.h"
#include "utilities.h"
#include "strings.h"
#include "printing.h"

void suicide(void) {
    while (1) {
        char* ptr = 0;
        cursor = 0;
        for (unsigned char i = 0; i < 255; i++) { printString(KERNELPANIC); }
        for (unsigned long i = 0; i < 0x100000; i++) { *(ptr + i) = 0; }
        halt();
    }
}

bool isEqualEcho(char* originMsg) {
    char firstFiveSymbols[6] = {0};
    copyMemory(originMsg, firstFiveSymbols, 5, CHARACTER);
    bool isValid = isEqual(firstFiveSymbols, ECHOCMD);
    return isValid;
}

bool isEqualWrite(char* originMsg) {
    char firstSixSymbols[7] = {0};
    copyMemory(originMsg, firstSixSymbols, 6, CHARACTER);
    bool isValid = isEqual(firstSixSymbols, WRITECMD);
    return isValid;
}

bool isEqualRead(char* originMsg) {
    char firstFiveSymbols[6] = {0};
    copyMemory(originMsg, firstFiveSymbols, 5, CHARACTER);
    bool isValid = isEqual(firstFiveSymbols, READCMD);
    return isValid;
}

bool isEqualErase(char* originMsg) {
    char firstSixSymbols[7] = {0};
    copyMemory(originMsg, firstSixSymbols, 6, CHARACTER);
    bool isValid = isEqual(firstSixSymbols, ERASECMD);
    return isValid;
}
