#include "TMonom.h"

TDataValue* TMonom::GetCopy()
{
	TDataValue* temp = new TMonom(Coeff, Index);
	return temp;
}
ostream& operator<<(ostream& os, TMonom& q)
{
	int powX = q.Index / 100;
	int powY = (q.Index / 10) % 10;
	int powZ = q.Index % 10;
	if (q.Coeff != 0)
	{
		os << " " << q.Coeff;
		if (powX != 0)
			os << "X^" << powX;
		if (powY != 0)
			os << "Y^" << powY;
		if (powZ != 0)
			os << "Z^" << powZ;
	}
	return os;
}