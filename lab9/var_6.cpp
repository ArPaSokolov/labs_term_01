/*Найти периметр треугольника. (сторона1, сторона2, сторона3)*/

#include <iostream>
using namespace std;

class triangle //класс
{
private: //модификатор доступа
	int A; //поле
	int B; //поле
	int C; //поле
public: //модификатор доступа
	triangle(int valueA, int valueB, int valueC) // constructor
	{
		A = valueA;
		B = valueB;
		C = valueC;
	}
	void SetSides(int valueA, int valueB, int valueC) //(метод) задаем значение
	{
		A = valueA;
		B = valueB;
		C = valueC;
	}
	int GetA() // (метод) получаем значение
	{
		return A;
	}
	int GetB() //(метод) получаем значение
	{
		return B;
	}
	int GetC() //(метод) получаем значение
	{
		return C;
	}
	int Perimetr()
	{
		int valueP = A + B + C;
		return valueP;
	}
	void Show()
	{
		cout << "A is: " << A << endl;
		cout << "B is: " << B << endl;
		cout << "C is: " << C << endl;
	}
	~triangle() // destructor
	{
		cout << "Destruction succeded!" << endl;
	}

};
int main()
{
	cout << "Enter 3 sides:" << endl;
	int valueA;
	int valueB;
	int valueC;
	cin >> valueA;
	cin >> valueB;
	cin >> valueC;
	while (valueA <= 0 or valueC <= 0 or valueB <= 0 or (valueA + valueB <= valueC) or (valueA + valueC <= valueB) or (valueB + valueC <= valueA))
	{
		cout << "The values are incorrect. Enter new ones:" << endl;
		cin >> valueA;
		cin >> valueB;
		cin >> valueC;
	}

	triangle ABC(valueA, valueB, valueC); //обЪект

	/*ABC.SetSides();*/
	cout << "Perimetr is: " << ABC.Perimetr() << endl;
	ABC.Show();

	return 0;
}