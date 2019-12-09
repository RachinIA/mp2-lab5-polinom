//#pragma once
#include <iostream>
#include "THeadRing.h"
#include "TMonom.h"

using namespace std;

class TPolinom : public THeadRing
{
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор
										  // полинома из массива «коэффициент-индекс»
	TPolinom(TPolinom& q);                  // конструктор копирования
	PTMonom GetMonom() { return (PTMonom)GetDataValue(); }
	TPolinom& operator+=(TPolinom& q);                                  // сложение полиномов
	TPolinom& operator=(TPolinom& q);                                  // присваивание
	int CalculatePolinom(int x, int y, int z);                         //Вычисление значения полинома
	TPolinom& Integration(bool x = true, bool y = true, bool z = true); //Интегрирование,по какой переменной
	friend ostream& operator<<(ostream& os, TPolinom& q);
	friend istream& operator>>(istream& is, TPolinom& q);
	bool operator==(TPolinom& q);
};
