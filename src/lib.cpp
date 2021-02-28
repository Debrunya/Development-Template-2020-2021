#include "header.h"

#include<map>
#include <string>
#include <iostream>
using namespace std;

struct temp_connections {
    char letter;
    int number;
};
const temp_connections ARR[] = { {'I', 1}, {'V', 5}, {'X', 10} , {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

void Convertor::toArabic(roman t)
{
    r_struct = t;

    string str = t.val;
    int res = 0;

    for (int i = 0; i < str.size() - 1; i++)
    {
        int l, r;

        switch (str[i])
        {
        case 'I':
            l = 0;
            break;
        case 'V':
            l = 1;
            break;
        case 'X':
            l = 2;
            break;
        case 'L':
            l = 3;
            break;
        case 'C':
            l = 4;
            break;
        case 'D':
            l = 5;
            break;
        case 'M':
            l = 6;
            break;
        }

        int left = ARR[l].number;

        switch (str[i + 1])
        {
        case 'I':
            r = 0;
            break;
        case 'V':
            r = 1;
            break;
        case 'X':
            r = 2;
            break;
        case 'L':
            r = 3;
            break;
        case 'C':
            r = 4;
            break;
        case 'D':
            r = 5;
            break;
        case 'M':
            r = 6;
            break;
        }

        if (left < ARR[r].number)
            res -= left;
        else
            res += left;
    }

    int last;

    switch (str[str.size() - 1])
    {
    case 'I':
        last = 0;
        break;
    case 'V':
        last = 1;
        break;
    case 'X':
        last = 2;
        break;
    case 'L':
        last = 3;
        break;
    case 'C':
        last = 4;
        break;
    case 'D':
        last = 5;
        break;
    case 'M':
        last = 6;
        break;
    }

    res += ARR[last].number;

    a_struct.val = res;

    return;
};

void Convertor::toRoman(arabic t)
{
    a_struct = t;

    int num = a_struct.val;
    string res = "";
    int k = 100;

    for (int i = 6; i >= 0; i--)
    {
        if (num / ARR[i].number > 0)
        {
            for (int j = 0; j < num / ARR[i].number; j++)
            {
                res.append(1, ARR[i].letter);
            }

            num = num % ARR[i].number;
        }

        if (num >= ARR[i].number - k)
        {
            res.append(1, ARR[i - 1 - !(i % 2)].letter);
            res.append(1, ARR[i].letter);
            num -= (ARR[i].number - k);
        }

        if (i % 2 == 1) k /= 10;
    }

    r_struct.val = res;

    return;
};

string Convertor::get_r_struct()
{
    return r_struct.val;
}

int Convertor::get_a_struct()
{
    return a_struct.val;
}

ostream& operator<<(ostream& out, Convertor& c)
{
    out << "Roman version: " << c.get_r_struct() << endl;
    out << "Arabic version: " << c.get_a_struct() << endl;

    return out;
}