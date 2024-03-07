#include "Queue.h"

Queue::~Queue()
{
    Node *tmp = top;

    while (tmp != nullptr)  //hits nullptr when Queue is no more
    {
        top = top->next;
        delete tmp;
        
        tmp = top;
    }
    top = nullptr;
}

void Queue::push(int data)
{
    Node *newnode = new Node(data);
    newnode->next = top;
    top = newnode;
}

bool Queue::pop()
{
    Node *tmp = top;

    if (top == nullptr) return false;   //empty Queue, pop fails
    
    top = top->next;    // set top to the node beneath itself
    delete tmp;         //OG top deleted
    return true;
}

bool Queue::peek(int &data)
{
    if (top == nullptr) return false;   //Queue empty, can't peek
    data = top->data;
    return true;
}

void Queue::display(std::ostream &os)
{
    Node *current = top;      // start from the top

    while (current != nullptr)      //stops when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next;    //move forwards
    }
    os << "\n"; 
}