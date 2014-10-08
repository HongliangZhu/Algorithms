#pragma once

int binarySearch(int * s, int len, int key)
{
    //binary search consider len==0
    //while quick sort consider len<=0
    if(len==0)
        return -1;

    int half = len/2;

    if(s[half]==key)
    {
        return half;
    }
    else if(key < s[half])
    {
        binarySearch(s, half, key);
    }
    else
    {
        binarySearch(s+half+1, len-half-1, key);
    }
}