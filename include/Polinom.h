#pragma once

#ifndef POLINOM
#define POLINOM

#include "TList.h"
#include "TMonom.h"

class Polinom
{
private:
    TList<int, float>* monoms;

    void SortMonoms();
    void SimilarMonoms();

public:
    Polinom();
    Polinom(TList<int, float>* list);
    Polinom(const string&);
    Polinom(const Polinom& list);

    ~Polinom();

    Polinom operator+(const Polinom& polinom)const;
    Polinom operator+(const TNode<int, float>& monom);
    Polinom operator-() const;
    Polinom operator-(const Polinom& polinom);
    Polinom operator-(const TNode<int, float>& monom);
    Polinom operator*(const Polinom& polinom)const;
    Polinom operator*(const TNode<int, float>& monom)const;
    bool operator==(const Polinom& polinom)const;
    const Polinom& operator=(const Polinom& polinom);

    friend ostream& operator<<(std::ostream& out, const Polinom& pol);
};
#endif POLINOM