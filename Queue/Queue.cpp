/**
 * @file Queue.cpp
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
    Node*lChild;
    int data;
    Node *rChild;
};
class Queue
{
    private:
    int qFront=-1,qRear=-1,qSize=10;
    Node **Q;

    public:
    Node ** getQueue()
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
    Node * dequeue();
    bool isEmpty(){
        return (qFront==qRear) ?true:false;
    }
    void print()
    {
        for (int i=0;i<=this->qRear;i++)
            {
                cout<<this->Q[i]->data<<"\n";
            }
    }
};

Queue::Queue():qFront(-1),qRear(-1),qSize(10)
{
    try{
        Q=new Node*[this->qSize];
    }
    catch(exception e)
    {
        cout<<" Exception occured "<<e.what()<<endl;
    }
}
Queue::Queue(int sz):qFront(-1),qRear(-1),qSize(sz)
{
    try{
        this->Q=new Node*[this->qSize];
    }
    catch(exception e)
    {
        cout<<" Exception occured "<<e.what()<<endl;
    }
}
void Queue::enqueue(Node*p)
{
    if (this->qRear == this->qSize-1)
    {
        cout<<"Queue is full\n";
        return;
    }
    else
    {
        Q[++this->qRear]=p;
    }

}
Node * Queue::dequeue()
{
if (this->qFront == this->qRear)
    {
        cout<<"Queue is Empty\n";
        return nullptr;
    }
    else
    {
        Node *t= Q[++this->qFront];
        return t;
    }
}

int main()
{
    Queue q;
    Node *n = new Node();
    n->data=50;
    n->lChild=nullptr;
    n->rChild=nullptr;

    Node *n1 = new Node();
    n1->data=510;
    n1->lChild=nullptr;
    n1->rChild=nullptr;

    
    if (q.isEmpty()){
        q.enqueue(n);
        //cout<<q.getQueueSize()<<"\n";
        q.enqueue(n1);
        //cout<<q.getQueueSize()<<"\n";
    }
    
    q.print();
    //cout<<q.dequeue()->data;


    return 0;
}