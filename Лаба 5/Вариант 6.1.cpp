/* Дана строка длиной не более 100 символов. 
Найти в ней позицию заданного символа или определить, 
что такого символа в строке нет.*/

#include <iostream>
using namespace std;

int main()
{
	char str[100];
	cout << "Enter the str:\n";
	cin >> str;	
	cout << "Enter the element:\n";
	char E;
	cin >> E;
	bool thereIs = false; // флаг на наличие введенного элемента в строке
	for (int i = 0; i < strlen(str); i++)
	{
		if (E == str[i]) //сравниваем введеный элемент с элементами строки
		{
			if (thereIs == false) // сбрасываем вывод "The position(s):" после первого срабатывания
			{
				cout << "The position(s):\n";
			}
			thereIs = true; // нашли элемент
			cout << i + 1 << " ";
		}
	}
	if (thereIs == false) // элемент не был найден
	{
		cout << "There is no '"<< E <<"' in str!\n";
	}
	
	return 0;
}