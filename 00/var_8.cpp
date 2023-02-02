/*Найти периметр треугольника. (сторона1, сторона2, сторона3)*/
/*
Написать класс
Методы Set, Get + любой доп
2 информационных поля
2 конструктора + деструктор
константы, указатели, ссылки
*/

#include <iostream>
using namespace std;

class rect // класс
{
private: // модификатор доступа
	int *A; // поле
	int *B; // поле
public: // модификатор доступа
	rect(int valueA, int valueB) // constructor 1
	{
		A = &valueA;
		B = &valueB;
	}
	rect() // constructor 2
	{
		A = new int;
		B = new int;
	}
	void SetSides(int valueA, int valueB) // (метод) задаем значение
	{
		A = &valueA;
		B = &valueB;
	}

	int GetA() // (метод) получаем значение
	{
		return *A;
	}

	int GetB() // (метод) получаем значение
	{
		return *B;
	}

	int Square() // (метод) находим площадь
	{
		//cout << "A is: " << *A << "  |  A adress is: " << A << endl;
		//cout << "B is: " << *B << "  |  B adress is: " << B << endl;
		int valueP = (*A) * (*B);
		//cout << "A is: " << *A << "  |  A adress is: " << A << endl;
		//cout << "B is: " << *B << "  |  B adress is: " << B << endl;
		/*cout << "valueP is: " << valueP << "  |  valueP adress is: " << valueP << endl;*/
		return valueP;
	}

	void Show() // (метод) выводим все данные
	{
		cout << "A is: " << *A << "  |  A adress is: " << A << endl;
		cout << "B is: " << *B << "  |  B adress is: " << B << endl;
	}

	~rect() // destructor
	{
		delete A;
		delete B;
	}

};
int main()
{
	cout << "Enter 2 sides:" << endl;
	int valueA;
	int valueB;
	cin >> valueA;
	cin >> valueB;


	rect AB (valueA, valueB); //обЪект

	/*AB.Show();*/
	/*AB.Square();*/
	int area = AB.Square();
	cout << "Square is: " << area << endl;
	int s = 2;
	AB.Show();

	return 0;
}