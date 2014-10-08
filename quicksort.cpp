#include "quicksort.h"
#include <assert.h>
#include <iostream>
using namespace std;

void qsortSwap(int* s, int i, int j)
{
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int qsortGetPivotIndex(int*s, int len)
{
    return len/2;
}

int qsortPartition(int* s, int len)
{
    int pivotIndex = qsortGetPivotIndex(s, len);
    int pivot = s[pivotIndex];
    qsortSwap(s, pivotIndex, len-1);

    int storedIndex = 0;
    for (int i=0; i<len-1; ++i)
    {
        if(s[i]<pivot)
        {
            qsortSwap(s, i, storedIndex);
            ++storedIndex;
        }
    }

    return storedIndex;
}

void qsort(int* s, int len)
{
    if(len<=1)
        return;

    int iPartition = qsortPartition(s, len);
    qsort(s, iPartition);
    qsort(s+iPartition+1, len-iPartition-1);
}