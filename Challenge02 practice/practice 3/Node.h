#pragma once

class Node
{
    public:
        int data;
        Node *next;

        Node(): 
            data(0), next(nullptr)
        { }
        Node(int data): 
            data(data), next(nullptr)
        { }
        Node(int data, Node *next):
            data(data), next(next)
        { }
};