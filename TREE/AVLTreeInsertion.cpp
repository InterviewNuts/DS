#include<iostream>
using namespace std;

class Node
    {
    public:
        Node* left = nullptr;
        int data;
        Node* right = nullptr;
        int height = 1;
        Node() = default;
        Node(int d)
            {
            this->data = d;
            this->left = nullptr;
            this->right = nullptr;
            //! Initially the height of the node =1;
            this->height = 1;
            }

    };

int height(Node* p)
    {
    if (p == nullptr)
        return 0;
    else
        return p->height;
    }

int max(int a, int b)
    {
    return (a > b) ? a : b;
    }

Node* rightRotate(Node* p)
    {
    Node* temp = p->left;
    p->left = temp->right;
    temp->right = p;

    p->height = 1 + max(height(p->left), height(p->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));
    // Return new root  
    return temp;
    }

Node* leftRotate(Node* p)
    {
    Node* temp = p->right;
    p->right = temp->left;
    temp->left = p;

    p->height = 1 + max(height(p->left), height(p->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));
    return temp;
    }

int getNodeBalance(Node* p)
    {
    if (p == nullptr)
        return 0;
    return (height(p->left) - height(p->right));
    }

//! Now take the Rotaion for the unbalanced node
//! There will 4 types of rotation
//! 1. left - left case ( Here Right  Rotation will be taking care as It is left heavy)
//!     /
//     /
//    /
//! 2. right - right case ( Here Left  Rotation will be taking care as It is Right heavy)
//!     \
//!      \
//!       \
//!  
//! 3. left - right case ( Here Right  Rotation will be taking care as It is left heavy)
//!     /
//     /\
//    /  \
//! 4. right - left case ( Here Left  Rotation will be taking care as It is Right heavy)
//!     \
//!     /\
//!    /  \
//!    
//! we can notive  if the balance factor is -1,-2 then it is right heavt , oterwise it is positive , then left heavy
//! otherwise it is 0 means Balanced.

Node* insert(Node* p, int data)
    {
    if (p == nullptr)
        {
        p = new Node(data);
        return p;
        }

    if (data < p->data)
        p->left = insert(p->left, data);
    else if (data > p->data)
        p->right = insert(p->right, data);
    else// Equal keys are not allowed in BST 
        return p;

    //! Now take the height of the Node
    // p->height = 1 + max(height(p->left), height(p->right));

    /* 2. Update height of this ancestor node */
    p->height = 1 + max(height(p->left), height(p->right));

    //! Now take the Balance Factor of the node.
    int balance = getNodeBalance(p);

    //! case 1 left - left and right rotation 
    if ((balance > 1) && (data < p->left->data))
        {
        return rightRotate(p);
        }
    //! case 2 right - right and left rotation
    if ((balance < -1) && (data > p->right->data))
        {
        return leftRotate(p);
        }
    //! case 3 left - right and left rotation and then right rotation
    if ((balance > 1) && (data > p->left->data))
        {
        p->left = leftRotate(p->left);
        return rightRotate(p);
        }
    //! case 4 right - left and right rotation and then left rotation
    if ((balance < -1) && (data < p->right->data))
        {
        p->right = rightRotate(p->right);
        return leftRotate(p);
        }
    return p;

    }
void preOrder(Node* root) {
    if (root != nullptr)
        {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
        }
    }
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root);

    return 0;
    }