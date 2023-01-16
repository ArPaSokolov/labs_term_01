#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите значение площади основания пирамиды:\n";
    double S;
    cin >> S;
    cout << "Введите значение высоты пирамиды:\n";
    double h;
    cin >> h;
    cout << "Полученное значение объема:\n";
    double V;
    V = h * S;
    cout << V;
    return 0;

}
