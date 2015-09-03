#include "stdafx.h"
#include "ToolsFactory.h"
using namespace std;

ToolsFactory::ToolsFactory(){}

ToolsFactory::~ToolsFactory(){
	delete mpToolsInput;
	delete mpToolsOutput;
	delete mpToolsSave;
	delete mpToolsLoad;
}

void ToolsFactory::CreateInput(){
	try{
		if (mpToolsInput == NULL)
			mpToolsInput = new ToolsInput();
		mpToolsInput->SetProduct(mpTool);
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

void ToolsFactory::CreateOutput(){
	try{
		mpToolsOutput = new ToolsOutput();
		mpToolsOutput->SetProduct(mpTool);
		mpToolsOutput->SetOutputData(mppArrProducts, mnCurrentProductIndex);
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

void ToolsFactory::CreateSave(){
	try{
		mpToolsSave = new ToolsSave();
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

void ToolsFactory::CreateLoad(){
	try{
		mpToolsLoad = new ToolsLoad();
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

ToolsInput* ToolsFactory::GetToolsInput(){
	return mpToolsInput;
}

ToolsOutput* ToolsFactory::GetToolsOutput(){
	return mpToolsOutput;
}

ToolsSave* ToolsFactory::GetToolsSave(){
	return mpToolsSave;
}

ToolsLoad* ToolsFactory::GetToolsLoad(){
	return mpToolsLoad;
}

void ToolsFactory::SetProduct(Product *pProduct){
	mpTool = dynamic_cast<Tools*>(pProduct);
}

Tools* ToolsFactory::GetProduct(){
	return mpTool;
}

void ToolsFactory::SetOutputData(Product **ppArrProducts, int nCurrentProductIndex){
	mppArrProducts = ppArrProducts;
	mnCurrentProductIndex = nCurrentProductIndex;
}