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
		for (int  inJ = 0; inJ < N; inJ++)
			in >> numReading[inI][inJ];
	}
}

void outF(ofstream& out, int numReading[50][50], int N, int M)// процедура выведения файла
{
	for (int oI = 0; oI < M; oI++)
	{
		for (int oJ = 0; oJ < N; oJ++)
			out << numReading[oI][oJ] << " ";
		out << '\n';
	}
}

int isPrime(int ifPrime, int number) // определяем простое число или нет
{
	ifPrime = 1;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if ((number % i) == 0)
		{
			ifPrime = 0; // число не простое
		}
	}
	return ifPrime;
}

void decreasSort(int numOfPrime[], int numReading[50][50], int M, int N)
{
	for (int sI = 0; sI < M; sI++)
	{
		int s = sI;
		while (s > 0 and numOfPrime[s - 1] < numOfPrime[s])
		{
			swap(numOfPrime[s], numOfPrime[s - 1]);
			for (int sJ = 0; sJ < N; sJ++)
				swap(numReading[s][sJ], numReading[s - 1][sJ]);
			s = s - 1;
		}
	}
}

int findMaxNum(int numReading[50][50], int maxNum, int M, int N)
{
	for (int mI = 0; mI<M;mI++)
		for (int mJ = 0; mJ < M; mJ++)
		{
			if (numReading[mI][mJ] > maxNum)
				maxNum = numReading[mI][mJ];
		}
	return maxNum;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in("input.txt"); // имя файла и спецификатор (для чтения)
	ofstream out("output.txt"); // имя файла и спецификатор (для вывода)
	int numReading[50][50];// масив для чтения матрицы
	int number;//элемент матрицы (для проверки на простоту)
	int numOfPrime[50];//число простых в строчке
	int N, M; //количество столбцов и строк
	int ifPrime = 1;//флаг на простоту числа (0 - не простое, 1 - простое)
	int maxNum = INT_MIN;
	int maxNumCounter = 0;
	in >> N;
	in >> M;

	inF(in, numReading, N, M);//читаем файл
	
	maxNum=findMaxNum(numReading, maxNum, M, N);// нашли максимальное

	for (int pI = 0; pI < M; pI++)// считаем кол-во простых в строчке
	{
		numOfPrime[pI] = 0;// новая строчка => обновляем счетчик
		for (int pJ = 0; pJ < N; pJ++)
		{
			number = numReading[pI][pJ];
			if (number == maxNum)
				maxNumCounter++;// считаем количество макимальных
			if (isPrime(ifPrime, number) == 1)
				numOfPrime[pI]++;//нашли простое
		}
	}
	if (maxNumCounter > 1)// если нашлось несколько максисальных - сортируем
	{
		decreasSort(numOfPrime, numReading, M, N);//сортируем строчки по кол-ву простых в них
		outF(out, numReading, N, M);// выводим файл
	}
	else//не нашлось - не сортируем
		outF(out, numReading, N, M);// выводим файл


	return 0;
}
