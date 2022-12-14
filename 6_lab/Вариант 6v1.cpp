/*Äàíà öåëî÷èñëåííàÿ ìàòðèöà {Aij}i=1...n;j=1..n ,
n<=100. Åñëè â ìàòðèöå åñòü åùå îäèí ýëåìåíò,
ðàâíûé åå ìàêñèìàëüíîìó ýëåìåíòó,
óïîðÿäî÷èòü ñòðîêè ìàòðèöû ïî óáûâàíèþ
êîëè÷åñòâà ïðîñòûõ ÷èñåë ñðåäè ýëåìåíòîâ ñòðîê.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void inF(ifstream& in, int numReading[50][50], int N, int M) //ïðîöåäóðà ÷òåíèÿ ôàéëà
{
	for (int inI = 0; inI < M; inI++)
	{
		for (int inJ = 0; inJ < N; inJ++)
			in >> numReading[inI][inJ];
	}
}

void outF(ofstream& out, int numReading[50][50], int N, int M)// ïðîöåäóðà âûâåäåíèÿ ôàéëà
{
	for (int oI = 0; oI < M; oI++)
	{
		for (int oJ = 0; oJ < N; oJ++)
			out << numReading[oI][oJ] << " ";
		out << '\n';
	}
}

int isPrime(int ifPrime, int number) // îïðåäåëÿåì ïðîñòîå ÷èñëî èëè íåò
{
	ifPrime = 1;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if ((number % i) == 0)
		{
			ifPrime = 0; // ÷èñëî íå ïðîñòîå
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
	for (int mI = 0; mI < M; mI++)
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
	ifstream in("input.txt"); // èìÿ ôàéëà è ñïåöèôèêàòîð (äëÿ ÷òåíèÿ)
	ofstream out("output.txt"); // èìÿ ôàéëà è ñïåöèôèêàòîð (äëÿ âûâîäà)
	int numReading[50][50];// ìàñèâ äëÿ ÷òåíèÿ ìàòðèöû
	int number;//ýëåìåíò ìàòðèöû (äëÿ ïðîâåðêè íà ïðîñòîòó)
	int numOfPrime[50];//÷èñëî ïðîñòûõ â ñòðî÷êå
	int N, M; //êîëè÷åñòâî ñòîëáöîâ è ñòðîê
	int ifPrime = 1;//ôëàã íà ïðîñòîòó ÷èñëà (0 - íå ïðîñòîå, 1 - ïðîñòîå)
	int maxNum = INT_MIN;
	int maxNumCounter = 0;
	in >> N;
	in >> M;

	inF(in, numReading, N, M);//÷èòàåì ôàéë

	maxNum = findMaxNum(numReading, maxNum, M, N);// íàøëè ìàêñèìàëüíîå

	for (int pI = 0; pI < M; pI++)// ñ÷èòàåì êîë-âî ïðîñòûõ â ñòðî÷êå
	{
		numOfPrime[pI] = 0;// íîâàÿ ñòðî÷êà => îáíîâëÿåì ñ÷åò÷èê
		for (int pJ = 0; pJ < N; pJ++)
		{
			number = numReading[pI][pJ];
			if (number == maxNum)
				maxNumCounter++;// ñ÷èòàåì êîëè÷åñòâî ìàêèìàëüíûõ
			if (isPrime(ifPrime, number) == 1)
				numOfPrime[pI]++;//íàøëè ïðîñòîå
		}
	}
	if (maxNumCounter > 1)// åñëè íàøëîñü íåñêîëüêî ìàêñèñàëüíûõ - ñîðòèðóåì
	{
		decreasSort(numOfPrime, numReading, M, N);//ñîðòèðóåì ñòðî÷êè ïî êîë-âó ïðîñòûõ â íèõ
		outF(out, numReading, N, M);// âûâîäèì ôàéë
	}
	else//íå íàøëîñü - íå ñîðòèðóåì
		outF(out, numReading, N, M);// âûâîäèì ôàéë


	return 0;
}