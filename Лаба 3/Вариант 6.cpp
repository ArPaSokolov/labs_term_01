#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int N, sum = 0, max = INT_MIN, i = 0, j = 0;
    int G;
    cout << "Введите количество чисел последовательности:\n";
    cin >> N;
    while (i < N)
    {
        i += 1;
        cout << "Введите число:\n";
        cin >> G;
        if (G < 0 and G % 7 == 0)
        {
            sum = sum + G;
            if (max < G)
            {
                max = G;
                j = i;
            }
        }
    }
    if (max != INT_MIN)
    {
        cout << "Сумма:\n";
        cout << sum << endl;
        cout << "Максимальное значение:\n";
        cout << max << endl;
        cout << "Номер числа:\n";
        cout << j << endl;
    }
    else
    {
        cout << "Чисел удовлетворяющих условию нет" << endl;
    }

    return 0;
}