#pragma once
#include "stdlib.h"

bool FindMinMaxElements(int A[], int n, int& indexOfMin, int& indexOfMax)
{
    if(n==0) return false;

    int minv,maxv;
    int i;
    if(n%2==1)
    {
        minv = maxv = A[0];
        i = 1;
    }
    else
    {
        minv = min(A[0], A[1]);
        maxv = max(A[0], A[1]);
        i = 2;
    }

    for(; i<n; i+=2)
    {
        int indexMin, indexMax;
        if(A[i]<A[i+1])
        {
            indexMin = i;
            indexMax = i+1;
        }
        else
        {
            indexMin = i+1;
            indexMax = i;
        }

        if(A[indexMin]<minv)
        {
            minv = A[indexMin];
            indexOfMin = indexMin;
        }
        if(A[indexMax]>maxv)
        {
            maxv = A[indexMax];
            indexOfMax = indexMax;
        }
    }

    return true;
}

int Swap(int* A, int i, int j)
{
    int temp = A[i];
    A[j] = A[i];
    A[i] = temp;
}

int RandomizedPartition(int* A, int n)
{
    int pivotIndex = rand()%n;
    int pivot = A[pivotIndex];
    Swap(A,pivotIndex, n-1);

    int storedIndex = 0;
    for(int i=0; i<n-1; ++i)
    {
        if(A[i]<pivot)
        {
            Swap(A, i, storedIndex++);
        }
    }

    return storedIndex;
}

int FindKthElement(int* A, int n, int k)
{
    if(n==1) return 0;

    int p = RandomizedPartition(A, n);
    if(p==k) return p;
}