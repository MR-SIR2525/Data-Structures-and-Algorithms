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

void Queue::push(int data) //now append...
{
    Node *newnode = new Node(data);

    if (first == nullptr)
        first = newnode;
    else
        last->next = newnode;
    last = newnode;
}

bool Queue::pop()
{
    if (first == nullptr) return false;   //empty Queue, pop fails

    Node *current = first;
    first = first->next;    // set first to the node beneath itself, prep for delete
    
    if (first == nullptr)   //if list became empty
        last = nullptr;

    delete current;         //OG first deleted
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