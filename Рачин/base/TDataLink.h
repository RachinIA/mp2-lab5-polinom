#pragma once
//#include "TDataValue.h"
#include "TRootLink.h"
class TDataLink;
typedef TDataLink* PTDataLink;

class TDataLink : public TRootLink
{
protected:
	PTDataValue pValue; // указатель на объект значения
public:
	TDataLink(PTDataValue pVal = NULL, PTRootLink pN = NULL) : TRootLink(pN)
	{
		pValue = pVal;
	}
	void SetDataValue(PTDataValue pVal) { pValue = pVal; }
	PTDataValue GetDataValue() { return pValue; }
	PTDataLink GetNextDataLink() { return (PTDataLink)pNext; }
	friend class TDataList;
};