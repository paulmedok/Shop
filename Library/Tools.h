#pragma once
#include "Product.h"

class Tools :
	public Product
{
private:
	double mPrice;
	char *mName = 0;
	int mnWarranty = 0;
public:
	Tools(char* name = 0, int warranty = 0, double price = 0);
	Tools(const Tools &Right);
	~Tools();
	virtual void SetPrice(double price);
	virtual double GetPrice();
	virtual void SetName(char *name);
	virtual char* GetName();
	virtual void SetWarranty(int warranty);
	virtual int GetWarranty();
};

