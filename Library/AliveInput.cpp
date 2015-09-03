#include "stdafx.h"
#include "AliveInput.h"

AliveInput::AliveInput(){}

AliveInput::~AliveInput(){}

void AliveInput::SetPrice(double price){
	mpAlive->SetPrice(price);
}

void AliveInput::SetName(char *name){
	mpAlive->SetName(name);
}

void AliveInput::SetColor(char *color){
	mpAlive->SetColor(color);
}

void AliveInput::SetProduct(Product *pAlive){
	mpAlive = dynamic_cast<Alive*>(pAlive);
}

Alive* AliveInput::GetProduct(){
	return mpAlive;
}