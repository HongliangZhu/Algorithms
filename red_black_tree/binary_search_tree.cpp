#include "StdAfx.h"
#include "binary_search_tree.h"




//! 
/** Step1. 确定要删除的结点y. 
 *  Step2. 确定结点y的子女x.
 *  Step3. 删除y(链接x与y的父节点)
 *  Step4. 复制 satellite data
 *	@param tree_node * z
 *	@return 
 *	@note 
 */
tree_node* binary_search_tree::Delete( tree_node* z )
{
    tree_node* y; // the node to be deleted
    if(z->left==NULL || z->right==NULL)
        y = z;
    else
        y = Successor(z);

    tree_node* x; // the only child node of the node to be deleted
    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if(x!=NULL)
        x->parent = y->parent;

    if (y->parent==NULL)
        root = x;
    else
    {
        if (y==y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    if(y!=z)
       z->key = y->key, z->info = y->info;
    
    return y;
}

tree_node* binary_search_tree::Successor( tree_node* x )
{
    if(x->right)
        return Minimum(x->right);

    while (x->parent && x == x->parent->right)
    {
        x = x->parent;
    }

    return x->parent;
}

tree_node* binary_search_tree::Minimum( tree_node* x )
{
    while (x->left)
    {
        x = x->left;
    }

    return x;
}
