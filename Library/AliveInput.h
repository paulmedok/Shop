#pragma once
#include "BaseInput.h"
#include "Alive.h"

class AliveInput :
	public BaseInput
{
private:
	Alive *mpAlive;
public:
	AliveInput();
	~AliveInput();
	void SetProduct(Product *pAlive);
	Alive* GetProduct();
	virtual void SetPrice(double price);
	virtual void SetName(char *name);
	virtual void SetColor(char *color);
};
