#include "stdafx.h"
#include "Category.h"

Category::Category(HMODULE hMod) : mnCurrentProductIndex(0), mnArrProductSize(DEFAULT_NUMBER_OF_PRODUCTS)
{
	mhMod = hMod;

	mppArrProducts = new Product*[mnArrProductSize];
	ZeroMemory(mppArrProducts, mnArrProductSize*sizeof(Product*));

	try{
		pGFA = (GetFactoryType)GetProcAddress(mhMod, "GetNewAliveFactory");
		pGFT = (GetFactoryType)GetProcAddress(mhMod, "GetNewToolsFactory");
		pGA = (GetProductType)GetProcAddress(mhMod, "GetNewAlive");
		pGT = (GetProductType)GetProcAddress(mhMod, "GetNewTool");
		if (pGFA == NULL)  throw 2;
		if (pGFT == NULL)  throw 3;
		if (pGA == NULL)  throw 4;
		if (pGT == NULL)  throw 5;
	}
	catch (int nErrNum){
		switch (nErrNum){
		case 2:
			cout << "Error in pGFA =  (GetFactory)GetProcAddress(hMod, \"GetNewAliveFactory\");" << endl;
			FreeLibrary(hMod);
			break;
		case 3:
			cout << "Error in pGFT =  (GetFactory)GetProcAddress(hMod, \"GetNewToolsFactory\");" << endl;
			FreeLibrary(hMod);
			break;
		case 4:
			cout << "Error in pGA =  GetNewAlive;" << endl;
			FreeLibrary(hMod);
			break;
		case 5:
			cout << "Error in pT =  GetNewTool" << endl;
			FreeLibrary(hMod);
			break;
		}
	}
}

Category::~Category()
{
	delete mpBaseFactory;
	delete mpBaseInput;
	delete mpBaseOutput;
	delete mpBaseSave;
	delete mpBaseLoad;

	for (int i = 0; i < mnCurrentProductIndex; i++){ //delete all Products
		delete mppArrProducts[i];
	}
	delete []mppArrProducts;
}

void Category::CreateAliveFactory(){
	if (dynamic_cast<ToolsFactory*>(mpBaseFactory)) delete mpBaseFactory;
		mpBaseFactory = pGFA();
		if (mpBaseFactory == NULL) {
			cout << "Error in mpBaseFactory = pGFA();" << endl;
			FreeLibrary(mhMod);
			return;
		}
}

Product** Category::GetArrProducts(){
	return mppArrProducts;
}

int& Category::GetCurrentProductIndex(){
	return mnCurrentProductIndex;
}

void Category::CreateToolsFactory(){
	if (dynamic_cast<AliveFactory*>(mpBaseFactory)) delete mpBaseFactory;
		mpBaseFactory = pGFT();
		if (mpBaseFactory == NULL) {
			cout << "Error in mpBaseFactory = pGFT();" << endl;
			FreeLibrary(mhMod);
			return;
		}
}

void Category::CreateAlive(){
	mpProduct = pGA();
	if (mpProduct == NULL) {
		cout << "Error in mpProduct = pGA();" << endl;
		FreeLibrary(mhMod);
		return;
	}
	AddAliveToProductArray();
}

void Category::CreateTool(){
	mpProduct = pGT();
	if (mpProduct == NULL) {
		cout << "Error in mpProduct = pGT();" << endl;
		FreeLibrary(mhMod);
		return;
	}
	AddToolToProductArray();
}

void Category::AddToolToProductArray(){
	if ((mnCurrentProductIndex + 1) == mnArrProductSize){
		//Expand Array
		Product **ppProductsTemp = new Product*[2 * mnArrProductSize];
		memcpy(ppProductsTemp, mppArrProducts, mnArrProductSize*sizeof(Product*));
		mnArrProductSize *= 2;
		delete[]mppArrProducts;
		mppArrProducts = ppProductsTemp;
		ZeroMemory(&mppArrProducts[mnCurrentProductIndex], (mnArrProductSize - mnCurrentProductIndex)*sizeof(Product*));
	}
	mppArrProducts[mnCurrentProductIndex] = mpProduct;
	mnCurrentProductIndex++;
}

void Category::AddAliveToProductArray(){
	if ((mnCurrentProductIndex + 1) == mnArrProductSize){
		//Expand Array
		Product **ppProductsTemp = new Product*[2 * mnArrProductSize];
		memcpy(ppProductsTemp, mppArrProducts, mnArrProductSize*sizeof(Product*));
		mnArrProductSize *= 2;
		delete []mppArrProducts;
		mppArrProducts = ppProductsTemp;
		ZeroMemory(&mppArrProducts[mnCurrentProductIndex], (mnArrProductSize - mnCurrentProductIndex)*sizeof(Product*));
	}
	mppArrProducts[mnCurrentProductIndex] = mpProduct;
	mnCurrentProductIndex++;
}

void Category::DeleteProductFromArrProducts(Product *pProduct){
	Product *pRest = 0;
	for (int i = 0; i < mnCurrentProductIndex; i++){
		if (mppArrProducts[i] == pProduct){
			delete pProduct;
			for (int j = i; j < mnCurrentProductIndex - 1; j++){
				mppArrProducts[j] = mppArrProducts[j + 1];
			}
			mnCurrentProductIndex--;
			mppArrProducts[mnCurrentProductIndex] = NULL;
			return;
		}
	}
	cout << "There is no product in array" << endl;
}

void Category::SetBaseFactory(BaseFactory *pBaseFactory){
	mpBaseFactory = pBaseFactory;
}
void Category::SetBaseInput(BaseInput *pBaseInput){
	mpBaseInput = mpBaseInput;
}
void Category::SetBaseOutput(BaseOutput *pBaseOutput){
	mpBaseOutput = pBaseOutput;
}
void Category::SetBaseSave(BaseSave *pBaseSave){
	mpBaseSave = pBaseSave;
}
void Category::SetBaseLoad(BaseLoad *pBaseLoad){
	mpBaseLoad = pBaseLoad;
}
Product * Category::GetAlive(){
	return mpProduct;
}
Product * Category::GetTool(){
	return mpProduct;
}
BaseFactory* Category::GetBaseFactory(){
	return mpBaseFactory;
}
BaseInput* Category::GetBaseInput(){
	return mpBaseInput;
}
BaseOutput* Category::GetBaseOutput(){
	return mpBaseOutput;
}
BaseSave* Category::GetBaseSave(){
	return mpBaseSave;
}
BaseLoad* Category::GetBaseLoad(){
	return mpBaseLoad;
}
Product* Category::GetProduct(){
	return mpProduct;
}