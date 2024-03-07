/**
 * @file main.cpp
 * @author Andrew Blythe (cab1361)
 * @brief Challenge01 - Singly Linked List being converted to a doubly linked list + test operations.
 * @date 2024-02-15
 */
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;


int main()
{
    LinkedList LL;
    

    // Example Testing Code:
    LL.append(5);
    LL.append(33);
    LL.append(1);
    LL.append(7);
    LL.append(33);
    LL.append(12);
    LL.display( cout );
    LL.remove(33);
    LL.display( cout );
    LL.prepend(12);
    LL.display( cout );
    LL.remove(13);
    LL.display( cout );
    // LL.tailDisplay( cout );  // for doubly linked list
    // LL.tailRemove( 12 );     // for doubly linked list
    LL.display( cout );
    
    
    return 0;
}

/*
    1. Implement a singly linked list.
    2. Demonstrate working singly linked list with the example operations.
    3. Modify it into a doubly linked list.
    4. tailDisplay() and tailRemove()
 */