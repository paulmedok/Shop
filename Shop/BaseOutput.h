#pragma once
#include "Product.h" 

class BaseOutput
{
public:
	BaseOutput(){};
	virtual ~BaseOutput(){};
	virtual double GetPrice() = 0;
	virtual char* GetName() = 0;
	virtual void ShowAll() = 0;
	virtual void SetOutputData(Product** ppArr, int num) = 0;
};

