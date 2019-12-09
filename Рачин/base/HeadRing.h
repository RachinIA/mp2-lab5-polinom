#pragma once
#include "DataList.h"
#include "TDataLink.h"
#include "DataValue.h"
class THeadRing : public TDataList
{
protected:
	PTDataLink pHead; // ���������, pFirst - ����� �� pHead
public:
	THeadRing();
	~THeadRing();
	// ������� �������
	virtual void InsFirst(PTDataValue pVal = NULL); // ����� ���������
	// �������� �������
	virtual void DelFirst(void); // ������� ������ �����
};