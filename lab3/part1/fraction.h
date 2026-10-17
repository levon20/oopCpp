#include <iostream>

class Fraction
{
    private:
        int numerator;
        int denominator;
 
    public:
        int Numerator();
        int Denominator();
        void SetNumerator(int);
        void SetDenominator(int);

        double ToDouble();
        Fraction Normalize(Fraction);

        Fraction(int, int);
        Fraction(int);
        Fraction();

        Fraction operator +(Fraction);
        Fraction operator -(Fraction);
        Fraction operator *(Fraction);
        Fraction operator /(Fraction);

        Fraction operator +(int);
        void operator += (Fraction);
        Fraction operator -(int);
        Fraction operator *(int);
        Fraction operator /(int);
};

Fraction operator +(int, Fraction);
Fraction operator -(int, Fraction);
Fraction operator *(int, Fraction);
Fraction operator /(int, Fraction);

std::ostream& operator <<(std::ostream&, Fraction);
int ABS(int);