#pragma once
#include "Product.h"

class BaseInput
{
public:
	BaseInput(){};
	virtual ~BaseInput(){};
	virtual void SetProduct(Product *pProduct) = 0;
	virtual Product* GetProduct() = 0;
};

