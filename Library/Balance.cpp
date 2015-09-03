#include "stdafx.h"
#include "Balance.h"

Balance::Balance(double balance) : mBalance(balance){}

Balance::~Balance(){}

void Balance::SetBalance(double balance){
	mBalance = balance;
}

double Balance::GetBalance(){
	return mBalance;
}

void Balance::AddBalance(double balance){
	mBalance += balance;
}

void Balance::SubstractBalance(double balance){
	mBalance -= balance;
}

void Balance::ClearBalance(){
	mBalance = 0.0;
}
