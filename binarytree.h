#pragma once
#include "tree_defs.h"
#include <stack>
#include <iostream>

void PreorderTraversal(Node* root)
{
    if (root==nullptr)
        return;

    std::stack<Node*> stack;
    stack.push(root);
    Node* current;

    while(!stack.empty())
    {
        current = stack.top();
        cout<<current->data<<" ";
        stack.pop();

        if(current->right) stack.push(current->right);
        if(current->left) stack.push(current->left);
    }
}


void InOrderTraversal(Node* root)
{
    if (root==nullptr)
        return;

    std::stack<Node*> stack;
    Node* node=root;

    while(!stack.empty() || node!=nullptr)
    {
        if(node!=nullptr)
        {
            stack.push(node);
            node = node->left;
        }
        else
        {
            node = stack.top();
            stack.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
}

void PostOrderTraversal(Node* root)
{
    std::stack<Node*> stack;
    Node* node=root;
    stack.push(node);

    bool returning = false;
    while(!stack.empty())
    {
        if(node)
        {
            if(!returning)
            {
                if(node->right) stack.push(node->right);
                if(node->left) stack.push(node->left);
                node = node->left? node->left:node->right;
            }
            else if(stack.top()->left==node||stack.top()->right==node)
            {
                node = stack.top();
                cout<<node->data<<" ";
                stack.pop();
            }
            else
            {
                node = stack.top();
                returning = false;
            }
        }
        else
        {
            node = stack.top();
            cout<<node->data<<" ";
            stack.pop();
            returning = true;
        }
    }
}

void PostOrderTraversal2(Node* root)
{
    std::stack<Node*> stack;
    Node* node=root;
    stack.push(node);

    bool returning = false;
    while(!stack.empty())
    {
        if(node==nullptr || returning)
        {
            if(stack.top()->left!=node && stack.top()->right!=node)
            {
                returning = false;
            }
            else
            {
                node = stack.top();
                cout<<node->data<<" ";
                stack.pop();
                returning=true;
            }
        }
        else
        {
            if(node->right) stack.push(node->right);
            if(node->left) stack.push(node->left);
            node = node->left? node->left:node->right;
        }
    }
}

void PostorderTraverser2(Node* root)
{
    if(root==nullptr) return;

    std::stack<Node*> stack;
    Node* node = root;
    Node* lastprinted = nullptr;

    while(!stack.empty() || node)
    {
        if(node==lastprinted && node==stack.top()->right)
        {
            lastprinted = node = stack.top();
            std::cout<<node->data<<" ";
            stack.pop();
        }
        else if(node)
        {
            if(node->right)
            {
                node = node->right;
                stack.push(node);
            }
            if(node->left)
            {
                node = node->left;
                stack.push(node);
            }
        }
        else//node==null, arrived at leaf
        {
            lastprinted = node = stack.top();
            std::cout<<node->data<<" ";
            stack.pop();
        }
    }


}