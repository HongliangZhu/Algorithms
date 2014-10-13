#include <assert.h>  
#include "bintree_search.h"

BinTree* left( BinTree* node)
{
    return node->left;
}

BinTree* right( BinTree* node)
{
    return node->right;
}

BinTree* parent( BinTree* node)
{
    return node->parent;
}

int key( BinTree* node)
{
    return node->key;
}

BinTree* tree_minimum( BinTree* tree )
{
    while(left(tree) != NULL)
        tree = tree->left;

    return tree;
}

BinTree* tree_maximum( BinTree* tree )
{
    while(right(tree) != NULL)
        tree = tree->left;

    return tree;
}

BinTree* tree_successor( BinTree* tree )
{
    if (!tree)
    {
        assert(false);
        throw "invalid arguments";
    }

    if (right(tree))
    {
        return tree_minimum(tree);
    }

    BinTree* y = parent(tree);
    while( y && tree == right(y) )
    {
        tree = y;
        y = parent(tree);
    }

    return y;
}

BinTree* tree_predecessor( BinTree* tree )
{
    if( left(tree) )
    {
        return tree_maximum(tree);
    }

    BinTree* y = parent(tree);
    while( y && tree == left(y) )
    {
        tree = y;
        y = parent(tree);
    }

    return y;
}

