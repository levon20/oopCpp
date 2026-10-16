#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    Fraction frac0 = Fraction(5, 20);
    Fraction frac1 = Fraction(3, 4);

    Fraction resultInc = (frac0 + frac1).Normalize();
    Fraction resultDec = (frac0 - frac1).Normalize();
    Fraction resultMul = (frac0 * frac1).Normalize();
    Fraction resultDiv = (frac0 / frac1).Normalize();

    cout << frac0 << " + " << frac1 << " = " << resultInc << "\n\n";
    cout << frac0 << " - " << frac1 << " = " << resultDec << "\n\n";
    cout << frac0 << " * " << frac1 << " = " << resultMul << "\n\n";
    cout << frac0 << " / " << frac1 << " = " << resultDiv << "\n\n";

    cout << resultInc.ToDouble();
}