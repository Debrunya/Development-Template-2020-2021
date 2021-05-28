#include "TText.h"

#include <stack>
#include <iostream>
using namespace std;

void Text::printTRL(ostream& ost, Node* root, Node* curr, int level)
{
    if (root == NULL) return;
    if (root == curr) ost << ">|";
    else ost << " |";

    for (int i = 0; i < level; i++)
    {
        ost << "   ";
    }
    ost << root->val << endl;

    printTRL(ost, root->right, curr, level + 1);
    printTRL(ost, root->left, curr, level);
};

void Text::right()
{
    if (curr == NULL) throw logic_error("Error void right: curr == NULL");
    if (curr->right == NULL) throw logic_error("Error void right: curr->right == NULL");
    path.push(curr);
    curr = curr->right;
}
void Text::left()
{
    if (curr == NULL) throw logic_error("Error void left: curr == NULL");
    if (curr->left == NULL) throw logic_error("Error void left: curr->left == NULL");
    path.push(curr);
    curr = curr->left;
}
void Text::top()
{
    if (curr == NULL) throw logic_error("Error void top: curr == NULL");
    if (path.empty()) throw logic_error("Error void top: path.empty()");
    curr = path.top();
    path.pop();
}

void Text::addLeft(string str)
{
    if (root == NULL)
    {
        root = curr = new Node(str);
        return;
    }

    Node* newnode = new Node(str, curr->left);
    curr->left = newnode;
}
void Text::addRight(string str)
{
    if (root == NULL)
    {
        root = curr = new Node(str);
        return;
    }

    Node* newnode = new Node(str, curr->right);
    curr->right = newnode;
}
void Text::createDelPath(Node* delroot, stack<Node*> delpath)
{
    if (delroot == NULL) return;
    delpath.push(delroot);
    createDelPath(delroot->right, delpath);
    createDelPath(delroot->left, delpath);
}
void Text::remove()
{
    if (root == NULL) return;
    if (curr == root)
    {
        if (curr->right == NULL)
        {
            if (curr->left == NULL)
            {
                Node* tempCurr = curr;
                delete tempCurr;
                root = curr = NULL;
            }
            else
            {
                Node* tempCurr = curr;
                Node* tempLeft = curr->left;
                delete tempCurr;
                root = curr = tempLeft;
            }
        }
        else
        {
            if (curr->left == NULL)
            {
                stack<Node*> delpath;
                createDelPath(curr->right, delpath);
                Node* tempCurr = curr;
                while (delpath.empty() != true)
                {
                    delete delpath.top();
                    delpath.pop();
                }
                delete tempCurr;
                root = curr = NULL;
            }
            else
            {
                stack<Node*> delpath;
                createDelPath(curr->right, delpath);
                Node* tempCurr = curr;
                Node* tempLeft = curr->left;
                while (delpath.empty() != true)
                {
                    delete delpath.top();
                    delpath.pop();
                }
                delete tempCurr;
                root = curr = tempLeft;
            }
        }
    }
    else
    {
        if (curr->right == NULL)
        {
            if (curr->left == NULL)
            {
                Node* tempCurr = curr;
                top();
                if (tempCurr == curr->left)
                {
                    delete tempCurr;
                    curr->left = NULL;
                }
                if (tempCurr == curr->right)
                {
                    delete tempCurr;
                    curr->right = NULL;
                }
            }
            else
            {
                Node* tempCurr = curr;
                Node* tempLeft = curr->left;
                top();
                if (tempCurr == curr->left)
                {
                    delete tempCurr;
                    curr->left = tempLeft;
                }
                if (tempCurr == curr->right)
                {
                    delete tempCurr;
                    curr->right = tempLeft;
                }
            }
        }
        else
        {
            if (curr->left == NULL)
            {
                stack<Node*> delpath;
                createDelPath(curr->right, delpath);
                Node* tempCurr = curr;
                top();
                if (tempCurr == curr->left)
                {
                    while (delpath.empty() != true)
                    {
                        delete delpath.top();
                        delpath.pop();
                    }
                    delete tempCurr;
                    curr->left = NULL;
                }
                if (tempCurr == curr->right)
                {
                    while (delpath.empty() != true)
                    {
                        delete delpath.top();
                        delpath.pop();
                    }
                    delete tempCurr;
                    curr->right = NULL;
                }
            }
            else
            {
                stack<Node*> delpath;
                createDelPath(curr->right, delpath);
                Node* tempCurr = curr;
                Node* tempLeft = curr->left;
                top();
                if (tempCurr == curr->left)
                {
                    while (delpath.empty() != true)
                    {
                        delete delpath.top();
                        delpath.pop();
                    }
                    delete tempCurr;
                    curr->left = tempLeft;
                }
                if (tempCurr == curr->right)
                {
                    while (delpath.empty() != true)
                    {
                        delete delpath.top();
                        delpath.pop();
                    }
                    delete tempCurr;
                    curr->right = tempLeft;
                }
            }
        }
    }
}

void Text::replace(string str)
{
    if (curr == NULL) throw logic_error("Error void replace: curr == NULL");
    curr->val = str;
    return;
}
void Text::replaceKey(string str)
{
    if (curr == NULL) throw logic_error("Error void replaceKey: curr == NULL");
    int checkKeyCurr = curr->val.find(":");
    string temp;
    temp.append(str);
    if (checkKeyCurr == -1)
    {
        temp.append(":");
        temp.append(curr->val);
    }
    else
    {
        curr->val.erase(0, checkKeyCurr);
        temp.append(curr->val);
    }
    curr->val = temp;
    return;
}
void Text::replaceValue(string str)
{
    if (curr == NULL) throw logic_error("Error void replaceValue: curr == NULL");
    int checkKeyCurr = curr->val.find(":");
    string temp;
    if (checkKeyCurr == -1)
    {
        curr->val = str;
    }
    else
    {
        curr->val.erase(checkKeyCurr);
        temp.append(curr->val);
        temp.append(":");
        temp.append(str);
        curr->val = temp;
    }
    return;
}

string Text::getValCurr()
{
    return curr->val;
}

void Text::findKey(Node* root, string key)
{
    if (root == NULL) return;
    int checkKeyRoot = root->val.find(":");
    string temp;
    string value;
    if (checkKeyRoot != -1)
    {
        temp = root->val;
        temp.erase(checkKeyRoot);
        if (temp == key)
        {
            value = root->val;
            int checkKey = value.find(":");
            value.erase(0, checkKey + 1);
            cout << endl << value << endl;
            return;
        }
    }
    findKey(root->right, key);
    findKey(root->left, key);
}
void Text::findValue(string key)
{
    findKey(root, key);
    return;
}