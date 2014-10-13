#pragma once

int binarySearch(int A[], int n, int x)
{
    int low = 0, high=n-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if (x==A[mid])
        {
            return mid;
        }
        if (x<A[mid])
        {
            high = mid - 1;
        } 
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int binarySearch(int A[], int n, int x, bool searchFirst)
{
    int low = 0, high=n-1, mid, result=-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if (x==A[mid])
        {
            result = mid;
            if (searchFirst) high = mid - 1;
            else low = mid + 1;
        }
        if (x<A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return result;
}

int countOccurence(int A[], int n, int x)
{
    int firstIndex = binarySearch(A, n, x, true);
    if(firstIndex==-1)
    {
        return 0;
    }
    else
    {
        int lastIndex = binarySearch(A, n, x, false);
        return lastIndex-firstIndex+1;
    }
}

//number of rotate is the index of the minimum number in A.
//case 1: A[low] < A[high] 
//return low;
//
//next = (mid+1)%N
//prev = (mid+N-1)%N
//case 2: A.mid <A.next && A.mid <A.prev
//return mid
//
//case 3: A.mid<A.high
//high = (mid+N-1)%N;
//case 4: A.mid>A.low
//low = (mid+1)%N;
int FindRotationCount(int A[], int n)
{
    int low = 0, high = n-1;

    while(low<=high)
    {
        if (A[low]<=A[high])
            return low;

        int mid = (low+high)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if (A[mid]<=A[next] && A[mid]<=A[prev])
            return mid;

        if (A[mid]<=A[high])
            high = mid-1;
        else//if (A[mid]>A[low])
            low = mid+1;
    }
}

int binarySearchInRotatedArray(int A[], int n, int x)
{
    int low = 0, high = n - 1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(x==A[mid])
            return mid;

        if (A[low]<A[mid])
        {
            if (x>=A[low] && x<A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (x>A[mid] && x<=A[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}