#pragma once

struct rb_tree_node
{
   rb_tree_node* parent;
   rb_tree_node* left;
   rb_tree_node* right;
   int red;
   void* key;
   void* info;
};

struct rb_tree
{
   rb_tree_node* root;
   static rb_tree_node* nil;

   int (*Compare)(void*, void*);
   void (*Print)(void*);
};

rb_tree* RBTreeCreate(int (*CompFunc)(void*, void*),
                      void (*PrintFunc)(void*) );

void RightRotate(rb_tree* tree, rb_tree_node* x);

void LeftRotate(rb_tree*tree, rb_tree_node* x);

void BSTInsert(rb_tree* tree, rb_tree_node* x);

rb_tree_node* RBTreeInsert( rb_tree* tree, void* key, void* info );

rb_tree_node* RBTreeQuery(rb_tree* tree, void* key);

void PreorderPrint(rb_tree* tree, rb_tree_node* x);

void InorderPrint(rb_tree* tree, rb_tree_node* x);

void PostorderPrint(rb_tree* tree, rb_tree_node* x);

