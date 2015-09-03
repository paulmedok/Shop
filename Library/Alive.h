#pragma once
#include "Product.h"

class Alive :
	public Product
{
private:
	double mPrice;
	char *mName = 0;
	char* mColor = 0;
public:
	Alive(char* name = 0, char* color = 0, double price = 0);
	Alive(const Alive &Right);
	~Alive();
	virtual void SetPrice(double price);
	virtual double GetPrice();
	virtual void SetName(char *name);
	virtual char* GetName();
	virtual void SetColor(char *name);
	virtual char* GetColor();
};

