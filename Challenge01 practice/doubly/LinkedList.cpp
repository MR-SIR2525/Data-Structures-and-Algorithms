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
    } else
    {
        tail->next = current;   // list wasn't empty so tail's 'next' is the new node.
        current->prev = tail;   // repair backward link.
    }
    tail = current; // regardless
}

void LinkedList::prepend(int data)
{
    Node *current = new Node(data);     // create new node with the `data`
    
    if (head == nullptr)    //if list empty
        tail = current;
    else
    {
        current->next = head; 
        head->prev = current;
    }

    head = current; //regardless
}

bool LinkedList::search(int data)
{
    Node *current = head; //set current current to head

    while (current != nullptr) // while current is not null
    {
        if (current->data == data) // if the data is stored in the current node...
            return true; // return success

        current = current->next; //current now points to whatever's next from current
    }
    return false; // escaped the loop without success, return failure
}

bool LinkedList::remove(int data)
{
    Node *current = head;       // Start with current pointing to 'head' 

    while (current != nullptr) // loop through list until finding data or reaching 'tail', a nullptr
    {
        if (current->data == data) // if we find specified 'data'... 
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
                
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            else 
            {
                tail = current->prev;
            }

            delete current;
            return true;
        }
        current = current->next; // move forward to the next node
    }
    return false; // escaped the loop without success, return failure
}

bool LinkedList::tailRemove(int data)
{
    Node *current = tail;

    while (current != nullptr) //aka we haven't fallen out of the list yet.
    {
        if (current->data == data)
        {
            if (current->prev != nullptr)
            {
                //node is not the head, need to repair previous node's forward link
                current->prev->next = current->next;
            } else 
            {
                //node is the head, update 'head' because active head is getting deleted...
                head = current->next;
            }

            if (current->next != nullptr)
            {
                //node is not the tail, need to repair the next node's backward link
                current->next->prev = current->prev;
            } else 
            {
                //node is tail, need to change 'tail' to be active tail's previous node.
                tail = tail->prev;
            }

            delete current;
            return true;
        }
        current = current->prev;
        
    }
    return false; // escaped the loop without success, return failure
}

void LinkedList::display(ostream &os)
{
    Node *current = head; // set current Node to the head

    while (current != nullptr) //stops when current hits 'tail'.
    {
        os << current->data << " ";
        current = current->next; //move forwards
    }
    os << "\n"; 
}

void LinkedList::tailDisplay(ostream &os) 
{
    Node* current = tail; // Start from the tail
    //ensure head has a null prev
    head->prev = nullptr;

    while (current != nullptr) 
    {
        os << current->data << " ";
        current = current->prev; // Move backwards
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
