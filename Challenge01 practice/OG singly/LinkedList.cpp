#include <iostream>
#include "LinkedList.h"

using std::ostream;

// append node to the end of list
void LinkedList::append(int data)
{
    Node *current = new Node(data);     // Create new node with the `data`

    if (head == nullptr)    // if the list is empty...
    {
        head = current; 
    } 
    else
    {
        tail->next = current; 
    }
    tail = current;     // regardless, new tail = current.
}

void LinkedList::prepend(int data)
{
    Node *current = new Node(data);     // create new node with the `data`
    
    if (head == nullptr)        //if list empty
        tail = current;
    else
        current->next = head;   // prep forward link

    head = current;             // regardless, new head = current.
}

bool LinkedList::search(int data)
{
    Node *current = head;       // start at the head

    while (current != nullptr) // while current is not null
    {
        if (current->data == data) 
            return true;            //found data.

        current = current->next; //current now points to whatever's next from current
    }
    return false;   // escaped the loop without success
}

bool LinkedList::remove(int data)
{
    Node *current = head;       // Start at the head.
    Node *prev = nullptr;       // reference to allow for repairing links.

    while (current != nullptr)          //loop til exceeding the tail.
    {
        if (current->data == data)      // found data...
        {
            if (current == head)
            {
                head = current->next;   // new 'head' bc we're deleting pre-exsiting one.
            }
            else 
            {
                prev->next = current->next; //disconnect current node, repair forward link in preparation for delete.
            }

            if (current == tail)
            {
                tail = prev;            // new 'tail' bc we're deleting pre-existing one.
            }

            delete current;
            return true;
        }
        // didn't find 'data', move to next node.
        prev = current;             // bring 'prev' along for the ride...
        current = current->next;    // move forward to next node
    }
    return false; // escaped the loop without success, return failure
}

void LinkedList::display(ostream &os)
{
    Node *current = head; // start from the head

    while (current != nullptr) //stops when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next; //move forwards
    }
    os << "\n"; 
}

ostream &operator<<(ostream &os, LinkedList &right)
{
    right.display(os); //call the display method for the linkedlist
    return os;
}

//Destructor
LinkedList::~LinkedList()
{
    Node *current = head; // set current to head 

    while (current != nullptr)
    {
        head = head->next; //move head to the next node
        delete current;
        current = head;
    }

    tail = nullptr;
}
