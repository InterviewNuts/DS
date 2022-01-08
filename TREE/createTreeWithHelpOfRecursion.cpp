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
        Node* root = nullptr;
    public:
        Node* getRoot() { return root; }
        Tree() :root(nullptr){};
        Node* createTree(Node * r,int data);
        void preOrder(Node* r);
        void postOrder(Node* r);
        void inOrder(Node* r);
    };


Node* Tree::createTree(Node * r,int data)
    {
    Node* p = nullptr;
    if (!r) {
        //! this code is for first time, this ccan be improved. 
        r = new Node();
        r->data = data;
        r->lChild = r->rChild = nullptr;
        if ( !root)
        {
            root=r;
        }
        return r;
        }
    if (data < r->data)
        r->lChild = createTree(r->lChild,data);
    else if (data > r->data)
        r->rChild = createTree(r->rChild,data);
    return r;
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

    Tree* rootTree = new Tree();
     
    Node *r=rootTree->createTree(rootTree->getRoot(),50);
    r=rootTree->createTree(r,60);
    r=rootTree->createTree(r,40);
    r=rootTree->createTree(r,20);
    r=rootTree->createTree(r,80);


    rootTree->inOrder(rootTree->getRoot());


    return 0;
    }