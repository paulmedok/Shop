#pragma once
#include "BaseInput.h"
#include "Tools.h"

class ToolsInput :
	public BaseInput
{
private:
	Tools *mpTool;
public:
	ToolsInput();
	~ToolsInput();
	void SetProduct(Product *pTool) ;
	Tools* GetProduct();
	virtual void SetPrice(double price);
	virtual void SetName(char *name);
	virtual void SetWarranty(int warranty);
};

