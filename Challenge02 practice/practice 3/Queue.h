# pragma once
#include "Node.h"
#include <iostream> //for ostream

class Queue
{
    private:
        Node *top;

    public:
        Queue():
            top(nullptr)
        {}
        ~Queue();

        void push(int data);
        bool pop();
        bool peek(int &data);
        void display(std::ostream &os);
};