#include "stdafx.h"
#include "AliveOutput.h"


AliveOutput::AliveOutput(){}

AliveOutput::~AliveOutput(){}

double AliveOutput::GetPrice(){
	return mpAlive->GetPrice();
}

char* AliveOutput::GetName(){
	return mpAlive->GetName();
}

char* AliveOutput::GetColor(){
	return mpAlive->GetColor();
}

void AliveOutput::SetProduct(Product *pAlive){
	mpAlive = dynamic_cast<Alive*>(pAlive);
}

Alive* AliveOutput::GetProduct(){
	return mpAlive;
}

Alive* AliveOutput::GetProductById(int id){
	Alive *pAliveTemp = 0;
	int tempCount = 0;
	for (int i = 0; i <= mnCurrentProductIndex; i++){
		if (pAliveTemp = dynamic_cast<Alive*>(mppArrProducts[i])){
			if ((tempCount + 1) == id){
				return pAliveTemp;
			}
			tempCount++;
		}
	}
	if (tempCount == 0) return NULL;
}

void AliveOutput::ShowAll(){
	Alive *pAliveTemp = 0;
	int tempCount = 0;
	for (int i = 0; i <= mnCurrentProductIndex; i++){
		if (pAliveTemp = dynamic_cast<Alive*>(mppArrProducts[i])){
			cout << "# " << tempCount + 1 << endl;
			cout << "Alive NAME: " << pAliveTemp->GetName() << endl;
			cout << "Alive COLOR: " << pAliveTemp->GetColor() << endl;
			cout << "Alive PRICE: " << pAliveTemp->GetPrice() << endl;
			tempCount++;
		}
	}
	if (tempCount == 0)
		cout << "There are no Alive products in the Shop"<< endl;
	cout << "- - - - - " << endl;
}

void AliveOutput::SetOutputData(Product **ppArrProducts, int nCurrentProductIndex){
	mppArrProducts = ppArrProducts;
	mnCurrentProductIndex = nCurrentProductIndex;
}