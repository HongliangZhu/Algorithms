#pragma once

//A - the array to be sorted
//n - the number of elements in A
//k - the maximum value of elements in A
//for simplicity, we suppose the minimum value of elements is 0
//
//step1. calculate the possibility distribution function - f(x),  0<=x && x<=k
//step2. calculate the accumulated f(x) - F(x)
//step3. according to F(x), we can work out the position of x ( x donate A[i]) in sorted array.
//e.g. the A[i] with value x, at the position of B(F(x)).
void CountingSort(int A[], int n, int k)
{
    //
    int* f = new int[k+1];
    int* F = new int[k+1];
    int* B = new int[k+1];
    for(int i=0; i<=k; ++i)
    {
        f[i] = 0;
        F[i] = 0;
        //B[i] = 0; 
    }

    //step1. calculate f(x)
    for(int i=0; i<n; ++i)
    {
        f[A[i]] = f[A[i]] + 1;
    }

    //step2. calculate F(x) by accumulating f(x)
    F[0] = f[0];
    for(int x=1; x<=k; ++x)
    {
        F[x] = F[x-1] + f[x];
    }

    //step3. put each elements in its destination in output array B.
    for(int i=n-1; i>=0; --i)
    {
        int x = A[i];
        int pos = F[x];
        B[pos] = x; //move A[i] to its destination
        F[x] = F[x] - 1; //1,2,2,2,3. the last 2 move to pos3, the second 2 move to F[2]-1=pos2, and so forth.
    }

    //print B

    delete []f;
    delete []F;
    delete []B;
}