#ifndef AKINATOR
#define AKINATOR

#include <stdio.h>
#include <assert.h>

#include "../tree/tree.h"
#include "onegin/SortText.h"

int     CtorTreeListing     (FILE* file, struct item* root, int* count = nullptr);

CTree   CtorTreeFromFile    (const char* fileName);
item*   CtorItmFromFile     (char* buffer, int* index, int sizeBuf);

#endif
