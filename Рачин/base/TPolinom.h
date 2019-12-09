//#pragma once
#include <iostream>
#include "THeadRing.h"
#include "TMonom.h"

using namespace std;

class TPolinom : public THeadRing
{
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // �����������
										  // �������� �� ������� ������������-������
	TPolinom(TPolinom& q);                  // ����������� �����������
	PTMonom GetMonom() { return (PTMonom)GetDataValue(); }
	TPolinom& operator+=(TPolinom& q);                                  // �������� ���������
	TPolinom& operator=(TPolinom& q);                                  // ������������
	int CalculatePolinom(int x, int y, int z);                         //���������� �������� ��������
	TPolinom& Integration(bool x = true, bool y = true, bool z = true); //��������������,�� ����� ����������
	friend ostream& operator<<(ostream& os, TPolinom& q);
	friend istream& operator>>(istream& is, TPolinom& q);
	bool operator==(TPolinom& q);
};
