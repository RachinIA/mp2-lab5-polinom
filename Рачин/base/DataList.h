#pragma once
#include "TDataLink.h"
#include "DataValue.h"
enum TLinkPos { FIRST, CURRENT, LAST };
class TDataList
{
protected:
	PTDataLink pFirst;    // ������ �����
	PTDataLink pLast;     // ��������� �����
	PTDataLink pCurrLink; // ������� �����
	PTDataLink pPrevLink; // ����� ����� �������
	PTDataLink pStop;     // �������� ���������, ����������� ����� ������
	int CurrPos;         // ����� �������� ����� (��������� �� 0)
	int ListLen;         // ���������� ������� � ������
protected:             // ������
	PTDataLink GetLink(PTDataValue pVal = NULL, PTDataLink pLink = NULL);
	void DelLink(PTDataLink pLink); // �������� �����
public:
	TDataList();
	~TDataList() { DelList(); }
	// ������
	PTDataValue GetDataValue(TLinkPos mode = CURRENT) const;  // ��������
	virtual int IsEmpty() const { return pFirst == pStop; } // ������ ���� ?
	int GetListLength() const { return ListLen; }           // �-�� �������
	// ���������
	int SetCurrentPos(int pos);          // ���������� ������� �����
	int GetCurrentPos(void) const;       // �������� ����� ���. �����
	virtual void Reset(void);             // ���������� �� ������ ������
	virtual int IsListEnded(void) const; // ������ �������� ?
	void GoNext(void);                    // ����� ������ �������� �����
										 // (=1 ����� ���������� GoNext ��� ���������� ����� ������)
	// ������� �������
	virtual void InsFirst(PTDataValue pVal = NULL);   // ����� ������
	virtual void InsLast(PTDataValue pVal = NULL);    // �������� ���������
	virtual void InsCurrent(PTDataValue pVal = NULL); // ����� �������
	// �������� �������
	virtual void DelFirst(void);   // ������� ������ �����
	virtual void DelCurrent(void); // ������� ������� �����
	virtual void DelList(void);    // ������� ���� ������
};