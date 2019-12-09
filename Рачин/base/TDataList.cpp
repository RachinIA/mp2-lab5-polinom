#include "TDataList.h"
TDataList::TDataList()
{
	pFirst = pLast = pStop = NULL;
	ListLen = 0;
	Reset();
}
PTDataLink TDataList::GetLink(PTDataValue pVal, PTDataLink pLink)
{
	PTDataLink temp = new TDataLink(pVal, pLink); // выделение звена
	if (temp == NULL)
		throw "List doesn't have memory!";
	return temp;
}
void TDataList::DelLink(PTDataLink pLink)
{
	if (pLink != NULL)
	{
		if (pLink->pValue != NULL)
			delete pLink->pValue;
		delete pLink;
	}
}
PTDataValue TDataList::GetDataValue(TLinkPos mode) const
{
	PTDataLink temp;
	switch (mode)
	{
	case FIRST:
		temp = pFirst;
		break;
	case LAST:
		temp = pLast;
		break;
	default:
		temp = pCurrLink;
		break;
	}
	return (temp == NULL) ? NULL : temp->pValue;
}

int TDataList::SetCurrentPos(int pos)
{
	Reset();
	for (int i = 0; i < pos; i++, GoNext());
	return 1;
}
int TDataList::GetCurrentPos(void) const
{
	return CurrPos;
}
void TDataList::Reset()
{
	pPrevLink = pStop;
	if (IsEmpty())
	{
		pCurrLink = pStop;
		CurrPos = -1;
	}
	else
	{
		pCurrLink = pFirst;
		CurrPos = 0;
	}
}
void TDataList::GoNext(void)
{
	if (pCurrLink != pStop)
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDataLink();
		CurrPos++;
	}
}

int TDataList::IsListEnded(void) const
{
	return pCurrLink == pStop;
}
void TDataList::InsFirst(PTDataValue pVal) //Вставить перед первым
{
	PTDataLink temp = GetLink(pVal, pFirst);
	if (temp != NULL)
	{
		pFirst = temp;
		ListLen++;
		if (ListLen == 1)
		{
			pLast = temp;
			Reset();
		}
		
		else if (CurrPos == 0)
			pCurrLink = temp;
		else
			CurrPos++;
	}
}
void TDataList::InsLast(PTDataValue pVal) 
{
	PTDataLink temp = GetLink(pVal, pStop);
	if (temp != NULL)
	{
		if (pLast != NULL)
			pLast->SetNextLink(temp);
		pLast = temp;
		ListLen++;
		if (ListLen == 1)
		{
			pFirst = temp;
			Reset();
		}
		if (IsListEnded())
			pCurrLink = temp;
	}
	else
		throw "ListNoMem";

}
void TDataList::InsCurrent(PTDataValue pVal) 
{
	if (IsEmpty() || pCurrLink == pFirst)
		InsFirst(pVal);
	else if (IsListEnded())
		InsLast(pVal);
	else if (pPrevLink == pStop)
		throw "List No Mem";
	else
	{
		PTDataLink temp = GetLink(pVal, pCurrLink);
		if (temp != NULL)
		{
			pCurrLink = temp;
			pPrevLink->SetNextLink(temp);
			ListLen++;
		}
	}
}
void TDataList::DelFirst(void)
{
	if (IsEmpty())
		throw "List is empty";
	else
	{
		PTDataLink temp = pFirst;
		pFirst = (PTDataLink)pFirst->GetNextLink();
		DelLink(temp);
		ListLen--;
	}
	if (IsEmpty())
	{
		pLast = pStop;
		Reset();
	}
	else if (CurrPos == 0)
		pCurrLink = pFirst;
	else if (CurrPos == 1)
		pPrevLink = pStop;
	if (CurrPos > 0)
		CurrPos--;
}
void TDataList::DelCurrent(void)
{
	if (pCurrLink == pStop)
		throw "No link in current position";
	else if (pCurrLink == pFirst)
		DelFirst();
	else
	{
		PTDataLink temp = pCurrLink;
		pCurrLink = pCurrLink->GetNextDataLink();
		pPrevLink->SetNextLink(pCurrLink);
		DelLink(temp);
		ListLen--;
		if (pCurrLink == pLast)
		{
			pLast = pPrevLink;
			pCurrLink = pStop;
		}
	}
}
void TDataList::DelList(void)
{
	while (!IsEmpty())
		DelFirst();
	pFirst = pLast = pStop = pCurrLink = pPrevLink;
	CurrPos = -1;
}
