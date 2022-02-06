/*
BFS (Breadth First Search) − It is a tree traversal algorithm that is also known as Level Order Tree Traversa. 
In this traversal we will traverse the tree row by row i.e. 1st row, then 2nd row, and so on.

DFS (Depth First Search ) − It is a tree traversal algorithm that traverses the structure to its deepest nod. 
There are three most used methods that are used to traverse the tree using DFS.
it goes into depth of each node as the root node and then goes to the next one.

Solved for a Tree
Let’s find the traversal of a tree using both these methods −

BFS traversal : A B K M S T
DFS traversal :
Preorder : A M N K S T
PostOrder: M B S T K A
InOrder: M B A S K T
Now, as we know the usage of both algorithms have Some similarities and some differences in their applications.
And both have found applications in dynamic programming, so let’s see who these things work.

The time complexity of both BFS and DFS is O(n).

Space required for traversal in BFS is of the order of width O(w) whereas the space required for traversal in DFS
is of the order of height O(h) of the tree.

Implementation of BFS tree traversal algorithm,
*/

#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    struct Node* left, * right;
    };
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
    }
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level Order traversal of binary tree is \n";
    queue<Node*> q;
    q.push(root);
    while (q.empty() == false) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        }
    return 0;
    }