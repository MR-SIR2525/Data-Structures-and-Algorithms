# pragma once
#include "Node.h"
#include <iostream> //for ostream

class Stack
{
    private:
        Node *top;

    public:
        Stack():
            top(nullptr)
        {}
        ~Stack();

        void push(int data);
        bool pop();
        bool peek(int &data);
        void display(std::ostream &os);
};