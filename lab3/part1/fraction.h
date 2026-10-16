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
        Fraction Normalize();

        Fraction(int, int);
        Fraction();

        Fraction operator +(Fraction&);
        Fraction operator -(Fraction&);
        Fraction operator *(Fraction&);
        Fraction operator /(Fraction&);

        Fraction operator +(int&);
        Fraction operator -(int&);
        Fraction operator *(int&);
        Fraction operator /(int&);
};

std::ostream& operator <<(std::ostream&, Fraction&);
