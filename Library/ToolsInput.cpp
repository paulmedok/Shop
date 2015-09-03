#include "stdafx.h"
#include "ToolsInput.h"

ToolsInput::ToolsInput(){}

ToolsInput::~ToolsInput(){}

void ToolsInput::SetPrice(double price){
	mpTool->SetPrice(price);
}

void ToolsInput::SetName(char *name){
	mpTool->SetName(name);
}

void ToolsInput::SetWarranty(int warranty){
	mpTool->SetWarranty(warranty);
}

void ToolsInput::SetProduct(Product *pTools){
	mpTool = dynamic_cast<Tools*>(pTools);
}

Tools* ToolsInput::GetProduct(){
	return mpTool;
}