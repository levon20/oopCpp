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
    int maxDivider = ABS(numerator) > ABS(denominator) ? ABS(denominator/2) : ABS(numerator/2);

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

Fraction::Fraction(int number)
{
    SetNumerator(number);
    SetDenominator(1);
}

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}


Fraction Fraction::operator +(Fraction frac)
{
    int newNumerator = numerator * frac.Denominator() + frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    return Fraction(newNumerator, newDenominator).Normalize();
}

void Fraction::operator +=(Fraction frac)
{
    int newNumerator = numerator * frac.Denominator() + frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    SetNumerator(newNumerator);
    SetDenominator(newDenominator);
    Normalize();
}

Fraction Fraction::operator -(Fraction frac)
{
    int newNumerator = numerator * frac.Denominator() - frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction Fraction::operator *(Fraction frac)
{
    int newNumerator = numerator * frac.Numerator();
    int newDenominator = denominator * frac.Denominator();

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction Fraction::operator /(Fraction frac)
{
    int newNumerator = numerator * frac.Denominator();
    int newDenominator = denominator * frac.Numerator();

    return Fraction(newNumerator, newDenominator).Normalize();
}


Fraction Fraction::operator +(int num)
{
    int newNumerator = numerator * num + denominator;
    int newDenominator = denominator * num;

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction Fraction::operator -(int num)
{
    int newNumerator = numerator * num - denominator;
    int newDenominator = denominator * num;

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction Fraction::operator *(int num)
{
    int newNumerator = numerator * num;
    int newDenominator = denominator;

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction Fraction::operator /(int num)
{
    int newNumerator = numerator;
    int newDenominator = denominator * num;

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction operator +(int num, Fraction frac)
{
    int newNumerator = frac.Numerator() * num + frac.Denominator();
    int newDenominator = frac.Denominator() * num;

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction operator -(int num, Fraction frac)
{
    int newNumerator = frac.Numerator() * num - frac.Denominator();
    int newDenominator = frac.Denominator() * num;

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction operator *(int num, Fraction frac)
{
    int newNumerator = frac.Numerator() * num;
    int newDenominator = frac.Denominator();

    return Fraction(newNumerator, newDenominator).Normalize();
}

Fraction operator /(int num, Fraction frac)
{
    int newNumerator = frac.Numerator();
    int newDenominator = frac.Denominator() * num;

    return Fraction(newNumerator, newDenominator).Normalize();
}

int ABS(int num)
{
    if((num >> 31) & 1) 
        return -num;
    else 
        return num;
}

std::ostream& operator <<(std::ostream& outStream, Fraction frac)
{
    return outStream << frac.Numerator() << '/' << frac.Denominator();
}