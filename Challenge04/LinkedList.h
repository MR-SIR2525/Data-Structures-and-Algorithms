#pragma once
#include <iostream> //for ostream
// #include "Node.h"

class LinkedList 
{
private:
    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(): 
            data(0), next(nullptr), prev(nullptr)
        {}

        Node(int data): 
            data(data), next(nullptr), prev(nullptr)
        {}
        
        Node(int data, Node *next, Node *prev): 
            data(data), next(next), prev(prev)
        {}
    };

    Node *head;
    Node *tail;
    

    public:
        LinkedList(): head(nullptr), tail(nullptr) { }
        ~LinkedList();

        void append(int data);
        void prepend(int data);
        bool search(int data);
        bool remove(int data);
        bool tailRemove(int data);

        void display(std::ostream &os);
        void tailDisplay(std::ostream &os);

        friend std::ostream &operator<<(std::ostream &os, LinkedList &right); 
};