#ifndef MEMORY
#define MEMORY

#include "types.h"

memoryAddress allocateMemory(unsigned long bytes);
void copyMemory(void* source, void* destination, unsigned long amountToCopy, unsigned char type);
void setMemory(void* value, void* destination, unsigned long amountToSet, char type);

#endif
