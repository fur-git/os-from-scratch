#ifndef TYPES
#define TYPES

#define CHARACTER 'c'
#define SHORT 's'
#define LONG 'l'
#define LONGLONG 'v'

#define CHARACTERBYTES 1
#define SHORTBYTES 2
#define LONGBYTES 4
#define LONGLONGBYTES 8

typedef struct {
    void* ptr;
    unsigned long size;
} memoryAddress;

typedef struct {
    void* ptr;
    unsigned short elements;
    char type;
} vector;

#endif
