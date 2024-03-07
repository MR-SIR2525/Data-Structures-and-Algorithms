#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int data): data(data), next(nullptr) {}

    Node(int data, Node *next): data(data), next(next) {}
    //is this all of it..?
};


int main()
{



    int myVariable = 42;
    int *myPointer = &myVariable;

    // address is printed
    cout << myPointer << "\n";
    cout << &myVariable << "\n";

    // value is printed
    cout << *myPointer << "\n";
    cout << myVariable << "\n";

    // how to delete pointer?

    // hold user until they press any key
    cout << "\nPress ENTER to exit...\n";
    cin.get();

    return 0;
}
