#pragma once
//class TDataValue;
class TDataValue
{
public:
	~TDataValue() {}
	virtual TDataValue* GetCopy() = 0; // создание копии	
};

typedef TDataValue* PTDataValue;
