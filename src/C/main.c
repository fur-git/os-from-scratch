#include "types.h"
#include "globals.h"
#include "printing.h"
#include "memory.h"
#include "utilities.h"
#include "misc.h"
#include "strings.h"
#include "vector.h"

void mainC(void) {
    clear();
    initCursor();
    printString(DEFAULT);
    printString(INPUT);
    char symbols[65] = {0};
    char files[10][1024];
    char buffer[255];
    memoryAddress tmp = allocateMemory(1);
    setMemory(tmp.ptr, files, 1024*10, CHARACTER);
    volatile char actualCharacters = 0;
    while (1) {
        if ((inb(0x64) & 1) != 0) {
            char input = inb(0x60);
            char parsed = toAscii(input);
            if (parsed == 0) { continue; }
            if (parsed != '~' && parsed != '!' && parsed != '?' && actualCharacters != 64) {
                symbols[actualCharacters] = parsed;
                actualCharacters++;
                printChar(&parsed);
            }
            else if (parsed == '~') {
                if (actualCharacters != 0) {
                    symbols[actualCharacters] = 0;
                    actualCharacters--;
                    backspace();
                }
            }
            else if (parsed == '!') {
                symbols[actualCharacters] = 0;
                printChar(NEWLINE);
                if (isEqualEcho(symbols)) {
                    for (unsigned short j = 0; j < (actualCharacters - 5); j++) { printChar(&symbols[j+5]); }
                    printChar(NEWLINE);
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqual(symbols, HELPCMD)) {
                    printString(HELPTEXT);
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqual(symbols, CLEARCMD)) {
                    clear();
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqual(symbols, LISTFSCMD)) {
                    runListFs(files);
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqual(symbols, FUNNYCMD)) { clear(); while (1) { printString(FUNNYEASTEREGG); } }
                else if (isEqualWrite(symbols) && actualCharacters >= 8) {
                    char fileDescriptor = getFileDescriptorFromInput(symbols[6]);
                    if (fileDescriptor != -1 && symbols[7] == ' ') {
                        char zero = 0;
                        setMemory(&zero, files[fileDescriptor], 1024, CHARACTER);
                        for (unsigned char j = 0; j < (actualCharacters - 8); j++) { files[fileDescriptor][j] = symbols[j+8]; }
                    }
                    else { printString(INVALID); }
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqualRead(symbols) && actualCharacters >= 6) {
                    char fileDescriptor = getFileDescriptorFromInput(symbols[5]);
                    if (fileDescriptor != -1) { printString(files[fileDescriptor]); }
                    else { printString(INVALID); }
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                    printChar(NEWLINE);
                }
                else if (isEqualErase(symbols) && actualCharacters >= 7) {
                    char fileDescriptor = getFileDescriptorFromInput(symbols[6]);
                    if (fileDescriptor != -1) { for (unsigned short j = 0; j < 1024; j++) { files[fileDescriptor][j] = 0; } }
                    else { printString(INVALID); }
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqualExpress(symbols) && actualCharacters >= 11) {
                    runExpress(symbols, actualCharacters);
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                else if (isEqual(symbols, SUICIDECMD)) { suicide(); }
                else if (isEqual(symbols, HALTCMD)) { halt(); }
                else {
                    printString(INVALID);
                    for (unsigned char j = 0; j < 65; j++) { symbols[j] = 0; }
                    actualCharacters = 0;
                }
                printString(INPUT);
            }
            else if (parsed == '?') {}
            else { printString(PLACEHOLDER); }
        }
    }
}
