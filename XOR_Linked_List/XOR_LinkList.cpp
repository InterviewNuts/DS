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

 /*
 Note that XOR of pointers is not defined by C/C++ standard. So the above implementation may not work on all
 platforms.


 uintptr_t , Primarily for bitwise operations on pointers. In C++ one cannot perform bitwise operations on pointers.
 Thus in order to do bitwise operations on pointers one would need to cast pointers to type unitpr_t and
 then perform bitwise operations.

 Here is an example of a function that I just wrote to do bitwise exclusive or of 2 pointers to store in a
 XOR linked list so that we can traverse in both directions like a doubly linked list but
 without the penalty of storing 2 pointers in each node.

  template <typename T>
  T* xor_ptrs(T* t1, T* t2)
  {
      return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(t1)^reinterpret_cast<uintptr_t>(t2));
   }

 */
#include<iostream>

#include <cinttypes>
using namespace  std;



struct Node
{
    int data;
    Node* next;
};

void createList()
{
    int i = 10;
    Node* prev, * curr, * start = nullptr;

    while (i <= 50)
    {
        curr = new Node();
        curr->data = i;
        if (start == nullptr)
        {
            curr->next = start;
            prev = start = curr;
        }
        else {
            //! npx ( previous node ^ next Node)
            curr->next = prev;
            prev->next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(curr) ^ reinterpret_cast<uintptr_t>(prev->next));
            prev = curr;
        }
        i = i + 10;
    }

    int j = 1;
    curr = start;
    prev = nullptr;
    Node* next;

    while (curr != nullptr)
    {
        std::cout << " Data = " << curr->data << std::endl;

        // get address of next node: curr->npx is 
        // next^prev, so curr->npx^prev will be 
        // next^prev^prev which is next

        //next = XOR (prev, curr->npx); 
        next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(prev) ^ reinterpret_cast<uintptr_t>(curr->next));
        // update prev and curr for next iteration 
        prev = curr;
        curr = next;
    }
}


int main()
{
    createList();
}
