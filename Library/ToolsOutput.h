#pragma once
#include "BaseOutput.h"
#include "Tools.h"


class ToolsOutput :
	public BaseOutput
{
private:
	Tools *mpTool = 0;
	Product **mppArrProducts = 0;
	int mnCurrentProductIndex = 0;

public:
	ToolsOutput();
	~ToolsOutput();
	void SetProduct(Product *pTool);
	void SetOutputData(Product **mppArrProducts, int mnCurrentProductIndex);
	Tools* GetProduct();
	virtual Tools* GetProductById(int id);
	virtual double GetPrice();
	virtual char* GetName();
	virtual int GetWarranty();
	virtual void ShowAll();
};

