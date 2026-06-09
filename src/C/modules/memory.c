#include "globals.h"
#include "memory.h"

memoryAddress allocateMemory(unsigned long bytes) {
    char* ptr = (MALLOC_ADDRESS + usedRAM);
    memoryAddress construction = { ptr, bytes };
    for (unsigned long i = 0; i < bytes; i++) { *((char*)ptr + i) = 0; }
    usedRAM += bytes;
    return construction;
}

void copyMemory(void* source, void* destination, unsigned long amountToCopy, unsigned char type) {
    for (unsigned long i = 0; i < amountToCopy; i++) {
        switch (type) {
            case CHARACTER: {
                char* currentElement = (char*)((char*)source + i * CHARACTERBYTES);
                char* target = (char*)((char*)destination + i * CHARACTERBYTES);
                *target = *currentElement;
                break;
            }
            case SHORT: {
                short* currentElement = (short*)((char*)source + i * SHORTBYTES);
                short* target = (short*)((char*)destination + i * SHORTBYTES);
                *target = *currentElement;
                break;
            }
            case LONG: {
                long* currentElement = (long*)((char*)source + i * LONGBYTES);
                long* target = (long*)((char*)destination + i * LONGBYTES);
                *target = *currentElement;
                break;
            }
            case LONGLONG: {
                long long* currentElement = (long long*)((char*)source + i * LONGLONGBYTES);
                long long* target = (long long*)((char*)destination + i * LONGLONGBYTES);
                *target = *currentElement;
                break;
            }
            default:
                long long* target = (long long*)((char*)destination + i * LONGLONGBYTES);
                *target = 0;
                break;
        }
    }
}

void setMemory(void* value, void* destination, unsigned long amountToSet, char type) {
    for (unsigned long i = 0; i < amountToSet; i++) {
        switch (type) {
            case CHARACTER:
                *(char*)((char*)destination + i * CHARACTERBYTES) = *(char*)(value);
                break;
            case SHORT:
                *(short*)((char*)destination + i * SHORTBYTES) = *(short*)(value);
                break;
            case LONG:
                *(long*)((char*)destination + i * LONGBYTES) = *(long*)(value);
                break;
            case LONGLONG:
                *(long long*)((char*)destination + i * LONGLONGBYTES) = *(long long*)(value);
                break;
            default:
                *(char*)(destination + i) = 0;
                break; 
        }
    }
}
