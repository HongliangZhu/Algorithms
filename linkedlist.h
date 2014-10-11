#pragma once
#include <iostream>

struct Node{
    int data;
    Node* next;
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