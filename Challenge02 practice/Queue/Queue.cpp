#include "Queue.h"
#include <ostream>

Queue::~Queue()
{
    Node *current = first;

    while (current != nullptr)  //hits nullptr when Queue is no more
    {
        first = first->next;   //'first' is now the next node 
        delete current;            //OG node deleted
        current = first;           //move to next node
    }
    first = last = nullptr;     //ensure front and rear are nullptr's
}

void Queue::push(int data) // enqueue/append
{   
    Node* newNode = new Node(data);

    if (first == nullptr)   // Queue is empty
        first = newNode;
    else 
        last->next = newNode;

    last = newNode;
}

bool Queue::pop()
{
    if (first == nullptr) return false;   //Queue empty, pop fails

    Node *current = first;
    first = first->next;

    if (first == nullptr) last = nullptr; // Queue became empty

    delete current;
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
    Node *current = first;      // start from the top

    while (current != nullptr)      //stops when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next;    //move forwards
    }
    os << "\n"; 
}