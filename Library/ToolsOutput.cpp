#include "stdafx.h"
#include "ToolsOutput.h"

ToolsOutput::ToolsOutput(){}

ToolsOutput::~ToolsOutput(){}

double ToolsOutput::GetPrice(){
	return mpTool->GetPrice();
}

char* ToolsOutput::GetName(){
	return mpTool->GetName();
}

int ToolsOutput::GetWarranty(){
	return mpTool->GetWarranty();
}

void ToolsOutput::SetProduct(Product *pAlive){
	mpTool = dynamic_cast<Tools*>(pAlive);
}

Tools* ToolsOutput::GetProduct(){
	return mpTool;
}

void ToolsOutput::SetOutputData(Product **ppArrProducts, int nCurrentProductIndex){
	mppArrProducts = ppArrProducts;
	mnCurrentProductIndex = nCurrentProductIndex;
}

Tools* ToolsOutput::GetProductById(int id){
	Tools *pToolsTemp = 0;
	int tempCount = 0;
	for (int i = 0; i <= mnCurrentProductIndex; i++){
		if (pToolsTemp = dynamic_cast<Tools*>(mppArrProducts[i])){
			if ((tempCount + 1) == id){
				return pToolsTemp;
			}
			tempCount++;
		}
	}
	if (tempCount == 0) return NULL;
}

void ToolsOutput::ShowAll(){
	Tools *pToolTemp = 0;
	int tempCount = 0;
	for (int i = 0; i <= mnCurrentProductIndex; i++){
		if (pToolTemp = dynamic_cast<Tools*>(mppArrProducts[i])){
			cout << "# " << tempCount + 1 << endl;
			cout << "Tool NAME: " << pToolTemp->GetName() << endl;
			cout << "Tool WARRANTY: " << pToolTemp->GetWarranty() << endl;
			cout << "Tool PRICE: " << pToolTemp->GetPrice() << endl;
			tempCount++;
		}
	}
	if (tempCount == 0)
		cout << "There are no Tools products in the Shop" << endl;
	cout << "- - - - - " << endl;
}