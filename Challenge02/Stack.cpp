#include "Stack.h"

Stack::~Stack()
{
    Node *tmp = top;

    while (tmp != nullptr)  //hits nullptr when stack is no more
    {
        top = top->next;
        delete tmp;
        
        tmp = top;
    }
    top = nullptr;
}

void Stack::push(int data)
{
    Node *newnode = new Node(data);
    newnode->next = top;
    top = newnode;
}

bool Stack::pop()
{
    Node *tmp = top;

    if (top == nullptr) return false;   //empty stack, pop fails
    
    top = top->next;    // set top to the node beneath itself
    delete tmp;         //OG top deleted
    return true;
}

bool Stack::peek(int &data)
{
    if (top == nullptr) return false;   //stack empty, can't peek
    data = top->data;
    return true;
}

void Stack::display(std::ostream &os)
{
    Node *current = top;      // start from the top

    while (current != nullptr)      //stops when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next;    //move forwards
    }
    os << "\n"; 
}