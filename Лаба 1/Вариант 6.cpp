#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите значение стороны куба:\n";
	short A;
	cin >> A;
	short V;
	V = A * A * A;
	cout << "Полученное значение объема куба:\n";
	cout << V;
	return 0;
}