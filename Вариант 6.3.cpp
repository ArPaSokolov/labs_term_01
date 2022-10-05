
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of elements in a row:\n";
    int N;  // кол-во элементов в ряду
    int mi; // номер строки с максимальным произведением
    int max = 0;    // максимальное произ
    cin >> N;
    int matrix[100][100];
    // вводим матрицу
    cout << "Enter the elements:\n";
    for (int i = 0; i < N; i++)
    {
        int mult = 1;
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
            mult *= matrix[i][j];
            if (max < mult)
            {
                max = mult;
                mi = i;
            }
        }
    }
    
    // выводим матрицу
    cout << "\n";
    cout << "The matrix:";
    for (int l = 0; l < N; l++)
    {
        cout << "\n";
        for (int k = 0; k < N; k++)
        {
            if (l == mi)
            {
                cout << (matrix[l][k] = max) << " ";
            }
            else
            {
                cout << matrix[l][k] << " ";
            }
        }
    }
    return 0;
}