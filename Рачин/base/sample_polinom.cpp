#include <iostream>
#include "TPolinom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int input = 0;
	int x, y, z;
	cout << "������������ ���������..." << endl;
	cout << "1.���� �������� � ����������"<<endl<<"2.������������ �������� ��������" << endl;
	cin >> input;
	TPolinom* P1;
	TPolinom* P2;
	if (input == 1)
	{
		P1 = new TPolinom();
		P2 = new TPolinom();
		cout << "������� ������ �������:" << endl;
		cin >> *P1;
		cout << "������� ������ �������:" << endl;
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
	cout << "1 �������" << endl
		<< *P1 << endl;
	cout << "2 �������" << endl
		<< *P2 << endl;
	cout << "����� ��������� :" << endl
		<< (*P1 += *P2);
	cout << "\n���������� �������� � �����:" << endl;
	cout << "������� x" << endl;
	cin >> x;
	cout << "������� y" << endl;
	cin >> y;
	cout << "������� z" << endl;
	cin >> z;
	cout << "������� 1 = " << P1->CalculatePolinom(x, y, z) << endl;
	cout << "������� 2 = " << P2->CalculatePolinom(x, y, z) << endl;
	cout << "������������� ��������" << endl;
	cout << "�������� ���������� ��� ��������������:" << endl;
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
	cout << "������� 1 = " << r << endl;
	r = P2->Integration(x, y, z);
	cout << "������� 2 = " << r << endl;
}

