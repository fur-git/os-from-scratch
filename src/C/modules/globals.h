#ifndef GLOBALS
#define GLOBALS

extern volatile unsigned short* vga;
extern volatile unsigned short cursor;
extern volatile unsigned long usedRAM;
extern volatile char* MALLOC_ADDRESS;
extern volatile bool isCtrlHeld;

#endif
