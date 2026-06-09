#ifndef VECTOR
#define VECTOR

#include "types.h"

void addToVector(vector* arg, void* value, char argType);
void deleteLatestVectorElement(vector* arg, char argType);
void* getVectorElement(vector* arg, unsigned short argElement);

#endif
