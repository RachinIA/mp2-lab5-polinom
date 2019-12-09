#include <iostream>
#include "TPolinom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int input = 0;
	int x, y, z;
	cout << "Тестирование программы..." << endl;
	cout << "1.Ввод полинома с клавиатуры"<<endl<<"2.Использовать тестовые полиномы" << endl;
	cin >> input;
	TPolinom* P1;
	TPolinom* P2;
	if (input == 1)
	{
		P1 = new TPolinom();
		P2 = new TPolinom();
		cout << "Введите первый полином:" << endl;
		cin >> *P1;
		cout << "Введите второй полином:" << endl;
		cin >> *P2;
	}
	else
	{
		int tmp1[][2] = { {2, 421}, {2, 432}, {5, 321}, {4, 213}, {9, 100} };
		int Size1 = sizeof(tmp1) / (2 * sizeof(int));
		P1 = new TPolinom(tmp1, Size1);
		int tmp2[][2] = { {2, 432}, {4, 412}, {-5, 365}, {8, 110}, {10, 50} };
		int Size2 = sizeof(tmp2) / (2 * sizeof(int));
		P2 = new TPolinom(tmp2, Size2);
	}
	cout << "1 Полином" << endl
		<< *P1 << endl;
	cout << "2 Полином" << endl
		<< *P2 << endl;
	cout << "Сумма полиномов :" << endl
		<< (*P1 += *P2);
	cout << "\nВычисление полинома в точке:" << endl;
	cout << "Введите x" << endl;
	cin >> x;
	cout << "Введите y" << endl;
	cin >> y;
	cout << "Введите z" << endl;
	cin >> z;
	cout << "Полином 1 = " << P1->CalculatePolinom(x, y, z) << endl;
	cout << "Полином 2 = " << P2->CalculatePolinom(x, y, z) << endl;
	cout << "Интегррование полинома" << endl;
	cout << "Выберите переменную для интегрирования:" << endl;
	char Input1 = 0;
	cout << "x?(y/n)" << endl;
	cin >> Input1;
	if (Input1 == 'y')
		x = 1;
	else
		x = 0;
	cout << "y?(y/n)" << endl;
	cin >> Input1;
	if (Input1 == 'y')
		y = 1;
	else
		y = 0;
	cout << "z?(y/n)" << endl;
	cin >> Input1;
	if (Input1 == 'y')
		z = 1;
	else
		z = 0;
	TPolinom r;
	r = P1->Integration(x, y, z);
	cout << "Полином 1 = " << r << endl;
	r = P2->Integration(x, y, z);
	cout << "Полином 2 = " << r << endl;
}

