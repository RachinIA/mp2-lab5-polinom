#pragma once
#include "TDataLink.h"
#include "DataValue.h"
enum TLinkPos { FIRST, CURRENT, LAST };
class TDataList
{
protected:
	PTDataLink pFirst;    // первое звено
	PTDataLink pLast;     // последнее звено
	PTDataLink pCurrLink; // текущее звено
	PTDataLink pPrevLink; // звено перед текущим
	PTDataLink pStop;     // значение указателя, означающего конец списка
	int CurrPos;         // номер текущего звена (нумерация от 0)
	int ListLen;         // количество звеньев в списке
protected:             // методы
	PTDataLink GetLink(PTDataValue pVal = NULL, PTDataLink pLink = NULL);
	void DelLink(PTDataLink pLink); // удаление звена
public:
	TDataList();
	~TDataList() { DelList(); }
	// доступ
	PTDataValue GetDataValue(TLinkPos mode = CURRENT) const;  // значение
	virtual int IsEmpty() const { return pFirst == pStop; } // список пуст ?
	int GetListLength() const { return ListLen; }           // к-во звеньев
	// навигация
	int SetCurrentPos(int pos);          // установить текущее звено
	int GetCurrentPos(void) const;       // получить номер тек. звена
	virtual void Reset(void);             // установить на начало списка
	virtual int IsListEnded(void) const; // список завершен ?
	void GoNext(void);                    // сдвиг вправо текущего звена
										 // (=1 после применения GoNext для последнего звена списка)
	// вставка звеньев
	virtual void InsFirst(PTDataValue pVal = NULL);   // перед первым
	virtual void InsLast(PTDataValue pVal = NULL);    // вставить последним
	virtual void InsCurrent(PTDataValue pVal = NULL); // перед текущим
	// удаление звеньев
	virtual void DelFirst(void);   // удалить первое звено
	virtual void DelCurrent(void); // удалить текущее звено
	virtual void DelList(void);    // удалить весь список
};