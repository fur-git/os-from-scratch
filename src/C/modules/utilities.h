#ifndef UTILITIES
#define UTILITIES

unsigned long getStrLen(char* strArg);
void reverseArray(char* strArg, unsigned long length);
void itoa(unsigned long intArg, char* buffer);
char toAscii(unsigned char code);
bool isEqual(char* originMsg, char* comparisonMsg);
char getFileDescriptorFromInput(char originChar);
char inb(unsigned short port);
void outb(unsigned short port, unsigned char value);
void outw(unsigned short port, unsigned short value);
void halt(void);

#endif
