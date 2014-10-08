#include "stdafx.h"
#include "red_black_tree.h"


rb_tree_node* rb_tree::nil=0;

rb_tree* RBTreeCreate( int (*CompFunc)(void*, void*),
                       void (*PrintFunc)(void*))
{
    rb_tree* tree = new rb_tree;
    tree->root = tree->nil;
    tree->Compare = CompFunc;
    tree->Print = PrintFunc;
    return tree;
}

void RightRotate( rb_tree* tree, rb_tree_node* x )
{
   rb_tree_node* y = x->left;
   x->left = y->right;
   if (y->right) 
      y->right->parent = x;
   
   y->parent = x->parent;
   if (x==x->parent->left) {
      x->parent->left = y;
   } 
   else { 
      x->parent->right = y;
   }

   y->right = x;
   x->parent = y;
}


void LeftRotate( rb_tree*tree, rb_tree_node* x )
{
   rb_tree_node* y = x->right;
   x->right = y->left;
   if (y->left)
      y->left->parent = x;

   if (x==x->parent->left){
      x->parent->left = y;
   } 
   else {
      x->parent->right = y;
   }

   y->parent = x->parent;
   x->parent = y;
   y->left = x; 
}


void BSTInsert( rb_tree* tree, rb_tree_node* x )
{
   x->left = x->right = tree->nil;
   rb_tree_node* y = tree->root;
   rb_tree_node* z = tree->root;

   while(y != tree->nil)
   {
      z = y;
      if(tree->Compare(x->key, y->key)<0 )
         y = y->left;
      else 
         y = y->right;
   }

   if( z == tree->nil )
   {
      tree->root = x;
   }
   else if( tree->Compare(x->key, z->key)<0 )
   {
      z->left = x;
   }
   else
   {
      z->right = x;
   }

   x->parent = z;
}


rb_tree_node* RBTreeInsert( rb_tree* tree, void* key, void* info )
{
   rb_tree_node* x = new rb_tree_node;
   x->left = x->right = x->parent = tree->nil;
   x->key = key;
   x->info = info;
   x->red = 1;

   BSTInsert(tree, x);

   rb_tree_node* ret = x;
   rb_tree_node* y = tree->nil;
   
   while(x->parent->red)
   {
      if(x->parent==x->parent->parent->left)
      {
         y = x->parent->parent->right;
         if(y->red)
         {
            x->parent->red = 0;
            y->red = 0;
            x->parent->parent->red = 1;
            x = x->parent->parent;
         }
         else
         {
            if(x==x->parent->right)
            {
               x = x->parent;
               LeftRotate(tree, x);
            }

            x->parent->red = 0;
            x->parent->parent->red = 1;
            RightRotate(tree, x->parent->parent);
         }
      }
      else
      {
         y = x->parent->parent->left;
         if(y->red)
         {
            y->red = 0;
            x->parent->red = 0;
            x->parent->parent->red = 1;
            x = x->parent->parent;
         }
         else
         {
            if(x==x->parent->left)
            {
               x = x->parent;
               RightRotate(tree, x);
            }

            x->parent->red = 0;
            x->parent->parent->red = 1;
            LeftRotate(tree, x->parent->parent);
         }
      }
   }

   tree->root->red = 0;
   return ret;
}

rb_tree_node* RBTreeQuery( rb_tree* tree, void* query )
{
    rb_tree_node* x = tree->root;
    int compVal;

    while( x != tree->nil && (compVal = tree->Compare(x->key, query)) != 0 )
    {
        x = (compVal==1)? x->left : x->right;
    }

    return  x;
}

void PreorderPrint(rb_tree* tree, rb_tree_node* x )
{
   if( x !=tree->nil )
   {
      tree->Print(x->info);
      PreorderPrint(tree,x->left);
      PreorderPrint(tree,x->right);
   }
}

void InorderPrint(rb_tree* tree, rb_tree_node* y )
{
   rb_tree_node* x = tree->root;
   if(x!=tree->nil)
   {
      InorderPrint(tree, x->left);
      tree->Print(x->info);
      InorderPrint(tree, x->right);
   }
}

void PostorderPrint(rb_tree* tree, rb_tree_node* y )
{
   rb_tree_node* x = tree->root;
   if(x!=tree->nil)
   {
      PostorderPrint(tree, x->left);
      PostorderPrint(tree, x->right);
      tree->Print(x->info);
   }
}
