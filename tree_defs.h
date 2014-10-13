#pragma once


struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct Node2 : public Node
{
    Node2* parent;
};