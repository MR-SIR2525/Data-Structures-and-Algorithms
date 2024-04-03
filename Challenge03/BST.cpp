#include <iostream>
#include <algorithm>    // for std::max()
#include "BST.h"


int BST::height(Node *node) 
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
int BST::BF(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}


bool BST::insert(int data) {
    return insert(root, data);
}

bool BST::insert(Node *&node, int data)
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


bool BST::remove(int data) {    // Public method
    return remove(root, data);
}

bool BST::remove(Node *&node, int data)
{
    // Base case: If current node is nullptr, data isn't found; return false.
    if (node == nullptr)
        return false;

    // If data to remove is less than current node's data, search in left subtree.
    if (data < node->data)
        return remove(node->left, data);

    // If data to remove is greater than current node's data, search in right subtree.
    if (data > node->data)
        return remove(node->right, data);

    //if node->data == data
        //proceed...

    // Calculate the degree (number of children) of the node to be removed.
    int deg = node->degree();

    // Case 1: Node is a leaf (degree 0). Delete the node and set the pointer to nullptr.
    if (deg == 0)
    {
        delete node;
        node = nullptr;
    }
    // Case 2: Node has one child (degree 1). Replace node with its single child then delete.
    else if (deg == 1)
    {
        Node *current = node;

        // Determine which child exists, it is now the new node.
        node = (node->left != nullptr) ? node->left : node->right;
        delete current;     // Delete the original node with pointer you made.
    }
    // Case 3: Node has two children (degree 2).
    else 
    {
        // Find the in-order predecessor
        Node *current = node->left;         //Step 1: go to left child
        while (current->right != nullptr)   //Step 2: go down, right to find next largest number
        {
            current = current->right; //Step 2 (cont): Progress further down & right to find leaf
        }

        // Replace node-to-be-removed's data with its in-order predecessor's data.
        node->data = current->data;
        
        // node with data to remove has been overwritten, now remove the source of the overwrite.
        //with a new remove call with updated data.
        remove(node->left, current->data);
    }

    // If the function reaches this point, the node has been successfully removed.
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


bool BST::find(int data) {
    return find(root, data);
}

bool BST::find(Node* node, int data) 
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


void BST::rightRotate(Node * &node)
{
    Node *left = node->left;
    Node *hold = left->right;

    left->right = node;
    node->left = hold;
    node->height = std::max(height(node->left), height(node->right)) + 1;
    left->height = std::max(height(left->left), height(left->right)) + 1;
    node = left;
}


void BST::leftRotate(Node * &node)
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


void BST::balance(Node * &node)
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
void BST::inOrder(ostream &os) {
    os << "In-Order: ";
    inOrder(root, os);  // Start the traversal from the root
    os << "\n";
}

// Left-Node-Right (L-N-R)
void BST::inOrder(Node *node, ostream &os) 
{
    if (node != nullptr) 
    {
        inOrder(node->left, os);    // Visit left subtree
        os << node->data << " ";    // Visit node itself
        inOrder(node->right, os);   // Visit right subtree
    }
}


// Node-Left-Right (N-L-R)
void BST::preOrder(ostream &os) {
    os << "Pre-Order: ";
    preOrder(root, os);     // Start the traversal from the root
    os << "\n";
}

// Node-Left-Right (N-L-R)
void BST::preOrder(Node *node, ostream &os) {
    if (node != nullptr) {
        os << node->data << " ";    // Visit node itself first
        preOrder(node->left, os);   // Then, visit left subtree recursively
        preOrder(node->right, os);  // Finally, visit right subtree recursively
    }
}

// Left-Right-Node (L-R-N)
void BST::postOrder(ostream &os) {
    os << "Post-Order: ";
    postOrder(root, os);
    os << "\n";
}

// Left-Right-Node (L-R-N)
void BST::postOrder(Node *node, ostream &os)
{
    if (node == nullptr)
        return;

    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data << " ";
}


/******************** Destructor ********************/
BST::~BST() {
    destroy(root);
}

void BST::destroy(Node*& node) {
    if (node != nullptr) {
        destroy(node->left);    // Recursively destroy the left subtree
        destroy(node->right);   // Recursively destroy the right subtree
        delete node;        // Delete the current node
        node = nullptr;     // Set the node pointer to nullptr to avoid dangling pointers
    }
}