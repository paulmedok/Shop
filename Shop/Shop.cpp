#include "stdafx.h"
#include "Shop.h"

Shop::Shop(Balance *pBalance, BaseText *pBaseText, Category *pCategory)
{
	mpBalance = pBalance;
	mpBaseText = pBaseText;
	mpCategory = pCategory;
}

Shop::~Shop()
{
	delete mpBalance;
	delete mpBaseText;
	delete mpCategory;
}

Balance* Shop::GetBalance(){
	return mpBalance;
};

BaseText* Shop::GetBaseText(){
	return mpBaseText;
};

Category* Shop::GetCategory(){
	return mpCategory;
};

void Shop::SetBalance(Balance* pBalance){
	mpBalance = pBalance;
};

void Shop::SetBaseText(BaseText* pBaseText){
	mpBaseText = pBaseText;
};

void Shop::SetCategory(Category* pCategory){
	mpCategory = pCategory;
};