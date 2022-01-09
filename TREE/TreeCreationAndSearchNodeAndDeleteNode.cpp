/**
 * @file TreeCreationAndSearchNode.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<queue>
using namespace std;
class Node
    {
    public:
        Node* lChild;
        int data;
        Node* rChild;
    };

class Tree
    {
    private:
        Node* root = nullptr;
        Node * serahNode=nullptr;
    public:
        Node * getSerahNode(){return serahNode;};
        Node* getRoot() { return root; }
        Tree() :root(nullptr){};
        void createTree();
        void preOrder(Node* r);
        void postOrder(Node* r);
        void inOrder(Node* r);
        void searchNode(Node* r,int data);
        void deleteSearchedNode(Node * sn);
    };


void Tree::createTree()
    {
    queue<Node*> q;
    Node* p = nullptr, * t = nullptr;
    int x;
    cout << "Eneter root value ";
    cin >> x;
    root = new Node();
    root->data = x;
    root->lChild = root->rChild = nullptr;
    q.emplace(root);

    while (!q.empty())
        {
        p = q.front();
        q.pop();
        cout << "eneter left child of "<< p->data <<" ";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->data = x;
            t->lChild = t->rChild = nullptr;
            p->lChild = t;
            q.emplace(t);
            }
        cout << "eneter Right child of "<< p->data <<" ";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->data = x;
            t->lChild = t->rChild = nullptr;
            p->rChild = t;
            q.emplace(t);
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


void Tree::searchNode(Node * r,int data)
{
    //Node * r = root;
    if (!r ) return ;

    if ( r->data == data)
    {
        cout<<" Now matched Data = "<<r->data<<" \n";
        serahNode=r;
        return ;
    }
    else{
        cout<<" No matche, going on\n";
        searchNode(r->lChild,data);
        searchNode(r->rChild,data);
        return ;
    }
    
}

void Tree::deleteSearchedNode(Node * sn)
{
    Node * p=sn;
    Node* delNode=sn;
    sn = sn->rChild;
    if(sn)
    {
        while (sn->lChild!=nullptr)
        {
           p=sn;
           sn=sn->lChild;
        }
        //! now change the value
        delNode->data=sn->data;
        delete sn;
        p->lChild=nullptr;
    }
    else
    {
        sn->data=sn->lChild->data;
        delete sn->lChild;
        sn->lChild=nullptr;
    }
    
    

}


int main()
    {
    Tree t;
    t.createTree();
    t.inOrder(t.getRoot());
    t.searchNode(t.getRoot(),60);
    t.deleteSearchedNode(t.getSerahNode());
    t.inOrder(t.getRoot());
    return 0;
    }
