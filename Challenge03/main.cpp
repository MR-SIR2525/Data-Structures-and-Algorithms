/* Challenge 03 - Binary Search Tree
 * Author: Andrew Blythe (cab1361)
 * Date: 2024-3-30
 * 
 * Instructions: 
 * Write a program that implements a BST derived from the code provided in class.
 *  - demonstrate a working BST with the example function calls
 *  - delete and then retype the deletion method from memory
*/
#include <iostream>
#include "BST.h"

using namespace std;

int main() {

    BST b;

    b.insert(56);
    b.insert(34);
    b.insert(70);
    b.insert(5);
    b.insert(1);
    b.insert(42);
    b.insert(40);
    b.insert(52);
    b.insert(62);
    b.insert(57);
    b.insert(89);
    b.insert(90);
    cout << b.find(44) << "\n";
    cout << b.find(62) << "\n";

    b.remove(62);
    cout << b.find(62) << "\n";

    b.insert(44);
    cout << b.find(44) << "\n";

    b.postOrder(cout);
    b.preOrder(cout);
    b.inOrder(cout);
}