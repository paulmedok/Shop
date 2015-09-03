#ifndef _BaseFactory
#define _BaseFactory

#include "Product.h"

class BaseFactory
{
public:
	virtual void CreateInput() = 0;
	virtual void CreateOutput() = 0;
	virtual void CreateSave() = 0;
	virtual void CreateLoad() = 0;
	virtual void SetProduct(Product *pProduct) = 0;
	virtual void SetOutputData(Product **mppArrProducts, int mnCurrentProductIndex) = 0;
	virtual Product* GetProduct() = 0;
	virtual ~BaseFactory(){};
};

#endif