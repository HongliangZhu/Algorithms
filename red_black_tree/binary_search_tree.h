#pragma once


struct tree_node
{
    tree_node* left;
    tree_node* right;
    tree_node* parent;
    int        key;
    void*      info;
};


class binary_search_tree
{
public:
    binary_search_tree(){};
    ~binary_search_tree(){};

    tree_node* Minimum(tree_node* x);
    tree_node* Successor(tree_node* x);
    tree_node* Delete(tree_node* x);

    tree_node* root;
};