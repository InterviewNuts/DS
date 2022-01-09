/**
 * @file BinarySearchTree.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<iostream>
using namespace std;

/*
    time complexeity = log(n)
    Base 2;
    Note:
        1) if there is more data insertion and deletion , then go for
        BST( Tree implemenation )
        otherwise if there is constant data & there is no or less insertion and eeltion, Binary serach with array implementation


*/


class Node
    {
    public:
        int data;
        Node* left, * right = nullptr;
        Node(int data) :data(data),left(nullptr),right(nullptr) {};
    };


Node* BST_Insert(Node* head, int data)
    {
    if (!head)
        return new Node(data);
    if (head->data < data)
        head->left = BST_Insert(head->left, data);
    else  if (head->data > data)
        head->right = BST_Insert(head->right, data);

    return head;
    }

void postOrder(Node* p)
    {
    if (p)
        {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << endl;
        }
    }

void preOrder(Node* p)
    {
    if (p)
        {
        cout << p->data << endl;
        preOrder(p->left);
        preOrder(p->right);
        }
    }
void inOrder(Node* p)
    {
    if (p)
        {
        inOrder(p->left);
        cout << p->data << endl;
        inOrder(p->right);
        }
    }

int main()
    {
    int n = 3, data;
    Node* root = nullptr;
    while (n--)
        {
        cout << "Please insert data to TREE = ";
        cin >> data;
        root = BST_Insert(root, data);
        }
    cout << " Calling inOrder of tree\n";
    inOrder(root);
    cout << " Calling preOrder of tree\n";
    preOrder(root);
    cout << " Calling postOrder of tree\n";
    postOrder(root);
    return 0;
    }