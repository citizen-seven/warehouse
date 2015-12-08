#include "_qsort.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void _printarr(int* array, int n)
{
    int i;
    for(i=0; i<n;i++)
    {
        printf("%d ", array[i]);
    }
}


void swap(void* l, void* f, unsigned int size)
{
    char* tmp = (char*)calloc(size, sizeof(char));
    memcpy(tmp, l, size);
    memcpy(l, f, size);
    memcpy(f, tmp, size);
    free(tmp);
    return;
}

void qSort(void *array, unsigned int n, unsigned int size, int (*less)(const void *, const void *))
{
    if (n < 2) return;

    char* f = (char*)array + 1*size;
    char* l = ((char*)array) + (n-1)*size;

    while(l >= f)
    {
        if(less((void*)f, array) == -1)
            f += size;
        else
        {
            swap(l, f, size);
            l -= size;
        }
    }

    swap(array, l, size);

    qSort(array, (l-(char*)array)/size, size, less);
    qSort((void*)f, n-1-((l-(char*)array)/size), size, less);
}
