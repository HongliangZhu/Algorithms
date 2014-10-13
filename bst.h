#pragma once
#include "tree_defs.h"

#include <stack>

#ifndef NULL
#define NULL 0
#endif

Node* Search(Node* root, int key)
{
    return ;
}

Node* FindMiniValue(Node* root)
{
    if(root==nullptr) return nullptr;

    while(root->left)
        root = root->left;
    return root;
}

Node* Successor(Node2* node)
{
    if(node==nullptr) return nullptr;

    if(node->right)
    {
        return FindMiniValue(node->right);
    }

    Node2* parent = node->parent;
    while(parent && parent->right == node)
    {
        node = parent;
        parent = node->parent;
    }

    return parent;
}

Node* Successor(Node* root, Node* node)
{


}



Node* Delete(Node* root, int key)
{
    //find the node
    Node* node = root;
    Node* nodeParent = NULL;

    while(node!=NULL && node->data!=key)
    {
        if(key < node->data)
            node = node->left;
        else
            node = node->right;
        nodeParent = node;
    }

    //if not found
    if(node==NULL)
        return NULL;

    if(node->left==NULL)
}