
/*	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
Найти строку с наибольшим произведением элементов
и заменить все элементы этой строки этим произведением.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int N, S;  // кол-во столбцов и строк
    cout << "Enter a number of columns:\n";
    cin >> N;
    cout << "Enter a number of line:\n";
    cin >> S;
    int *maxProizvLine = new int; // номер строки с максимальным произведением
    int *maxProizv = new int;
    int *Proizv = new int;    // максимальное произ
    double** matrix = new double* [S];
    for (int ni = 0; ni < S; ni++)
        matrix[ni] = new double[N];


    // вводим матрицу
    cout << "Enter a matrix:\n";
    *maxProizv = 0;
    for (int i = 0; i < S; i++)
    {
        *Proizv = 1;
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
            (*Proizv) *= matrix[i][j];
            /*cout << Proizv << endl;
            cout << *Proizv << endl;*/
        }
        if (*maxProizv < *Proizv)
        {
            *maxProizv = *Proizv;
            *maxProizvLine = i;
        }
    }
    
    // выводим матрицу
    cout << "\n";
    cout << "The matrix:";
    for (int l = 0; l < S; l++)
    {
        cout << "\n";
        for (int k = 0; k < N; k++)
        {
            if (*maxProizvLine==l)
            {
                cout << (matrix[l][k] = (*maxProizv)) << " ";
            }
            else
            {
                cout << matrix[l][k] << " ";
            }
        }
    }
    
    for (int di = 0; di < S; di++)
        delete[] matrix[di];
    delete[]matrix;

    delete maxProizvLine;
    delete maxProizv;
    delete Proizv;

    return 0;
}