#include <iostream>
#include "fraction.h"

void PrintMatrix(Fraction*, int, int);
Fraction Get2x2MatrixDeterminant(Fraction*);
void GetSquareMatrix(Fraction*, Fraction*, int, int);

int main()
{
    int numOfRows = 2;
    int numOfCol = 2;
    
    //Матрицы объявил так, посокльку так их проще передать в метод в виде аргумента )

    Fraction resultMatrix[numOfRows*numOfCol];
    Fraction matrix[numOfRows*numOfCol]
    {
        Fraction(1,2), Fraction(3,4),
        Fraction(1,4), Fraction(1)
    };

    GetSquareMatrix(matrix, resultMatrix, numOfRows, numOfCol);

    PrintMatrix(resultMatrix, numOfRows, numOfCol);
    std::cout << "\ndet = " <<  Get2x2MatrixDeterminant(matrix) << '\n';
}

void PrintMatrix(Fraction* matrix, int numOfRows, int numOfCol)
{
    for (int i = 0; i < numOfRows; i++)
    {
        std::cout << '\n';
        for (int j = 0; j < numOfCol; j++)
            std::cout << matrix[j + i*numOfRows] << ' ';
    }
    std::cout << '\n';
}

Fraction Get2x2MatrixDeterminant(Fraction* matrix)
{
    // В этом решении практически все очень легко масштабиремо, кроме этого.. В задаче сказано под матрицу 2х2 - я сделал.
    // Просто уже надоела эта задача, не хочу больше ей время уделять. А где-то подсматривать алгоритм - я не люблю.
    return matrix[0] * matrix[3] - matrix[1] * matrix[2];
}

void GetSquareMatrix(Fraction* matrix, Fraction* result, int numOfRows, int numOfCol)
{
    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfCol; j++)
        {
            result[j + i*numOfRows] = Fraction(0);

            for (int g = 0; g < numOfCol; g++)
                result[j + i*numOfRows] += matrix[g + i*numOfRows] * matrix[j + g*numOfRows];
        }
    }
}