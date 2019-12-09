#include "THeadRing.h"
THeadRing::THeadRing() : TDataList()
{
	InsLast();
	pHead = pFirst;
	ListLen = 0;
	pStop = pHead;
	Reset();
	pFirst->SetNextLink(pFirst); 
}
THeadRing::~THeadRing()
{
	TDataList::DelList();
	DelLink(pHead);
	pHead = NULL;
}
void THeadRing::InsFirst(PTDataValue pVal)
{
	TDataList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}
void THeadRing::DelFirst(void)
{
	TDataList::DelFirst();
	pHead->SetNextLink(pFirst);
}