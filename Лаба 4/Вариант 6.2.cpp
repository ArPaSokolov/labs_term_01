/* Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию суммы цифр числа, 
числа с одинаковыми суммами цифр дополнительно упорядочить 
по неубыванию произведения цифр числа, числа с одинаковыми 
суммами цифр и одинаковыми произведениями цифр дополнительно 
упорядочить по неубыванию самого числа.*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number:\n";
    int N;  // кол-во элементов
    cin >> N;
    int mas[10000];
    int masSum[10000];
    int masMult[10000];

    // заполняем массив
    for (int c = 0; c < N; c++)
    {
        cout << "Enter the element:\n";
        cin >> mas[c];
    }

    // бежим по массиву
    for (int s = 0; s < N; s++)
    {
        int n = mas[s];  // число
        int o;  // остаток
        int sum = 0;    // сумма цифр числа
        int mult = 1;   // произведение цифр числа
        while (n > 0)   // раскладываем число по разрядам
        {
            o = n % 10;
            n = n/ 10;
            sum += o;
            mult *= o;
        }
        masSum[s] = sum; // добавляем в массив сумму цифр числа
        masMult[s] = mult; // добавляем в массив произведение цифр числа
    }

    //сортировка по сумме цифр
    for (int i = 1; i < N; i++)
    {             // знак меняем здесь |
        int j = i;//                   V
        while (j > 0 and masSum[j - 1] > masSum[i]) // бежим по элементам стоящим cлева, пока выполняется условие
        {
            swap(mas[j], mas[j - 1]);// меняемся местами с элементом стоящим слева
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }
    //сортировка по сумме произведений цифр
    for (int i = 1; i < N; i++)
    {
        int j = i;
        while (j > 0 and masMult[j - 1] > masMult[i] and masSum[j - 1] == masSum[i]) // бежим по элементам стоящим слева, пока выполняется условие
        {
            swap(mas[j], mas[j - 1]);// меняемся местами с элементом стоящим слева
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }
    //сортировка по числам
    for (int i = 1; i < N; i++)
    {
        int j = i;
        while (j > 0 and mas[j - 1] > mas[i] and masMult[j - 1] == masMult[i] and masSum[j - 1] == masSum[i]) // бежим по элементам стоящим слева, пока выполняется условие
        {
            swap(mas[j], mas[j - 1]);// меняемся местами с элементом стоящим слева
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }
    
    // выводим ответ
    cout << "The array:\n";
    for (int h = 0; h < N; h++)
    {
        cout << mas[h] << " ";
    }
    return 0;

}
// первоначальное решение
/*int a;
    int b;
    for (a = 2; a < N+1; a++)
    {
        b = a;
        while (b>1)
        {
            b = b - 1;
            if (mas[b-1] > mas[b]);
            {
                swap(mas[b], mas[b-1]);
            }

        }
    }*/

    /*for (int l1 = 0; l1 < N; l1++)
        for (int l2 = 0; l2 < N; l2++)
        {
            if (num1[l1] < num1[l2])
            {
                swap(mas[l1], mas[l2]);
                swap(num1[l1], num1[l2]);
                swap(num2[l1], num2[l2]);

            }
        }

    // сортировка по произведению цифр
    for (int k1 = 0; k1 < N; k1++)
        for (int k2 = 0; k2 < N; k2++)
        {
            if (num1[k1] == num1[k2])
            {
                if ((num2[k1] < num2[k2]))
                {
                    swap(mas[k1], mas[k2]);
                    swap(num1[k1], num1[k2]);
                    swap(num2[k1], num2[k2]);
                }
            }
        }

    // сортировка по числам
    for (int k1 = 0; k1 < N; k1++)
        for (int k2 = 0; k2 < N; k2++)
        {
            if (num1[k1] == num1[k2] and (num2[k1] == num2[k2]))
            {
                if ((mas[k1] < mas[k2]))
                {
                    swap(mas[k1], mas[k2]);
                    swap(num1[k1], num1[k2]);
                    swap(num2[k1], num2[k2]);
                }
            }
        }
    */
/* сортировка по сумме цифр(пузырьком) https://ru.wikipedia.org/wiki/Сортировка_вставками */
    /*int j;
    int i;
    for (i = 1; i < N; i++)
    {
        int xSum = masSum[i]; // переменная, которая хранит сравниваемый элемент
        int x = mas[i];
        j = i;
        while (j > 0 and masSum[j - 1] > xSum) // бежим по элементам стоящим левее, пока выполняется условие
        {
            masSum[j] = masSum[j - 1];  // перезаписываем слева стоящий элемент
            mas[j] = mas[j - 1];
            j = j - 1;
        }
        masSum[j] = xSum; // восстанавливаем перезаписанный элемент
        mas[j] = x;
    }*/