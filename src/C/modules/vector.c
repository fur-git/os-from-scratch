#include "vector.h"
#include "types.h"
#include "memory.h"

void addToVector(vector* arg, void* value, char argType) {
    switch (argType) {
        case CHARACTER: {
            unsigned short targetVectorElement = (*arg).elements;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            copyMemory((char*)value, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, CHARACTER);
            (*arg).elements++;
            break;
        }
        case SHORT: {
            unsigned short targetVectorElement = (*arg).elements;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            copyMemory((short*)value, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, SHORT);
            (*arg).elements++;
            break;
        }
        case LONG: {
            unsigned short targetVectorElement = (*arg).elements;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            copyMemory((long*)value, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, LONG);
            (*arg).elements++;
            break;
        }
        case LONGLONG: {
            unsigned short targetVectorElement = (*arg).elements;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            copyMemory((long long*)value, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, LONGLONG);
            (*arg).elements++;
            break;
        }
    }
}

void deleteLatestVectorElement(vector* arg, char argType) {
    switch (argType) {
        case CHARACTER: {
            unsigned short targetVectorElement = (*arg).elements - 1;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            char nothingness = 0;
            setMemory(&nothingness, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, CHARACTER);
            (*arg).elements--;
            break;
        }
        case SHORT: {
            unsigned short targetVectorElement = (*arg).elements - 1;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            char nothingness = 0;
            setMemory(&nothingness, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, SHORT);
            (*arg).elements--;
            break;
        }
        case LONG: {
            unsigned short targetVectorElement = (*arg).elements - 1;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            char nothingness = 0;
            setMemory(&nothingness, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, LONG);
            (*arg).elements--;
            break;
        }
        case LONGLONG: {
            unsigned short targetVectorElement = (*arg).elements - 1;
            unsigned short offset;
            switch ((*arg).type) {
                case CHARACTER: offset = CHARACTERBYTES; break;
                case SHORT: offset = SHORTBYTES; break;
                case LONG: offset = LONGBYTES; break;
                case LONGLONG: offset = LONGLONGBYTES; break;
            }
            char nothingness = 0;
            setMemory(&nothingness, ((char*)((*arg).ptr) + (targetVectorElement * offset)), 1, LONGLONG);
            (*arg).elements--;
            break;
        }
    }
}

void* getVectorElement(vector* arg, unsigned short argElement) {
    unsigned short targetVectorElement = argElement;
    unsigned short offset;
    switch ((*arg).type) {
        case CHARACTER: offset = CHARACTERBYTES; break;
        case SHORT: offset = SHORTBYTES; break;
        case LONG: offset = LONGBYTES; break;
        case LONGLONG: offset = LONGLONGBYTES; break;
    }
    void* ptr = ((char*)(*arg).ptr) + (targetVectorElement * offset);
    return ptr;
}
