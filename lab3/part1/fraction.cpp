#include "fraction.h"

int Fraction::Numerator()
{ 
    return numerator;
}

int Fraction::Denominator()
{
    return denominator;
}

void Fraction::SetNumerator(int number)
{
    numerator = number;
}

void Fraction::SetDenominator(int number)
{
    if(number != 0) 
      denominator = number;
    else
      denominator = 1;
}


double Fraction::ToDouble()
{
    return (double)numerator / (double)denominator;
}

Fraction Fraction::Normalize()
{
    int minDivider = 2;
    int maxDivider = numerator > denominator ? denominator/2 : numerator/2;

    for(int i = minDivider; i <= maxDivider; i++)
    {
        if(numerator%i == 0 && denominator%i == 0)
        {
            numerator /= i;
            denominator /=i;
            i = minDivider-1;
        }
    }

    return Fraction(numerator, denominator);
}


Fraction::Fraction(int newNumerator, int newDenominator)
{
    SetNumerator(newNumerator);
    SetDenominator(newDenominator);
}

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}


Fraction Fraction::operator +(Fraction& frac)
{
    int newNumerator = numerator * frac.Denominator() + frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator -(Fraction& frac)
{
    int newNumerator = numerator * frac.Denominator() - frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator *(Fraction& frac)
{
    int newNumerator = numerator * frac.Numerator();
    int newDenominator = denominator * frac.Denominator();

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator /(Fraction& frac)
{
    int newNumerator = numerator * frac.Denominator();
    int newDenominator = denominator * frac.Numerator();

    return Fraction(newNumerator, newDenominator);
}


Fraction Fraction::operator +(int& num)
{
    int newNumerator = numerator * num + denominator;
    int newDenominator = denominator * num;

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator -(int& num)
{
    int newNumerator = numerator * num - denominator;
    int newDenominator = denominator * num;

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator *(int& num)
{
    int newNumerator = numerator * num;
    int newDenominator = denominator;

    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator /(int& num)
{
    int newNumerator = numerator;
    int newDenominator = denominator * num;

    return Fraction(newNumerator, newDenominator);
}


std::ostream& operator <<(std::ostream& outStream, Fraction& frac)
{
    return outStream << frac.Numerator() << '/' << frac.Denominator();
}