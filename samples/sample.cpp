#include "TText.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

void console(Text text)
{
    int op;
    string temp;


    while (true)
    {
        system("cls");
        cout << text << endl;
        cout << "0 - Exit" << endl;
        cout << "6 - Right" << endl;
        cout << "4 - Left" << endl;
        cout << "8 - Top" << endl;
        cout << "3 - Add to Right" << endl;
        cout << "1 - Add to Left" << endl;
        cout << "2 - Remove" << endl;
        cout << "5 - Replace" << endl;
        cout << "7 - Replace Key" << endl;
        cout << "9 - Replace Value" << endl;
        cout << "f - Find by key" << endl;

        try
        {
            op = _getch();
            switch (op)
            {
            case 48: return; break;
            case 54: text.right(); break;
            case 52: text.left(); break;
            case 56: text.top(); break;
            case 51:
                cout << "Enter string:" << endl;
                cin >> temp;
                text.addRight(temp);
                break;
            case 49:
                cout << "Enter string:" << endl;
                cin >> temp;
                text.addLeft(temp);
                break;
            case 50:
                text.remove();
                break;
            case 53:
                cout << "Enter string:" << endl;
                cin >> temp;
                text.replace(temp);
                break;
            case 55:
                cout << "Enter string:" << endl;
                cin >> temp;
                text.replaceKey(temp);
                break;
            case 57:
                cout << "Enter string:" << endl;
                cin >> temp;
                text.replaceValue(temp);
                break;
            case 102:
                cout << "Enter string:" << endl;
                cin >> temp;
                text.findValue(temp);
                _getch();
                break;
            }
        }
        catch (logic_error l)
        {
            cout << l.what() << endl;
            _getch();
        }
    }
}

int main()
{
    Text text;
    text.addLeft("L1");
    text.addLeft("L2");
    text.left();
    text.addLeft("L3");
    text.addRight("R2");
    text.addRight("R1");
    text.top();

    console(text);

    return 0;
}