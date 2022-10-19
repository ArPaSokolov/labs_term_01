/*Дан файл, содержащий русский текст,
размер текста не превышает 10 К байт.
Найти в тексте N(N ≤ 100) слов,
содержащих наибольшее количество сочетаний из двух согласных.
Записать найденные слова в текстовый файл
в порядке убывания количества сочетаний.
Для каждого слова вывести также количество сочетаний
из двух согласных.Все найденные слова должны быть разными.
Число N вводить из файла.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	bool consonatesCount = false;
	int N;
	string wordReading[100]; // массив для пробега по файлу
	string okWords[100]; // массив , в который закидываем слова с комбинациями согласных
	string word; // слово проверяемое на сочетания согласных
	int numOkWords[100]; // массив в который закидываем количество комбинаций
	for (int zero = 0; zero < 100; zero++)
	{
		numOkWords[zero] = 0;
	}
	int numberOfWordsInFile = 0;// количество слов в файле
	char consonates[43] = "йцкнгшщзхфвпрлджчсмтбЙЦКНГШЩЗХФВПРЛДЖЧСМТБ";
	int numEnter = 0; // сколько слов выводить в ответе
	ifstream in("input.txt"); // имя файла и спецификатор (для чтения)
	ofstream out("output.txt"); // имя файла и спецификатор (для вывода)
	in >> N;
	int i = 0;
	while (!in.eof()) //бежим по файлу 
	{
		int c = 0; // счетчик сочетаний
		in >> wordReading[i];
		word = wordReading[i];
		numberOfWordsInFile++;
		while (ispunct(word[word.length() - 1]))
		{
			word.erase(word.length() - 1);
		}
		for (int letterNum = 1; letterNum < ((word.length())); letterNum++) // бежим по буквам слова
		{
			for (int sonsonateNum = 0; sonsonateNum < 42; sonsonateNum++) // бежим по согласным
			{
				for (int sonsonateNumTwo = 0; sonsonateNumTwo < 42; sonsonateNumTwo++) // бежим по согласным
				{

					if (word[letterNum] == consonates[sonsonateNum] and word[letterNum - 1] == consonates[sonsonateNumTwo])
					{
						c++;
						consonatesCount = true;
					}

				}
			}
			numOkWords[i] = c;
		}
		okWords[i] = word;
		i = i + 1; // берем следующее слово

	}

	if (consonatesCount = true) // сочетания нашлись
	{
		for (int a = 1; a < numberOfWordsInFile + 1; a++) // сортировка
		{
			int b = a;
			while (b > 0 and numOkWords[b - 1] < numOkWords[b]) // бежим по элементам стоящим cлева, пока выполняется условие
			{
				swap(numOkWords[b], numOkWords[b - 1]);// меняемся местами с элементом стоящим слева
				swap(okWords[b], okWords[b - 1]);
				b = b - 1;
			}
		}
		for (int j = 0; j < N; j++)
		{
			bool uniq = true;
			for (int u = 0; u < j; u++)
			{
				if (okWords[j] == okWords[u]) 
				{
					uniq = false;
				}
			}
			if (uniq)
			{
				out << "В слове '" << okWords[j] << "' сочетаний: " << numOkWords[j] << '\n';
				cout << "В слове '" << okWords[j] << "' сочетаний: " << numOkWords[j] << '\n';
			}
		}
	}
	else
	{
		cout << "В тексте нет сочетаний";
	}


	return 0;
}
