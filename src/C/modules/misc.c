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

bool isEqualExpress(char* originMsg) {
    char firstEightSymbols[9] = {0};
    copyMemory(originMsg, firstEightSymbols, 8, CHARACTER);
    bool isValid = isEqual(firstEightSymbols, EXPRESSCMD);
    return isValid;
}

void runExpress(char* originMsg, unsigned char length) {
    unsigned char i = 8;
    if (length <= i) { printString(INVALID); return; }
    unsigned long left = 0;
    while (i < length && originMsg[i] >= '0' && originMsg[i] <= '9') {
        left = left * 10 + (originMsg[i] - '0');
        i++;
    }
    if (i == 8 || i >= length) { printString(INVALID); return; }
    char op = originMsg[i];
    if (op != '+' && op != '-' && op != '*' && op != '/') { printString(INVALID); return; }
    i++;
    if (i >= length) { printString(INVALID); return; }
    unsigned long right = 0;
    unsigned char rightStart = i;
    while (i < length && originMsg[i] >= '0' && originMsg[i] <= '9') {
        right = right * 10 + (originMsg[i] - '0');
        i++;
    }
    if (i == rightStart || i != length) { printString(INVALID); return; }
    unsigned long result;
    switch (op) {
        case '+': result = left + right; break;
        case '-':
            if (left < right) { printString(INVALID); return; }
            result = left - right;
            break;
        case '*': result = left * right; break;
        case '/':
            if (right == 0) { printString(INVALID); return; }
            result = left / right;
            break;
    }
    char resultBuffer[255] = {0};
    itoa(result, resultBuffer);
    printString(resultBuffer);
    printChar(NEWLINE);
}

void runListFs(char files[10][1024]) {
    char numBuffer[16] = {0};
    for (unsigned char i = 0; i < 10; i++) {
        printString("FILE ");
        itoa(i, numBuffer);
        printString(numBuffer);
        printString(": ");
        itoa(getStrLen(files[i]), numBuffer);
        printString(numBuffer);
        printString(" BYTES");
        printChar(NEWLINE);
    }
}
