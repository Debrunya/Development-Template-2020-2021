#pragma once

#include <stack>
#include <string>
#include <iostream>
using namespace std;

struct Node
{
    string val;
    Node* left;
    Node* right;

    Node(string _val, Node* _left = NULL, Node* _right = NULL) :
        val(_val), left(_left), right(_right) {}
};

class Text
{
    Node* root;
    Node* curr;
    stack<Node*> path;

public:
    Text() { root = curr = NULL; }

    void right();
    void left();
    void top();

    void addLeft(string str);
    void addRight(string str);
    void createDelPath(Node* delroot, stack<Node*> delpath);
    void remove();

    void replace(string str);
    void replaceKey(string str);
    void replaceValue(string str);

    void findKey(Node* root, string key);
    void findValue(string key);

    string getValCurr();

    void printTRL(ostream& ost, Node* root, Node* curr, int level);
    friend ostream& operator<<(ostream& ost, Text& text)
    {
        text.printTRL(ost, text.root, text.curr, 0);
        return ost;
    }
};
