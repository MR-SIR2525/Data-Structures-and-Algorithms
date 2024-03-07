#pragma once
#include <iostream> //for ostream
#include "Node.h"

class LinkedList {
    private:
        Node *head;
        Node *tail;

    public:
        LinkedList(): head(nullptr), tail(nullptr) { }
        ~LinkedList();

        void append(int data);
        void prepend(int data);
        bool search(int data);
        bool remove(int data);
        // bool tailRemove(int data);

        void display(std::ostream &os);
        // void tailDisplay(std::ostream &os);

        friend std::ostream &operator<<(std::ostream &os, LinkedList &right); 
};
