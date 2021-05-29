
#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
    Node* left;
    Node* right;

    Node(Node* _left = NULL, Node* _right = NULL) : left(_left), right(_right) {}
};

int height(Node* root)
{
    int h1 = 0, h2 = 0;

    if (root == NULL) return 0;
    if (root->left) h1 = height(root->left);
    if (root->right) h2 = height(root->right);

    return(max(h1, h2) + 1);
}

//                a
//            b       c
//        d       f
//    e               h
//g


int main()
{
    Node* g = new Node;
    Node* e = new Node(g, NULL);
    Node* d = new Node(e, NULL);
    Node* h = new Node;
    Node* f = new Node(NULL, h);
    Node* b = new Node(d, f);
    Node* c = new Node;
    Node* a = new Node(b, c);

    int i = height(a);
    cout << i;

    return 0;
}