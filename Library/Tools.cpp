#include "stdafx.h"
#include "Tools.h"

Tools::Tools(char* name, int warranty, double price){
	mPrice = price;
	mName = name;
	mnWarranty = warranty;
}

Tools::Tools(const Tools &Right){
	mPrice = Right.mPrice;

	mnWarranty = Right.mnWarranty;

	int nLength = strlen(Right.mName) + 1;
	mName = new char[nLength];
	memcpy(mName, Right.mName, sizeof(char)*nLength);
}

Tools::~Tools(){
	delete mName;
}

void Tools::SetPrice(double price){
	mPrice = price;
}

double Tools::GetPrice(){
	return mPrice;
}

void Tools::SetName(char *name){
	int nLength = strlen(name) + 1;
	mName = new char[nLength];
	memcpy(mName, name, sizeof(char)*nLength);
}

char* Tools::GetName(){
	return mName;
}

void Tools::SetWarranty(int warranty){
	mnWarranty = warranty;
}

int Tools::GetWarranty(){
	return mnWarranty;
}