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

Fraction Fraction::Normalize(Fraction frac)
{
    int minDivider = 2;
    int maxDivider = ABS(frac.Numerator()) > ABS(frac.Denominator()) ? ABS(frac.Denominator()/2) : ABS(frac.Numerator()/2);

    for(int i = minDivider; i <= maxDivider; i++)
    {
        if(frac.Numerator()%i == 0 && frac.Denominator()%i == 0)
        {
            frac.SetNumerator(frac.Numerator() / i);
            frac.SetDenominator(frac.Denominator() / i);
            i = minDivider-1;
        }
    }
    return frac;
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

    return Normalize(Fraction(newNumerator, newDenominator));
}

void Fraction::operator +=(Fraction frac)
{
    int newNumerator = numerator * frac.Denominator() + frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    Fraction buffer = Normalize(Fraction(newNumerator, newDenominator));

    SetNumerator(buffer.Numerator());
    SetDenominator(buffer.Denominator());
}

Fraction Fraction::operator -(Fraction frac)
{
    int newNumerator = numerator * frac.Denominator() - frac.Numerator() * denominator;
    int newDenominator = denominator * frac.Denominator();

    return Normalize(Fraction(newNumerator, newDenominator));
}

Fraction Fraction::operator *(Fraction frac)
{
    int newNumerator = numerator * frac.Numerator();
    int newDenominator = denominator * frac.Denominator();

    return Normalize(Fraction(newNumerator, newDenominator));
}

Fraction Fraction::operator /(Fraction frac)
{
    if(frac.Numerator() == 0)
    {
        std::cerr << "\nError! Attempt to divide by 0! \n";
        exit(1);
    }

    int newNumerator = numerator * frac.Denominator();
    int newDenominator = denominator * frac.Numerator();

    return Normalize(Fraction(newNumerator, newDenominator));
}


Fraction Fraction::operator +(int num)
{
    int newNumerator = numerator + num*denominator ;
    int newDenominator = denominator;

    return Normalize(Fraction(newNumerator, newDenominator));
}

Fraction Fraction::operator -(int num)
{
    int newNumerator = numerator - num*denominator;
    int newDenominator = denominator;

    return Normalize(Fraction(newNumerator, newDenominator));
}

Fraction Fraction::operator *(int num)
{
    int newNumerator = numerator * num;
    int newDenominator = denominator;

    return Normalize(Fraction(newNumerator, newDenominator));
}

Fraction Fraction::operator /(int num)
{
    if(num == 0)
    {
        std::cerr << "\nError! Attempt to divide by 0! \n";
        exit(1);
    }

    int newNumerator = numerator;
    int newDenominator = denominator * num;

    return Normalize(Fraction(newNumerator, newDenominator));
}

Fraction operator +(int num, Fraction frac)
{
    int newNumerator = frac.Denominator() * num + frac.Numerator();
    int newDenominator = frac.Denominator();

    return frac.Normalize(Fraction(newNumerator, newDenominator));
}

Fraction operator -(int num, Fraction frac)
{
    int newNumerator = frac.Denominator() * num - frac.Numerator();
    int newDenominator = frac.Denominator();

    return frac.Normalize(Fraction(newNumerator, newDenominator));
}

Fraction operator *(int num, Fraction frac)
{
    int newNumerator = frac.Numerator() * num;
    int newDenominator = frac.Denominator();

    return frac.Normalize(Fraction(newNumerator, newDenominator));
}

Fraction operator /(int num, Fraction frac)
{
    if(frac.Numerator() == 0)
    {
        std::cerr << "\nError! Attempt to divide by 0! \n";
        exit(1);
    }

    int newNumerator = frac.Denominator()* num;
    int newDenominator =  frac.Numerator();

    return frac.Normalize(Fraction(newNumerator, newDenominator));
}

int ABS(int num) //Проосто поэкспериментировал - не ругаться )
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