#include <iostream>
#include <algorithm>    // for std::max()
#include "BST-AVL.h"
/* 
 * Public and private methods are arranged as:
 *
 * AVL::Private method {
 * }
 * AVL::Public method {
 * }
*/

int AVL::height(Node *node) 
{
    if (node == nullptr) 
        return -1;  // Height of a non-existent node is considered -1
    else 
    {
        // Compute the height of each subtree
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Use the larger one
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}


// Balance Factor
int AVL::BF(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}


bool AVL::insert(int data) {
    return insert(root, data);
}

bool AVL::insert(Node *&node, int data)
{
    bool success = false;
    if (node == nullptr)
    {
        node = new Node(data);
        return true;
    }
    if (data < node->data)
        success = insert(node->left, data);
    if (data > node->data)
        success = insert(node->right, data);
    if (!success)
        return false;

    node->height = std::max(height(node->left), height(node->right)) + 1;

    balance(node);

    return true;
}


bool AVL::remove(int data) {    // Public method
    return remove(root, data);
}

bool AVL::remove(Node *&node, int data)
{
    if (node == nullptr)
        return false;
    if (data < node->data)
        return remove(node->left, data);
    if (data > node->data)
        return remove(node->right, data);

    int deg = node->degree();
    if (deg == 0)
    {
        delete node;
        node = nullptr;
    }
    else if (deg == 1)
    {
        Node *tmp = node;
        if (node->left != nullptr)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        delete tmp;
    }
    else
    {
        Node *tmp = node->left;
        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }
        node->data = tmp->data;
        remove(node->left, tmp->data);
    }

    return true;
}


// counts the number of non-null children, returns it as degree
int Node::degree() const
{
    int deg = 0;
    if (left != nullptr) ++deg;     // If left child exists, increment degree
    if (right != nullptr) ++deg;    // If right child exists, increment degree

    return deg; // Return the total count of existing children
}


bool AVL::find(int data) {
    return find(root, data);
}

bool AVL::find(Node* node, int data) 
{
    if (node == nullptr) // If the node is nullptr, the search value is not found in the tree.
        return false;

    else if (data < node->data)
        // If the search value is less than the current node's data, search in the left subtree.
        return find(node->left, data);
    
    else if (data > node->data)
        // If the search value is greater than the current node's data, search in the right subtree.
        return find(node->right, data);
    else
        // The current node's data matches the search value.
        return true;
}


void AVL::rightRotate(Node * &node)
{
    Node *left = node->left;
    Node *hold = left->right;

    left->right = node;
    node->left = hold;
    node->height = std::max(height(node->left), height(node->right)) + 1;
    left->height = std::max(height(left->left), height(left->right)) + 1;
    node = left;
}


void AVL::leftRotate(Node * &node)
{
    Node *right = node->right;
    Node *hold = right->left;

    right->left = node;
    node->right = hold;
    node->height = std::max(height(node->left), height(node->right)) + 1;
    right->height = std::max(height(right->left),
                        height(right->right)) +
                    1;
    node = right;
}


void AVL::balance(Node * &node)
{
    int balance = BF(node);

    if (balance > 1)
    {
        if (BF(node->left) < 0)
            leftRotate(node->left);
        rightRotate(node);
    }

    if (balance < -1)
    {
        if (BF(node->right) > 0)
            rightRotate(node->right);
        leftRotate(node);
    }
}

/******************** Traversals ********************/

// Left-Node-Right (L-N-R)
void AVL::inOrder(ostream &os) {
    inOrder(root, os);  // Start the traversal from the root
}

// Left-Node-Right (L-N-R)
void AVL::inOrder(Node *node, ostream &os) 
{
    if (node != nullptr) 
    {
        inOrder(node->left, os);    // Visit left subtree
        os << node->data << " ";    // Visit node itself
        inOrder(node->right, os);   // Visit right subtree
    }
}


// Node-Left-Right (N-L-R)
void AVL::preOrder(ostream &os) {
    preOrder(root, os);     // Start the traversal from the root
}

// Node-Left-Right (N-L-R)
void AVL::preOrder(Node *node, ostream &os) {
    if (node != nullptr) {
        os << node->data << " ";    // Visit node itself first
        preOrder(node->left, os);   // Then, visit left subtree recursively
        preOrder(node->right, os);  // Finally, visit right subtree recursively
    }
}


// Left-Right-Node (L-R-N)
void AVL::postOrder(ostream &os) {
    postOrder(root, os);
}

// Left-Right-Node (L-R-N)
void AVL::postOrder(Node *node, ostream &os)
{
    if (node == nullptr)
        return;

    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data << " ";
}


/******************** Destructor ********************/
AVL::~AVL() {
    destroy(root);
}

void AVL::destroy(Node*& node) {
    if (node != nullptr) {
        destroy(node->left);    // Recursively destroy the left subtree
        destroy(node->right);   // Recursively destroy the right subtree
        delete node;        // Delete the current node
        node = nullptr;     // Set the node pointer to nullptr to avoid dangling pointers
    }
}