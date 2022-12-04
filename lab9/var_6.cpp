/*Ќайти периметр треугольника. (сторона1, сторона2, сторона3)*/

#include <iostream>
using namespace std;

class triangle //класс
{
private: //модификатор доступа
	int A; //поле
	int B; //поле
	int C; //поле
public: //модификатор доступа
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
		if ((A + B > C) and (A + C > B) and (B + C > A))
		{
			int valueP = A + B + C;
			return valueP;
		}
		else
		{
			return 0;
		}
	}
	void Show()
	{
		cout << "A is: " << A << endl;
		cout << "B is: " << B << endl;
		cout << "C is: " << C << endl;
	}

};
int main()
{
	cout << "Perimetr is: "<< "Enter 3 sides:" << endl;
	
	triangle ABC; //обЏект
	int valueA;
	int valueB;
	int valueC;
	cin >> valueA;
	cin >> valueB;
	cin >> valueC;

	ABC.SetSides(valueA, valueB, valueC);
	cout << "Perimetr is: " << ABC.Perimetr() << endl;
	ABC.Show();

	return 0;
}