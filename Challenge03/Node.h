class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;

    Node(): 
        data(0), height(0), left(nullptr), right(nullptr) 
    {}
    Node(int data): 
        data(data), height(0), left(nullptr), right(nullptr) 
    {}
    
    int degree() const;
};
