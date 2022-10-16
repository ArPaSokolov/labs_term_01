/* 1.	Дана последовательность натуральных чисел 
{aj}j=1...n (n<=10000). 
Если в последовательности нет ни одного простого числа, 
упорядочить последовательность по неубыванию.*/

#include <iostream>

int main()
{
    std::cout << "Enter the number of elements:\n";
    int numberOfElements;
    int primeNumber = 0;
    bool allPrime = true; // флаг - все числа простые
    std::cin >> numberOfElements;
    int mas[10000];
    std::cout << "Enter the elements:\n";
    for (int i = 0; i < numberOfElements; i++)
    {
        std::cin >> mas[i];
        for (int j = 2; j < sqrt(mas[i]); j++)
        {
            if ((mas[i] % j) == 0 or mas[i] == 1)
            {
                allPrime = false; // нашли непростое число
                primeNumber++; // количество непростых
                break;
            }
        }

    }
    if (allPrime == false) // флаг сработал - нет простых чисел
    {
        for (int k = 0; k < numberOfElements - 1; k++)
        {
            for (int l = k + 1; l < numberOfElements; l++)
            {
                if (mas[k] > mas[l])
                {
                    std::swap(mas[k], mas[l]);
                }
            }
        }
        std::cout << "The array:\n";
        for (int h = 0; h < numberOfElements; h++)
        {
            std::cout << mas[h] << " ";
        }
    }
    else // флаг сработал
    {
        std::cout << "The array:\n";
        for (int h = 0; h < numberOfElements; h++)
        {
            std::cout << mas[h] << " ";
        }
    }

    return 0;
}