#include "stdafx.h"
#include "Alive.h"

Alive::Alive(char* name, char* color, double price){
	mPrice = price;
	mName = name;
	mColor = color;
}

Alive::Alive(const Alive &Right){
	mPrice = Right.mPrice;

	int nLength = strlen(Right.mName) + 1;
	mName = new char[nLength];
	memcpy(mName, Right.mName, sizeof(char)*nLength);

	nLength = strlen(Right.mColor) + 1;
	mColor = new char[nLength];
	memcpy(mColor, Right.mColor, sizeof(char)*nLength);
}

Alive::~Alive()
{
	delete mName;
	delete mColor;
}

void Alive::SetPrice(double price){
	mPrice = price;
}

double Alive::GetPrice(){
	return mPrice;
}

void Alive::SetName(char *name){
	int nLength = strlen(name) + 1;
	mName = new char[nLength];
	memcpy(mName, name, sizeof(char)*nLength);
}

char* Alive::GetName(){
	return mName;
}

void Alive::SetColor(char *color){
	int nLength = strlen(color) + 1;
	mColor = new char[nLength];
	memcpy(mColor, color, sizeof(char)*nLength);
}

char* Alive::GetColor(){
	return mColor;
}