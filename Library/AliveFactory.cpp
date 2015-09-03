#include "stdafx.h"
#include "AliveFactory.h"
using namespace std;

AliveFactory::AliveFactory(){}

AliveFactory::~AliveFactory(){
	delete mpAliveInput;
	delete mpAliveOutput;
	delete mpAliveSave;
	delete mpAliveLoad;
}

void AliveFactory::CreateInput(){
	try{
		if (mpAliveInput == NULL)
			mpAliveInput = new AliveInput();
		mpAliveInput->SetProduct(mpAlive);
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

void AliveFactory::CreateOutput(){
	try{
		mpAliveOutput = new AliveOutput();
		mpAliveOutput->SetProduct(mpAlive);
		mpAliveOutput->SetOutputData(mppArrProducts,mnCurrentProductIndex);
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

void AliveFactory::CreateSave(){
	try{
		mpAliveSave = new AliveSave();
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

void AliveFactory::CreateLoad(){
	try{
		mpAliveLoad = new AliveLoad();
	}
	catch (bad_alloc &ba){
		cout << "Memory allocation error!" << endl << ba.what() << endl;
	}
}

AliveInput* AliveFactory::GetAliveInput(){
	return mpAliveInput;
}

AliveOutput* AliveFactory::GetAliveOutput(){
	return mpAliveOutput;
}

AliveSave* AliveFactory::GetAliveSave(){
	return mpAliveSave;
}

AliveLoad* AliveFactory::GetAliveLoad(){
	return mpAliveLoad;
}

void AliveFactory::SetProduct(Product *pAlive){
	mpAlive = dynamic_cast<Alive*>(pAlive);
}

void AliveFactory::SetOutputData(Product **ppArrProducts, int nCurrentProductIndex){
	mppArrProducts = ppArrProducts;
	mnCurrentProductIndex = nCurrentProductIndex;
}

Alive* AliveFactory::GetProduct(){
	return mpAlive;
}

