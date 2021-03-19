#include "Polinom.h"

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int selector = 10;

    while (selector != 0)
    {
        cout << "Continue or exit? Enter 0 to exit. In other way enter 1" << endl;
        int exit;
        cin >> exit;
        cout << endl;

        if (exit != 0)
        {
            string polinom1, polinom2;

            cout << "Enter first polinom:" << endl;
            cin >> polinom1;
            Polinom pol1(polinom1);

            cout << "Enter second polynom:" << endl;
            cin >> polinom2;
            Polinom pol2(polinom2);

            cout << endl;

            cout << "Select the action:" << endl;
            cout << "Enter 1 to sum up polinoms" << endl << "Enter 2 to substract second polinom from first" << endl << "Enter 3 to substract first polinom from second" << endl << "Enter 4 to multiplicate polinoms" << endl;
            cin >> selector;

            switch (selector)
            {
            case 1:
            {
                cout << pol1 + pol2 << endl;
                break;
            }
            case 2:
            {
                cout << pol1 - pol2 << endl;
                break;
            }
            case 3:
            {
                cout << pol2 - pol1 << endl;
                break;
            }
            case 4:
            {
                cout << pol1 * pol2 << endl;
                break;
            }
            default:
                cout << "Wrong number" << endl;
            }

            cout << endl << endl;
        }
        else selector = 0;
    }

    return 0;
}