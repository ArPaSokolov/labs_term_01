
#include <iostream>

int main()
{
    std::cout << "Enter the number of elements:\n";
    int n;
    int N = 0;
    int c = 1; // флаг - все числа простые
    std::cin >> n;
    int mas[10000];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the element:\n";
        std::cin >> mas[i];
        for (int j = 2; j < sqrt(mas[i]); j++)
        {
            if ((mas[i] % j) == 0 or mas[i] == 1)
            {
                c = 0; // нашли непростое число
                N++; // количество непростых
                break;
            }
        }

    }
    std::cout << c << std::endl;
    if (N == n) // флаг сработал - нет простых чисел
    {
        for (int k = 0; k < n - 1; k++)
        {
            for (int l = k + 1; l < n; l++)
            {
                if (mas[k] > mas[l])
                {
                    std::swap(mas[k], mas[l]);
                }
            }
        }
        std::cout << "The array:\n";
        for (int h = 0; h < n; h++)
        {
            std::cout << mas[h] << " ";
        }
    }
    else // флаг сработал
    {
        std::cout << "The array:\n";
        for (int h = 0; h < n; h++)
        {
            std::cout << mas[h] << " ";
        }
    }

    return 0;
}