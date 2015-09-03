#ifndef _ToolsFactory
#define _ToolsFactory

#include "BaseFactory.h"
#include "ToolsInput.h"
#include "ToolsOutput.h"
#include "ToolsSave.h"
#include "ToolsLoad.h"
#include "Tools.h"

class ToolsFactory :
	public BaseFactory
{
private:
	ToolsInput  *mpToolsInput = 0;
	ToolsOutput *mpToolsOutput = 0;
	ToolsSave   *mpToolsSave = 0;
	ToolsLoad   *mpToolsLoad = 0;
	Tools       *mpTool = 0;
	Product **mppArrProducts = 0;
	int mnCurrentProductIndex = 0;

public:
	ToolsFactory();
	void CreateInput();
	void CreateOutput();
	void CreateLoad();
	void CreateSave();
	void SetProduct(Product *pProduct);
	void SetOutputData(Product **mppArrProducts, int mnCurrentProductIndex);
	Tools* GetProduct();
	virtual ToolsInput* GetToolsInput();
	virtual ToolsOutput* GetToolsOutput();
	virtual ToolsSave* GetToolsSave();
	virtual ToolsLoad* GetToolsLoad();
	~ToolsFactory();
};

#endif