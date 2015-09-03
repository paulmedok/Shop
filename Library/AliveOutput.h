#pragma once
#include "BaseOutput.h"
#include "Alive.h"

class AliveOutput :
	public BaseOutput
{
private:
	Alive *mpAlive;
	Product **mppArrProducts = 0;
	int mnCurrentProductIndex = 0;

public:
	AliveOutput();
	~AliveOutput();
	void SetProduct(Product *pAlive);
	void SetOutputData(Product **mppArrProducts, int mnCurrentProductIndex);
	Alive* GetProduct();
	virtual Alive* GetProductById(int id);
	virtual double GetPrice();
	virtual char* GetName();
	virtual char* GetColor();
	virtual void ShowAll();
};

