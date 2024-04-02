#pragma once
#include <iostream>
#include "Node.h"

using std::ostream;

class BST
{
private:
    Node *root;

    int height(Node *node);
    int BF(Node *node);
    void rightRotate(Node *&node);
    void leftRotate(Node *&node);
    void balance(Node *&node);

    bool insert(Node *&node, int data);
    bool remove(Node *&node, int data);
    bool find(Node *node, int data);
    void inOrder(Node *node, ostream &os);
    void preOrder(Node *node, ostream &os);
    void postOrder(Node *node, ostream &os);
    void destroy(Node *&node);

public:
    BST(): 
        root(nullptr) 
    {}
    ~BST();
    
    bool insert(int data);
    bool remove(int data);
    bool find(int data);
    void inOrder(ostream &os);
    void preOrder(ostream &os);
    void postOrder(ostream &os);
};
