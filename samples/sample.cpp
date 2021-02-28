#include "header.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        string str;
        cout << "Enter arabic or roman:" << endl;
        cin >> str;

        roman r;
        arabic a;
        Convertor con;

        int num = atoi(str.c_str());
        if (num != 0)
        {
            a.val = num;
            con.toRoman(a);
        }
        else
        {
            r.val = str;
            con.toArabic(r);
        }

        cout << con << endl << endl;
    }

    return 0;
}