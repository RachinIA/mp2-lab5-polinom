#pragma once
//#include "TDataList.h"
#include "TDataValue.h"
#include <iostream>
class TRootLink;
typedef TRootLink* PTRootLink;
class TRootLink
{
protected:
	PTRootLink pNext; // указатель на следующее звено
public:
	TRootLink(PTRootLink pN = NULL) { pNext = pN; }
	PTRootLink GetNextLink() { return pNext; }
	void SetNextLink(PTRootLink pLink) { pNext = pLink; }
	void InsNextLink(PTRootLink pLink)
	{
		PTRootLink p = pNext;
		pNext = pLink;
		if (pLink != NULL)
			pLink->pNext = p;
	}
	virtual void SetDataValue(PTDataValue pVal) = 0;
	virtual PTDataValue GetDataValue() = 0;

	friend class TDatList;
};