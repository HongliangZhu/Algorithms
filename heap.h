#pragma once

void HeapElementSwap(int A[], int i, int j)
{
    int temp = A[i];
    A[i-1] = A[j];
    A[j-1] = temp;
}


//A - heap array
//     Note! for simplicity, the root stored in position 1.
//     we won't use position 0.
//n - number of elements in heap
//i - the index of element to be put down.
void MaxHeapify(int A[], int n, int i)
{
    int l = i*2;
    int r = l + 1;
    int largest;
    if(l<=n && A[i]<A[l])  largest = l;
    if(r<=n && A[largest]<A[r]) largest = r;

    if(largest!=i)
    {
        HeapElementSwap(A, largest, i);
        MaxHeapify(A, n, largest);
    }
}

//A - 
//n - number of elements to be built into heap
//Description - max-heapify each non-leaf element 
//      down-to-top to make sure all of the 
//      sub heap are max heap.           
void BuildMaxHeap(int A[], int n)
{
    // m is the index of the last non-leaf element.
    int m = n/2; 
    for(int i=m; i>=1; --i)
    {
        MaxHeapify(A, n, i);
    }
}

//A - heap
//n - number of nodes in heap
//description - 
//  step1. build max heap
//  step2. swap root and last element.
//         while step2 was completed, the largest element
//         was moved to the end of the heap array.
//  step3. exclude the last element from heap, max-heapify
//         the new heap. 
//         continue step2.
//         proceeding likewise until heap size reachs 2.
void HeapSort(int A[], int n)
{
    //step1
    BuildMaxHeap(A, n);
    for(int i=n; i>=2; --i)
    {
        //step2
        HeapElementSwap(A, 1, i);
        //step3
        MaxHeapify(A, i-1, 1);
    }
}
//A - suppose
void MaxHeapInsert(int A[], int n, int key)
{
    A[++n] = key;
    // c - index of the current. 
    // p - index of the parent
    int c = n, p=n/2;
    while(p>=1 && A[c]>A[p])
    {
        HeapElementSwap(A, c, p);
        c = p;
        p = c/2;
    }
}