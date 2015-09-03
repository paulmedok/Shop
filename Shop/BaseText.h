#ifndef _BaseText
#define _BaseText
#include "Balance.h"
#include <regex>
#include "Structures.h"
#include "Category.h"
#include "AliveInput.h"
#include "AliveFactory.h"
#include <memory>
#include <stdio.h>

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define DEFAULT_NUMBER_OF_SAVED_CHARACTERS 20
#define nExitChoice 9
#define nColor 15


using namespace std;

class BaseText
{
private:
	Balance *mpBalance = 0;
	Category *mpCategory = 0;
	char buffer[100];
	Validation v;
public:
	BaseText();
	virtual ~BaseText();
	virtual void Menu();
	virtual void SetBalance(Balance *pBalance);
	virtual	Balance* GetBalance();
	virtual void SetCategory(Category *pCategory);
	virtual	Category* GetCategory();
	virtual void WorkInput();   //1
	virtual void WorkOutput();  //2
	virtual void WorkSave();    //3
	virtual void WorkLoad();    //4
	virtual void Info();        //5
	virtual void WorkBuyStuff();//6
	virtual void WorkBalance(); //7
};

#endif