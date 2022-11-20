/*Дана целочисленная матрица {Aij}i=1...n;j=1..n ,
n<=100. Если в матрице есть еще один элемент,
равный ее максимальному элементу,
упорядочить строки матрицы по убыванию
количества простых чисел среди элементов строк.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void inF(int numReading[50][50],int &N, int &M) //процедура чтения файла
{
	ifstream in("input.txt"); // имя файла и спецификатор (для чтения)
	in >> N;//столбцы
	in >> M;//стоки
	for (int inI = 0; inI < M; inI++)
	{
		for (int inJ = 0; inJ < N; inJ++)
			in >> numReading[inI][inJ];
	}
	in.close();// закрываем файл
}

void outF(int numReading[50][50], int &N, int &M, int numberOfPrime[100])// процедура выведения файла
{
	ofstream out("output.txt"); // имя файла и спецификатор (для вывода)
	for (int ofI = 0; ofI < M; ofI++)
	{
		for (int ofJ = 0; ofJ < N; ofJ++)
		{
			out << numReading[ofI][ofJ] << " ";
			cout << numReading[ofI][ofJ] << " ";
		}
		out << '\n';
		cout << "| " << numberOfPrime[ofI];
		cout << '\n';
	}
	out.close();// закрываем файл
}

int findMax(int numReading[50][50], int &N, int &M) //поиск максимального
{
	int max = INT_MIN;
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

int ifPrime(int isPrime, int numReading[50][50], int &nI, int &nJ) // определяем простое число или нет
{
	isPrime = 1;// число простое
	for (int i = 2; i <= sqrt(numReading[nI][nJ]); i++)
	{
		if ((numReading[nI][nJ] % i) == 0)
		{
			isPrime = 0; // число не простое
		}
	}
	if (numReading[nI][nJ] == 1)
	{
		isPrime = 0; // число не простое
	}
	return isPrime;
}

int ifPrime(int isPrime, double numReading[50][50], int& nI, int& nJ) // определяем простое число или нет
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

void decreasSort(int numberOfPrime[100], int numReading[50][50], int &N, int &M) // сортировка
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

void testim(int &test1, int &test2)
{
	test1+=test2;
	cout << test1 << " ";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int N, M; //количество столбцов и строк
	ifstream in("input.txt"); // имя файла и спецификатор (для чтения)
	ofstream out("output.txt"); // имя файла и спецификатор (для вывода)
	int numReading[50][50]; // матрица
	int numberOfPrimeInLine = 0; // количество простых в одной строке
	int isPrime = 1; //счетчик простых чисел
	int numberOfPrime[100]; // массив для хранения количества простых чисел в каждой строке
	int sortTrue = 0; //потребность в сортировке

	inF(numReading, N, M); // считываем файл
	int max = findMax(numReading, N, M); // находим максимальное значение

	for (int nI = 0; nI < M; nI++) // считаем количество простых чисел в строках
	{
		for (int nJ = 0; nJ < N; nJ++)
		{
			if (numReading[nI][nJ] == max) // проверяем на повтор максимального значения
				sortTrue += 1; // максимальное значение повторилось
			numberOfPrimeInLine += ifPrime(isPrime, numReading, nI, nJ); // считаем количество простых в строке
		}
		numberOfPrime[nI] = numberOfPrimeInLine; // строка закончилась -> запоминаем количество простых в ней
		numberOfPrimeInLine = 0; // обновляем счетчик для следующей строки
	}

	if (sortTrue > 1)//максимальное повторилось -> сортируем
	{
		decreasSort(numberOfPrime, numReading, N, M);
		outF(numReading, N, M, numberOfPrime); //выводим полученную матрицу
	}
	else // максимальное одно -> сортировка не нужна
	{
		outF(numReading, N, M, numberOfPrime); // выводим полученную матрицу
	}
	
	
	
	int test1 = 1;
	int test2 = 2;
	testim (test1, test2);
	cout << test1;
	return 0;
}