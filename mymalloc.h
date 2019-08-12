#ifndef __MYMALLOC_H__
#define __MYMALLOC_H__

#include <stdio.h>
#include <stdlib.h>
#include "blockfunctions.h"
#include "structfunctions.h"


#define malloc(x) mymalloc(x, __FILE__, __LINE__)
#define free(x) myfree(x, __FILE__, __LINE__)

typedef int bool;
#define true 1
#define false 0

// Function signatures -------------------
void *mymalloc(size_t size, char *filename, int line);
void myfree(void *ptr, char *filename, int line);

// Global Variables -------------------
static char block[4096];


#endif
