/**
 * @file tree.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<iostream>
#include<exception>
using namespace std;

class Node
    {
    public:
        Node* lChild;
        int data;
        Node* rChild;
    };
class Queue
    {
    private:
        int qFront = -1, qRear = -1, qSize = 10;
        Node** Q;

    public:
        Node** getQueue()
            {
            return Q;
            }

        int getQueueSize()
            {
            return this->qRear;
            }
        Queue();
        Queue(int sz);
        void enqueue(Node* p);
        Node* dequeue();
        bool isEmpty() {
            return (qFront == qRear) ? true : false;
            }
        void print()
            {
            for (int i = 0; i <= this->qRear; i++)
                {
                cout << this->Q[i]->data << "\n";
                }
            }
    };

Queue::Queue() :qFront(-1), qRear(-1), qSize(10)
    {
    try {
        Q = new Node * [this->qSize];
        }
    catch (exception e)
        {
        cout << " Exception occured " << e.what() << endl;
        }
    }
Queue::Queue(int sz) :qFront(-1), qRear(-1), qSize(sz)
    {
    try {
        this->Q = new Node * [this->qSize];
        }
    catch (exception e)
        {
        cout << " Exception occured " << e.what() << endl;
        }
    }
void Queue::enqueue(Node* p)
    {
    if (this->qRear == this->qSize - 1)
        {
        cout << "Queue is full\n";
        return;
        }
    else
        {
        Q[++this->qRear] = p;
        }

    }
Node* Queue::dequeue()
    {
    if (this->qFront == this->qRear)
        {
        cout << "Queue is Empty\n";
        return nullptr;
        }
    else
        {
        Node* t = Q[++this->qFront];
        return t;
        }
    }



class Tree
    {
    private:
        Queue q;
        Node* root = nullptr;
    public:
    Node* getRoot(){return root;}
        Tree() :root(nullptr), q(100) {};
        void createTree();
        void preOrder(Node* r);
        void postOrder(Node* r);
        void inOrder(Node* r);
    };


void Tree::createTree()
    {
    Node* p = nullptr, * t = nullptr;
    int x;
    root = new Node();

    root->lChild = root->rChild = nullptr;
    cout << " Enter the value to he tree= " << "\n";
    cin >> x;
    if (x != -1)
        root->data = x;
    q.enqueue(root);

    while (!q.isEmpty())
        {
        p = q.dequeue();
        cout << " Enter the value for the Left child tree= " << "\n";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->lChild = t->rChild = nullptr;
            q.enqueue(t);
            p->lChild = t;
            }
        cout << " Enter the value for the Right child tree= " << "\n";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->lChild = t->rChild = nullptr;
            q.enqueue(t);
            p->rChild = t;
            }
        }
    }

void Tree::preOrder(struct Node* p)
    {
    if (p)
        {

        cout << p->data << endl;
        preOrder(p->lChild);
        preOrder(p->rChild);
        }
    }
void Tree::inOrder(struct Node* p)
    {
    if (p)
        {

        inOrder(p->lChild);
        cout << p->data << endl;
        inOrder(p->rChild);
        }
    }
void Tree::postOrder(struct Node* p)
    {
    if (p)
        {
        postOrder(p->lChild);
        postOrder(p->rChild);
        cout << p->data << endl;
        }
    }



int masin()
{

    Tree *rootTree=new Tree();
    rootTree->createTree();
    rootTree->inOrder(rootTree->getRoot());

    return 0;
}