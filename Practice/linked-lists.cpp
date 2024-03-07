#include <iostream>
#include <iomanip>
#include <string>


using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Node 
{
    public:
        int data;
        Node *next;

        Node(): data(0), next(nullptr) {}
        Node(int data): data(data), next(nullptr) {}
        Node(int data, Node *next): data(data), next(next){}
};

class LinkedList
{
    private:
        Node *head;
        Node *tail;

    public:
        LinkedList(): head(nullptr), tail(nullptr) {}
        ~LinkedList();

        void append(int data)
        {
            Node *current = new Node(data); // create new node

            if (head == nullptr) // check if list is empty
            {
                head = current; // if so, set head to the new Node
            }
            else
            {
                tail->next = current;
            }

            tail = current; // move tail to the new Node
        }

        void prepend(int data)
        {
            Node *current = new Node(data); // create new node
            
            if (head == nullptr) // check if list is empty
            {
                tail = current; // if so, set tail to the new Node
            }

            current->next = head; // set new Node's next to head
            
            head = current; // move head to the new Node
        }

        bool search(int data)
        {
            Node *current = head; //set current current to head

            while (current != nullptr) // while current is not null
            {
                if (current->data == data) // if the data is stored in the current node...
                    return true; // return success

                current = current->next; //current now points to whatever's next from current

                return false; // if the loop ends without success, return failure
            }
        }

        bool remove(int data)
        {
            Node *current = head; //set the current current node to the head
            Node *prev = nullptr; // set the prev node's value to nullptr
                                  //the head doesn't have a previous node

            while (current != nullptr) // loop while current is still in the list
            {
                if (current->data == data) // if the data is stored in the current node, delete that node
                {
                    if (current == head) // check to see if we are deleting the head
                    {
                        head = current->next; //set head to the next node in the chain
                    }
                    else 
                    {
                        prev->next = current->next; //set the previous node's next to the next node in the chain
                    }

                    if (current = tail)
                    {
                        tail = prev;
                    }

                    delete current;
                    return true;
                }   
                prev = current;
                current = current->next;
            }
        }

        void display(ostream &os)
        {
            Node *current = head; // set current Node to the head

            while (current != nullptr)
            {
                os << current->data << "endl"; //output data stored in current node

                current = current->next; //move current to the next node
            }
        }

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
        friend ostream &operator<<(ostream &os, LinkedList &right)
        {
            right.display(os); //call the display method for the linkedlist
            return os;
        }

};

int main() {

    

    return 0;
}