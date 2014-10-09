#pragma once

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
}
