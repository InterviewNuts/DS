/**
 * @file XOR_LinkList.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace  std;



struct Node
{
    int data;
    Node *next;
};

void createList()
{
 int i=10;
 Node * prev,*curr,*start=nullptr;
 
 while(i<=50)
 {
    if (start== nullptr)
        {
            start=new Node();
            start->data=i;
            start->next=nullptr;
            prev=curr=start;
        }
    else{  
        curr=new Node();
        curr->data=i;
        curr->next=nullptr;
        prev->next=curr;
        prev=prev->next;
    }
    i=i+10;
 }

 int j=1;
 while (j <=5 )
 {
     j++;
    std::cout<<" Data = "<< start->data<<std::endl;
    start= start->next;
 }
}


int main()
{
    createList();
}
