#pragma once

#define NULL 0

struct BinTree
{
    BinTree(): parent(NULL), left(NULL), right(NULL), key(0)
    {
    }

    BinTree* parent;
    BinTree* left;
    BinTree* right;
    int      key;
};


BinTree* left(BinTree*);
BinTree* right(BinTree*);
BinTree* parent(BinTree*);
int  key(BinTree*);


BinTree* tree_minimum(BinTree* tree);
BinTree* tree_maximum(BinTree* tree);
BinTree* tree_successor(BinTree* tree);
BinTree* tree_predecessor(BinTree* tree);