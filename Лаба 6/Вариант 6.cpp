/*Дана целочисленная матрица {Aij}i=1...n;j=1..n ,
n<=100. Если в матрице есть еще один элемент,
равный ее максимальному элементу,
упорядочить строки матрицы по убыванию
количества простых чисел среди элементов строк.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void inF(ifstream& in, int numReading[50][50], int N, int M) //процедура чтения файла
{
	for (int inI = 0; inI < M; inI++)
	{
		for (int inJ = 0; inJ < N; inJ++)
			in >> numReading[inI][inJ];
	}
}

void outF(ofstream& out, int numReading[50][50], int N, int M)// процедура выведения файла
{
	for (int ofI = 0; ofI < M; ofI++)
	{
		for (int ofJ = 0; ofJ < N; ofJ++)
		{
			out << numReading[ofI][ofJ] << " ";
			cout << numReading[ofI][ofJ] << " ";
		}
		out << '\n';
		cout << '\n';
	}
}

int findMax(int numReading[50][50], int max, int M, int N) //поиск максимального
{
	for (int mI = 0; mI < M; mI++)
	{
		for (int mJ = 0; mJ < N; mJ++)
		{
			if (numReading[mI][mJ] > max)
			{
				max = numReading[mI][mJ];
			}
		}
	}
	return max;
}

int ifPrime(int isPrime, int number) // определяем простое число или нет
{
	isPrime = 1;// число простое
	for (int i = 2; i <= sqrt(number); i++)
	{
		if ((number % i) == 0)
		{
			isPrime = 0; // число не простое
		}
	}
	return isPrime;
}

int ifPrime(int isPrime, double number) // определяем простое число или нет
{
	isPrime = 0;// число не простое
	return isPrime;
}

string ifPrime(int a) // определяем простое число или нет
{
	string b = "простое";
	for (int i = 2; i <= sqrt(a); i++)
	{
		if ((a % i) == 0)
		{
			b = "число не простое";
		}
	}
	return b;
}

void decreasSort(int numberOfPrime[100], int numReading[50][50], int M, int N) // сортировка
{
	for (int sI = 0; sI < M; sI++)
	{
		int s = sI;
		while (s > 0 and numberOfPrime[s - 1] < numberOfPrime[s]) // бежим по элементам стоящим cлева, пока выполняется условие
		{
			swap(numberOfPrime[s], numberOfPrime[s - 1]);// меняем местами с элементом стоящим слева (бежим по количеству простых)
			for (int sJ = 0; sJ < N; sJ++)
				swap(numReading[s][sJ], numReading[s - 1][sJ]);// меняем местами строки по числам
			s = s - 1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt"); // имя файла и спецификатор (для чтения)
	ofstream out("output.txt"); // имя файла и спецификатор (для вывода)
	int numReading[50][50]; // матрица
	int numberOfPrimeInLine = 0; // количество простых в одной строке
	int N, M; //количество столбцов и строк
	int isPrime = 1; //счетчик простых чисел
	in >> N;
	in >> M;
	int max = INT_MIN;
	int numberOfPrime[100]; // массив для хранения количества простых чисел в каждой строке
	int sortTrue = 0; //потребность в сортировке

	inF(in, numReading, N, M); // считываем файл

	max = findMax(numReading, max, M, N); // находим максимальное значение

	for (int nI = 0; nI < M; nI++) // считаем количество простых чисел в строках
	{
		for (int nJ = 0; nJ < N; nJ++)
		{
			int number = numReading[nI][nJ];
			if (number == max) // проверяем на повтор максимального значения
				sortTrue += 1; // максимальное значение повторилось
			numberOfPrimeInLine += ifPrime(isPrime, number); // считаем количество простых в строке
		}
		numberOfPrime[nI] = numberOfPrimeInLine; // строка закончилась -> запоминаем количество простых в ней
		numberOfPrimeInLine = 0; // обновляем счетчик для следующей строки
	}

	if (sortTrue > 1)//максимальное повторилось -> сортируем
	{
		decreasSort(numberOfPrime, numReading, M, N);
		outF(out, numReading, N, M); //выводим полученную матрицу
	}
	else // максимальное одно -> сортировка не нужна
	{
		outF(out, numReading, N, M); // выводим полученную матрицу
	}
	return 0;
}