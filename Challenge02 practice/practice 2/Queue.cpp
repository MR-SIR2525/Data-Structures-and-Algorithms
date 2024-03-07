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

void Queue::push(int data) //append
{
    Node *newnode = new Node(data);     //new node with the given data

    if (first == nullptr)
        first = newnode;
    else 
        last->next = newnode;

    last = newnode;
}

bool Queue::pop() //delete the first node
{
    Node *tmp = first;

    if (first == nullptr) return false;   //empty Queue, pop fails
    
    first = first->next;        // set first to the node beneath itself
    if (first == nullptr) last = nullptr; // Queue became empty

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

    while (current != nullptr)      //stops when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next;    //move forwards
    }
    os << "\n"; 
}