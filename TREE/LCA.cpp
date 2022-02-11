/**
 * @file LCA.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<iostream>
using namespace std;

class Node
    {
    public:
        int data;
        Node* left, * right = nullptr;
        Node(int data) :data(data), left(nullptr), right(nullptr) {};
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