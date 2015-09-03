#pragma once
#include"BaseFactory.h"
#include"BaseInput.h"
#include"BaseOutput.h"
#include"BaseSave.h"
#include"BaseLoad.h"
#include"Product.h"
#include"AliveFactory.h"
#include"ToolsFactory.h"

#define DEFAULT_NUMBER_OF_PRODUCTS 10
 
using namespace std;

typedef BaseFactory*(*GetFactoryType)();
typedef Product*(*GetProductType)();

class Category
{
private:
	BaseFactory *mpBaseFactory = 0;
	BaseInput *mpBaseInput = 0;
	BaseOutput *mpBaseOutput = 0;
	BaseSave *mpBaseSave = 0;
	BaseLoad *mpBaseLoad = 0;
	Product *mpProduct = 0;
	Product **mppArrProducts = 0;
	int mnCurrentProductIndex = 0;
	int mnArrProductSize = 0;

	HMODULE mhMod = 0;
	GetFactoryType pGFA;
	GetFactoryType pGFT;
	GetProductType pGA;
	GetProductType pGT;

	void AddAliveToProductArray();
	void AddToolToProductArray();

public:
	Category(HMODULE hMod);
	~Category();
	void SetBaseFactory(BaseFactory *pBaseFactory);
	void SetBaseInput(BaseInput *pBaseInput);
	void SetBaseOutput(BaseOutput *pBaseOutput);
	void SetBaseSave(BaseSave *pBaseSave);
	void SetBaseLoad(BaseLoad *pBaseLoad);
	Product* GetAlive();
	void CreateAliveFactory();
	void CreateToolsFactory();
	Product* GetTool();
	BaseFactory* GetBaseFactory();
	BaseInput* GetBaseInput();
	BaseOutput* GetBaseOutput();
	BaseSave* GetBaseSave();
	BaseLoad* GetBaseLoad();
	Product* GetProduct();
	void CreateAlive();
	void CreateTool();
	void DeleteProductFromArrProducts(Product *pProduct);
	Product** GetArrProducts();
	int& GetCurrentProductIndex();
};

