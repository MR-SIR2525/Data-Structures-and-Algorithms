#include "Queue.h"

Queue::~Queue()
{
    Node *tmp = first;

    while (tmp != nullptr)  //hits nullptr when Queue is no more
    {
        first = first->next;
        delete tmp;
        
        tmp = first;
    }
    first = last = nullptr;
}

void Queue::push(int data)
{
    Node *newnode = new Node(data);
    newnode->next = first;
    first = newnode;
}

bool Queue::pop()
{
    Node *tmp = first;

    if (first == nullptr) return false;   //empty Queue, pop fails
    
    first = first->next;    // set first to the node beneath itself
    delete tmp;         //OG first deleted
    return true;
}

bool Queue::peek(int &data)
{
    if (first == nullptr) return false;   //Queue empty, can't peek
    data = first->data;
    return true;
}

void Queue::display(std::ostream &os)
{
    Node *current = first;      // start from the first

    while (current != nullptr)      //sfirsts when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next;    //move forwards
    }
    os << "\n"; 
}