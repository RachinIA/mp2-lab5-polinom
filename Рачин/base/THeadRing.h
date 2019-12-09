#pragma once
#include "TDataList.h"
//#include "TDataLink.h"
//#include "TDataValue.h"
class THeadRing : public TDataList
{
protected:
	PTDataLink pHead; // заголовок, pFirst - звено за pHead
public:
	THeadRing();
	~THeadRing();
	// вставка звеньев
	virtual void InsFirst(PTDataValue pVal = NULL); // после заголовка
	// удаление звеньев
	virtual void DelFirst(void); // удалить первое звено
};

