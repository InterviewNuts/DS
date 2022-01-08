/**
 * @file createTreeWithHelpOfQueue.cpp
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
        Node* getRoot() { return root; }
        Tree() :root(nullptr), q(100) {};
        void createTree();
        void preOrder(Node* r);
        void postOrder(Node* r);
        void inOrder(Node* r);
    };


void Tree::createTree()
    {
    // Queue q(100);
    Node* p = nullptr, * t = nullptr;
    int x;
    cout << "Eneter root value ";
    cin >> x;
    root = new Node();
    root->data = x;
    root->lChild = root->rChild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty())
        {
        p = q.dequeue();
        cout << "eneter left child of "<< p->data <<" ";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->data = x;
            t->lChild = t->rChild = nullptr;
            p->lChild = t;
            q.enqueue(t);
            }
        cout << "eneter Right child of "<< p->data <<" ";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->data = x;
            t->lChild = t->rChild = nullptr;
            p->rChild = t;
            q.enqueue(t);
            }
        }
    }

void Tree::preOrder(Node* p)
    {
    if (p)
        {
        cout << p->data << endl;
        preOrder(p->lChild);
        preOrder(p->rChild);
        }
    }
void Tree::inOrder(Node* p)
    {
    if (p)
        {
        inOrder(p->lChild);
        cout << p->data << endl;
        inOrder(p->rChild);
        }
    }
void Tree::postOrder(Node* p)
    {
    if (p)
        {
        postOrder(p->lChild);
        postOrder(p->rChild);
        cout << p->data << endl;
        }
    }



int main()
    {

    // Tree* rootTree = new Tree();
    // rootTree->createTree();
    // rootTree->inOrder(rootTree->getRoot());

    Tree t;
    t.createTree();
    t.inOrder(t.getRoot());

    return 0;
    }
