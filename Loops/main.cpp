
#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node() : value(0), next(NULL) {};
};

class List;

class ListIterator
{
    friend class List;
    Node* curr;

public:
    ListIterator() { curr = NULL; }

    Node* getLink() { return curr; }

    ListIterator operator=(const ListIterator& iter)
    {
        curr = iter.curr;
        return *this;
    }
    ListIterator operator ++()
    {
        curr = curr->next;
        return *this;
    }

    bool operator==(const ListIterator& m) const { return (curr == m.curr); }
    bool operator!=(const ListIterator& m) const { return (curr != m.curr); }
};

class List
{
public:
    Node* first;

    List()
    {
        first = new Node;
        first->next = NULL;
    }

    void add(int t)
    {
        Node* temp = new Node;
        temp->value = t;
        temp->next = first;
        first = temp;
    }

    ListIterator begin()
    {
        ListIterator it;
        it.curr = first;
        return it;
    }
    
    void print()
    {
        Node* temp = first;
        while (temp->next != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

bool searchloop1(List l)
{
    bool b = false;
    Node* p1, * p2;
    p1 = l.first;
    p2 = l.first->next;
    while (true)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2)
        {
            b = true;
            break;
        }
        else if ((p2 == NULL) || (p2->next == NULL))
        {
            break;
        }
    }
    return b;
}
bool searchloop2(List l)
{
    bool b = false;
    Node* n, * c, * p;
    p = l.first;
    c = l.first;
    n = l.first->next;
    while (true)
    {
        c = n;
        n = n->next;
        c->next = p;
        p = c;

        if (c == l.first)
        {
            b = true;
            break;
        }
        else if ((n == NULL) || (n->next == NULL))
        {
            break;
        }
    }
    return b;
}


int main()
{
    List list;
    for (int i = 0; i <= 10; i++)
    {
        list.add(i);
    }
    list.print();
    cout << endl;

    ListIterator iter = list.begin();
    for (int i = 0; i <= 10; i++)
    {
        ++iter;
    }
    
    Node* k = iter.getLink();
    iter = list.begin();
    for (int i = 0; i < 6; i++)
    {
        ++iter;
    }
    k->next = iter.getLink();
//    l.print();


    bool b1 = searchloop1(list);
    bool b2 = searchloop2(list);

    cout << b1 << " " << b2;

    return 0;
}