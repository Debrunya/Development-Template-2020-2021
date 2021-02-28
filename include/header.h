#include <string>
#include <iostream>
using namespace std;


struct roman
{
    string val;
};

struct arabic
{
    int val;
};

class Convertor
{
    roman r_struct;
    arabic a_struct;

public:
    void toArabic(roman t);
    void toRoman(arabic t);

    string get_r_struct();
    int get_a_struct();

    friend ostream& operator<<(ostream& out, Convertor& c);
};
