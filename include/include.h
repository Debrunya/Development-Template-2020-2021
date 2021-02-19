#ifndef INCLUDE_ROMAN_H_
#define INCLUDE_ROMAN_H_

struct roman {
  std::string value;
};

struct arabic {
  int value;
};

// I V X  -  M C

class Convertor {
  roman value_1;
  arabic value_2;

  arabic toArabic(roman t);
  roman toRoman(arabic t);

  bool check(roman &t);        // IIII - IV

  // оператор ввода-вывода, либо print

};

#endif  // INCLUDE_ROMAN_H_