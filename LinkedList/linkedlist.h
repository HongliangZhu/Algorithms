#pragma once
#include <iostream>

struct Node{
    int data;
    Node* next;
};

struct Node2{
    int data;
    Node2* prev;
    Node2* next;
};

Node* reverse(Node* head)
{
    Node* prev= nullptr;
    Node* cur = head;

    while(cur)
    {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
};

Node* recursiveReverse(Node* head)
{
    if(head==nullptr) return nullptr;
    if(head->next==nullptr) return head;//this is newHead.

    Node* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

void recursivePrint(Node* head)
{
    if(head==nullptr) return;
    recursivePrint(head->next);
    std::cout<<head->data<<" ";
}

Node* RemoveNode(Node* head, Node* node)
{
    if(head==nullptr) return head;
    if(head==node) return head->next;
        
    Node* prev = head;
    while(prev->next!=node)
    {
        prev = prev->next;
    }

    prev->next = prev->next->next;
    return head;
}

Node2* RemoveNode(Node2* head, Node2* node)
{
    if(node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        return head->next;
    }

    if(node->next)
    {
        node->next->prev = node->prev;
    }
    
    return head;
}

void RemoveNodeFromCircleList(Node2* nil, Node2* node)
{
    if(node==nil) return;

    node->prev->next = node->next;
    node->next->prev = node->prev;
}