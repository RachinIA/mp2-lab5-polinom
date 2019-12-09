#include <cmath>
#include <string>
#include "TPolinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDataValue(pMonom);
	for (int i = 0; i < km; i++)
	{
		if (monoms[i][1] > 999 || monoms[i][1] < 0)
			throw "Wrong power";
		pMonom = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(pMonom);
	}
}
TPolinom::TPolinom(TPolinom& q)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDataValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy()); 
	}
	
}
TPolinom& TPolinom::operator=(TPolinom& q)
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
	return *this;
	
}
TPolinom& TPolinom::operator+=(TPolinom& q)
{
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (true)
	{
		pm = GetMonom();
		qm = q.GetMonom();
		if (pm->Index < qm->Index)
		{ 
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->Index > qm->Index)
			GoNext();
		else
		{
			if (pm->Index == -1)
				break;
			pm->Coeff += qm->Coeff;
			if (pm->Coeff != 0)
			{
				GoNext();
				q.GoNext();
			}
			else
			{
				DelCurrent();
				q.GoNext();
			}
		}
	}
	return *this;
}
ostream& operator<<(ostream& os, TPolinom& q)
{
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
		cout << *q.GetMonom();
	return os;
}
istream& operator>>(istream& is, TPolinom& q)
{
	int coeff = 0;
	int amountOfMonom = 0;
	string indexStr;
	if (q.ListLen != 0)
		q.DelList();
	cout << "Введите количество мономов" << endl;
	is >> amountOfMonom;
	for (q.Reset(); q.CurrPos < amountOfMonom; q.GoNext())
	{
		std::cout << "Введите коэффициент монома" << std::endl;
		is >> coeff;
		if (coeff == 0)
			continue;
		std::cout << "Введите свёртку степеней(x,y,z)"
			<< endl
			<< "(3-ёх значное число,подряд без раздилителей" << std::endl;
		is >> indexStr;
		if (indexStr.length() > 3)
			throw "Wrong power";
		for (int i = 0; i < indexStr.length(); i++)
		{
			if (isdigit(indexStr[i]) == 0)
				throw "Wrong power";
		}

		PTMonom temp = new TMonom(coeff, atoi(indexStr.c_str()));
		q.InsLast(temp);
	}
	return is;
}
int TPolinom::CalculatePolinom(int x, int y, int z)
{
	int result = 0;
	for (Reset(); !IsListEnded(); GoNext())
	{
		int powX = GetMonom()->Index / 100;
		int powY = (GetMonom()->Index / 10) % 10;
		int powZ = GetMonom()->Index % 10;
		result += GetMonom()->Coeff * pow(x, powX) * pow(y, powY) * pow(z, powZ);
	}
	return result;
}
TPolinom& TPolinom::Integration(bool x, bool y, bool z)
{
	for (Reset(); !IsListEnded(); GoNext())
	{
		if (x)
		{
			GetMonom()->Index += 100;
			GetMonom()->Coeff /= (GetMonom()->Index / 100);
		}
		if (y)
		{
			GetMonom()->Index += 10;
			GetMonom()->Coeff /= ((GetMonom()->Index / 10) % 10);
		}
		if (z)
		{
			GetMonom()->Index += 1;
			GetMonom()->Coeff /= GetMonom()->Index % 10;
		}
	}
	return *this;
}

bool TPolinom::operator==(TPolinom& q)
{
	Reset();
	q.Reset();
	while (true)
	{
		if (IsListEnded() || q.IsListEnded())
		{
			if (IsListEnded() && q.IsListEnded())
				return true;
			return false;
		}
		if (*GetMonom() != *q.GetMonom())
			return false;
		GoNext();
		q.GoNext();
	}
}