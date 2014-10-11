#pragma once
#include "tree_defs.h"

#ifndef NULL
#define NULL 0
#endif

Node* Search(Node* root, int key)
{
    return ;
}

Node* Delete(Node* root, int key)
{
    //find the node
    Node* pToDel = root;
    Node* pToDelParent = NULL;

    while(pToDel!=NULL && pToDel->data!=key)
    {
        if(key < pToDel->data)
            pToDel = pToDel->left;
        else
            pToDel = pToDel->right;
        pToDelParent = pToDel;
    }

    //if not found
    if(pToDel==NULL)
        return NULL;

    if(pToDel->left==NULL)
}