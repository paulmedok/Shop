#pragma once
#include "Balance.h"
#include "BaseText.h"
#include "Category.h"

class Shop
{
private:
	Balance *mpBalance;  
	BaseText *mpBaseText;
	Category *mpCategory;

public:
	Shop(Balance *pBalance = 0, BaseText *pBaseText = 0, Category *pCategory = 0);
	virtual ~Shop();
	virtual Balance* GetBalance();
	virtual BaseText* GetBaseText();
	virtual Category* GetCategory();
	virtual void SetBalance(Balance* pBalance);
	virtual void SetBaseText(BaseText* pBaseText);
	virtual void SetCategory(Category* pCategory);
};

