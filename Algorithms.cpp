// Algorithms.cpp : Defines the entry point for the console application.
//

#include "quicksort.h"
#include "binarytree.h"
#include <iostream>
#include <time.h>
using namespace std;

int coins[3] = {4,10,25};
int coinsnum = 3;

void makechange(int money)
{
    unsigned* m = new unsigned[money+1];
    m[0] = 0;
    for (int i=1; i<=money; ++i)
    {
        m[i] = 0xFFFFFFFE;
    }

    for(int i=1; i<=money; ++i)
    {
        int coin = 0;
        int lastsum = 0;
        for(int j=0; j<coinsnum; ++j)
        {
            if(coins[j]<=i && m[i-coins[j]]+1<m[i])
            {
                m[i] = m[i-coins[j]] + 1;
                lastsum = i-coins[j];
                coin = coins[j];
            }
        }

        cout<<"i:"<<i<<"=\t"<<lastsum<<"+\t"<<coin<<"\n";
    }

    for (int i=0 ;i<=money; ++i)
    {
        cout<<i<<"\t"<<m[i]<<"\n";
    }

    delete []m;
}

void NonDecreasingSeqence(int seq[], int len)
{
    //Initialize sub-state[]
    int* S = new int[len];
    for (int i=0; i<len; ++i)
    {
        S[i] = 1;
    }

    for(int i=0; i<len; ++i)
    {
        int jj = 0;
        for(int j=0; j<i; ++j)
        {
            if(seq[j]<=seq[i] && S[j]+1>S[i] )
            {
                S[i] = S[j] + 1;
                jj = j;
            }
        }

        cout<<i<<"\t"<<seq[i]<<"\t"<<jj<<"\t"<<S[jj]<<"\t"<<S[i]<<endl;
    }

    delete []S;
}

void maxcollection(int g[][5], int r, int c)
{
    int** s = new int*[r];
    for(int i=0; i<r; ++i)
    {
        s[i] = new int[c];
        for (int j=0; j<c; ++j)
            s[i][j] = 0;
    }

    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            int ii = max(0, i-1);
            int jj = max(0, j-1);

            if(s[ii][j]>s[i][jj])
                s[i][j] = s[ii][j] + g[i][j];
            else
                s[i][j] = s[i][jj] + g[i][j];

            cout<<s[i][j]<<"\t";
        }

        cout<<endl;
    }

    for(int i=0; i<r; ++i)
        delete []s[i];
    delete []s;
}


int main(int argc, char* argv[])
{
    //IsOptimized();
    //test_quicksort();

    //makechange(61);

    //int s[6] = {5, 3, 4, 8, 6, 7};
    //NonDecreasingSeqence(s, 6);

    //srand(time(NULL));
    //int g[5][5];
    //for (int i=0; i<5; ++i)
    //{
    //    for(int j=0; j<5; ++j)
    //    {
    //        g[i][j] = rand()%6;
    //        cout<<g[i][j]<<"\t";
    //    }
    //    cout<<endl;
    //}
    //cout<<endl;
    //maxcollection(g, 5, 5);
	return 0;
}