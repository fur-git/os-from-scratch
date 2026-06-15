#include "globals.h"

volatile unsigned short cursor = 0;
volatile unsigned long usedRAM = 0;
volatile unsigned short* vga = (unsigned short*)0xB8000;
volatile char* MALLOC_ADDRESS = (char*)0x100000;
volatile bool isCtrlHeld = false;
