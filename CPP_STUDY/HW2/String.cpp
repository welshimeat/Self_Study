#pragma warning(disable : 4996)
#include "Person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stringMemCopy(void* p1, void* p2)
{
	strcpy((char*)p1, (char*)p2);
}

void stringClear(void* p)
{
	if ((char*)p != NULL) {
		strcpy((char*)p, "");
	}
}

void stringPrint(void* p)
{
	printf("%s /", (char *)p);
}

int stringCompare(void* p1, void* p2)
{
	return strcmp((char*)p1, (char*)p2);
}
