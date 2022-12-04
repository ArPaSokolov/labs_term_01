/* Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
Упорядочить последовательность по возрастанию суммы цифр числа,
числа с одинаковыми суммами цифр дополнительно упорядочить
по возрастанию произведения цифр числа, числа с одинаковыми
суммами цифр и одинаковыми произведениями цифр дополнительно
упорядочить по возрастанию самого числа.*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a length of array:" << endl;
    int N;  // кол-во элементов
    cin >> N;
    int* mas = new int[N];
    int* masSum = new int[N];
    int* masMult = new int[N];

    // заполняем массив
    cout << "Enter the elements:" << endl;
    for (int c = 0; c < N; c++)
    {
        cin >> mas[c];
    }

    // бежим по массиву
    for (int s = 0; s < N; s++)
    {
        int o;  // остаток
        int sum = 0;    // сумма цифр числа
        int mult = 1;   // произведение цифр числа
        int q = mas[s];
        while (q > 0)   // раскладываем число по разрядам
        {
            o = q % 10;
            q = q / 10;
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
        while (j > 0 and masSum[j - 1] > masSum[j]) // бежим по элементам стоящим cлева, пока выполняется условие
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
        while (j > 0 and masMult[j - 1] > masMult[j] and masSum[j - 1] == masSum[j]) // бежим по элементам стоящим слева, пока выполняется условие
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
        while (j > 0 and mas[j - 1] > mas[j] and masMult[j - 1] == masMult[i] and masSum[j - 1] == masSum[j]) // бежим по элементам стоящим слева, пока выполняется условие
        {
            swap(mas[j], mas[j - 1]);// меняемся местами с элементом стоящим слева
            swap(masSum[j], masSum[j - 1]);
            swap(masMult[j], masMult[j - 1]);
            j = j - 1;
        }
    }

    // выводим ответ
    cout << "The array:" << endl;
    for (int h = 0; h < N; h++)
    {
        cout << mas[h] << " ";
    }

    int M;
    cout << endl << "Enter a new length of array:" << endl;
    cin >> M;
    while (M < 0)
    {
        cout << "The value is incorrect.Enter a new value:" << endl;
        cin >> M;
    }

    mas = (int*)realloc(mas, M * sizeof(int));
    cout << "Enter " << M - N << " new elements :" << endl;
    for (int R = N; R < M; R++)
    {
        cin >> mas[R];
    }

    cout << "The array:\n";
    for (int h = 0; h < M; h++)
    {
        cout << mas[h] << " ";
    }

    delete[] mas;
    delete[] masSum;
    delete[] masMult;

    return 0;
}