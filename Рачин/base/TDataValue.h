#pragma once
//class TDataValue;
class TDataValue
{
public:
	~TDataValue() {}
	virtual TDataValue* GetCopy() = 0; // �������� �����	
};

typedef TDataValue* PTDataValue;
