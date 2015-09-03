#include "stdafx.h"
#include "BaseText.h"

BaseText::BaseText(){}
BaseText::~BaseText(){}

void BaseText::SetBalance(Balance *pBalance){
	mpBalance = pBalance;
}

Balance* BaseText::GetBalance(){
	return mpBalance;
}

void BaseText::SetCategory(Category *pCategory){
	mpCategory = pCategory;
}

Category* BaseText::GetCategory(){
	return mpCategory;
}

void BaseText::Menu()
{
	//user input
	int nMenuChoice = 0;
	//Set console Text color
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, nColor);
	
	while (nMenuChoice != nExitChoice){
		cout << "- - - - - MENU - - - - -" << endl;
		cout << "1 - Input" << endl;
		cout << "2 - Output" << endl;
		cout << "3 - Save" << endl;
		cout << "4 - Load" << endl;
		cout << "5 - Info" << endl;
		cout << "6 - Balance" << endl;
		cout << "7 - Buy stuff" << endl;
		cout << "8 - Clear screen" << endl;
		cout << "9 - Exit" << endl;
		//Validation
		try{
			cin >> buffer;
			if (!regex_match(buffer, v.MenuValidation)) throw false;
			nMenuChoice = atoi(buffer);
		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			rStatus = false;
		}

		switch (nMenuChoice){
		case 1:
			WorkInput();
			break;
		case 2:
			WorkOutput();
			break;
		case 3:
			WorkSave();
			break;
		case 4:
			WorkLoad();
			break;
		case 5:
			Info();
			break;
		case 6:
			WorkBalance();
			break;
		case 7:
			WorkBuyStuff();
			break;
		case 8:
			system("cls");
			break;
		case 9:
			break; //Exit
		}
	}
}

void BaseText::WorkLoad(){
	FILE *pAliveFile, *pToolsFile;
	int nCurrentProductIndex = mpCategory->GetCurrentProductIndex();
	Product** ppArrPrduct = mpCategory->GetArrProducts();
	char buffer[DEFAULT_NUMBER_OF_SAVED_CHARACTERS];
	char ReadBuffer[3*DEFAULT_NUMBER_OF_SAVED_CHARACTERS];
	char convertionBuffer[DEFAULT_NUMBER_OF_SAVED_CHARACTERS];
	ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
	ZeroMemory(convertionBuffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
	ZeroMemory(ReadBuffer, 3*DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
	Alive *pAlive = 0;
	Tools *pTools = 0;
	string str;
	int nLength = 0, warranty = 0;
	double price = 0.0;
	//
	//Read Alive
	//
	pAliveFile = fopen("FileAlive.bin", "rb");
	if (pAliveFile != NULL)
	{
		while (fread(ReadBuffer, sizeof(char), 3 * DEFAULT_NUMBER_OF_SAVED_CHARACTERS, pAliveFile)){
				mpCategory->CreateAlive();
				pAlive = dynamic_cast<Alive*>(mpCategory->GetAlive());
				//
				memcpy(buffer, ReadBuffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				pAlive->SetName(buffer);
				memcpy(buffer, &ReadBuffer[DEFAULT_NUMBER_OF_SAVED_CHARACTERS], DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				pAlive->SetColor(buffer);
				memcpy(buffer, &ReadBuffer[2*DEFAULT_NUMBER_OF_SAVED_CHARACTERS], DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				price = atof(buffer);
				pAlive->SetPrice(price);
				//
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				ZeroMemory(ReadBuffer, 3*DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			}
		fclose(pAliveFile);
	}
	else
		cout << "Can't create/open file FileAlive.bin" << endl;
	//
	//Read Tools
	//
	pToolsFile = fopen("FileTools.bin", "rb");
	if (pToolsFile != NULL)
	{
		while (fread(ReadBuffer, sizeof(char), 3 * DEFAULT_NUMBER_OF_SAVED_CHARACTERS, pToolsFile)){
			mpCategory->CreateTool();
			pTools = dynamic_cast<Tools*>(mpCategory->GetTool());
			//
			memcpy(buffer, ReadBuffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			pTools->SetName(buffer);
			memcpy(buffer, &ReadBuffer[DEFAULT_NUMBER_OF_SAVED_CHARACTERS], DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			warranty = atoi(buffer);
			pTools->SetWarranty(warranty);
			memcpy(buffer, &ReadBuffer[2 * DEFAULT_NUMBER_OF_SAVED_CHARACTERS], DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			price = atof(buffer);
			pTools->SetPrice(price);
			//
			ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			ZeroMemory(ReadBuffer, 3 * DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
		}
		fclose(pToolsFile);
	}
	else
		cout << "Can't create/open file FileTools.bin" << endl;

	cout << "- - - - - LOADED SUCCESSFULLY - - - - -" << endl;
}

void BaseText::WorkSave(){
	FILE *pAliveFile, *pToolsFile;
	int nCurrentProductIndex = mpCategory->GetCurrentProductIndex();
	Product** ppArrPrduct = mpCategory->GetArrProducts();
	char buffer[DEFAULT_NUMBER_OF_SAVED_CHARACTERS];
	char convertionBuffer[DEFAULT_NUMBER_OF_SAVED_CHARACTERS];
	ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
	ZeroMemory(convertionBuffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
	Alive *pAlive = 0;
	Tools *pTools = 0;
	string str;
	int nLength = 0;	
	//
	//Write Alive
	//
	pAliveFile = fopen("FileAlive.bin", "w");
	if (pAliveFile != NULL)
	{
		for (int i = 0; i < nCurrentProductIndex; i++){
			if (dynamic_cast<Alive*>(ppArrPrduct[i])){
				pAlive = dynamic_cast<Alive*>(ppArrPrduct[i]);
				// name
				nLength = strlen(pAlive->GetName()) + 1;
				memcpy(buffer, pAlive->GetName(), sizeof(char)*nLength);
				fwrite(buffer, sizeof(char)*DEFAULT_NUMBER_OF_SAVED_CHARACTERS, 1, pAliveFile);
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				// color
				nLength = strlen(pAlive->GetColor()) + 1;
				memcpy(buffer, pAlive->GetColor(), sizeof(char)*nLength);
				fwrite(buffer, sizeof(char)*DEFAULT_NUMBER_OF_SAVED_CHARACTERS, 1, pAliveFile);
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				// price
				str = to_string(pAlive->GetPrice());
				strcpy(convertionBuffer, str.c_str());
				nLength = strlen(convertionBuffer);
				memcpy(buffer, convertionBuffer, sizeof(char)*nLength);
				fwrite(buffer, sizeof(char)*DEFAULT_NUMBER_OF_SAVED_CHARACTERS, 1, pAliveFile);
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			}
		}
		fclose(pAliveFile);
	}
	else
		cout << "Can't create/open file FileAlive.bin" << endl;
	//
	//Write Tools
	//
	pToolsFile = fopen("FileTools.bin", "w");
	if (pToolsFile != NULL)
	{
		for (int i = 0; i < nCurrentProductIndex; i++){
			if (dynamic_cast<Tools*>(ppArrPrduct[i])){
				pTools = dynamic_cast<Tools*>(ppArrPrduct[i]);
				// name
				nLength = strlen(pTools->GetName()) + 1;
				memcpy(buffer, pTools->GetName(), sizeof(char)*nLength);
				fwrite(buffer, sizeof(char)*DEFAULT_NUMBER_OF_SAVED_CHARACTERS, 1, pToolsFile);
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				// warranty
				str = to_string(pTools->GetWarranty());
				strcpy(convertionBuffer, str.c_str());
				nLength = strlen(convertionBuffer) + 1;
				memcpy(buffer, convertionBuffer, sizeof(char)*nLength);
				fwrite(buffer, sizeof(char)*DEFAULT_NUMBER_OF_SAVED_CHARACTERS, 1, pToolsFile);
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				// price
				str = to_string(pTools->GetPrice());
				ZeroMemory(convertionBuffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
				strcpy(convertionBuffer, str.c_str());
				nLength = strlen(convertionBuffer);
				memcpy(buffer, convertionBuffer, sizeof(char)*nLength);
				fwrite(buffer, sizeof(char)*DEFAULT_NUMBER_OF_SAVED_CHARACTERS, 1, pToolsFile);
				ZeroMemory(buffer, DEFAULT_NUMBER_OF_SAVED_CHARACTERS);
			}
		}
		fclose(pToolsFile);
	}
	else
		cout << "Can't create/open file FileTools.bin" << endl;
	cout << "- - - - - SAVED SUCCESSFULLY - - - - -"<< endl;
}

void BaseText::WorkOutput(){
	bool matchInput = false;
	int nInputChoice = 0;
	do{
		cout << "- - - - - OUTPUT - - - - -" << endl;
		cout << "1 - Output Alive" << endl;
		cout << "2 - Output Tools" << endl;
		cout << "3 - Back to menu" << endl;
		//validation
		try{
			cin >> buffer;
			matchInput = regex_match(buffer, v.OutputValidation);
			if (!matchInput) throw false;
			nInputChoice = atoi(buffer);
		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			nInputChoice = 0;
			rStatus = false;
		}
	} while (!matchInput);

	switch (nInputChoice){
	case 1:
	{
			   cout << "- - - - - OUTPUT ALIVE - - - - -" << endl;
			   if (!dynamic_cast<AliveFactory*>(mpCategory->GetBaseFactory()))
					mpCategory->CreateAliveFactory();
			   AliveFactory *pAliveFactory = dynamic_cast<AliveFactory*>(mpCategory->GetBaseFactory());
			   if (pAliveFactory->GetAliveOutput() == NULL)
					pAliveFactory->CreateOutput();
			   AliveOutput *pAliveOutput = pAliveFactory->GetAliveOutput();
			   pAliveOutput->SetOutputData(mpCategory->GetArrProducts(), mpCategory->GetCurrentProductIndex());
			   pAliveOutput->ShowAll();
			   break;
	}
	case 2:
	{
			  cout << "- - - - - OUTPUT TOOLS - - - - -" << endl;
			  if (!dynamic_cast<ToolsFactory*>(mpCategory->GetBaseFactory()))
			  mpCategory->CreateToolsFactory();
			  ToolsFactory *pToolsFactory = dynamic_cast<ToolsFactory*>(mpCategory->GetBaseFactory());
			  if (pToolsFactory->GetToolsOutput() == NULL)
			  pToolsFactory->CreateOutput();
			  ToolsOutput *pToolsOutput = pToolsFactory->GetToolsOutput();
			  pToolsOutput->SetOutputData(mpCategory->GetArrProducts(), mpCategory->GetCurrentProductIndex());
			  pToolsOutput->ShowAll();
			  break;
	}
	case 3:
		break;
	}
}

void BaseText::WorkInput(){
	bool matchInput = false;
	int nInputChoice = 0;
	do{
		cout << "- - - - - INPUT - - - - -" << endl;
		cout << "1 - Input Alive" << endl;
		cout << "2 - Input Tools" << endl;
		cout << "3 - Back to menu" << endl;
		//validation
		try{
			cin >> buffer;
			matchInput = regex_match(buffer, v.InputValidation);
			if (!matchInput) throw false;
			nInputChoice = atoi(buffer);
		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			nInputChoice = 0;
			rStatus = false;
		}
	} while (!matchInput);

	switch (nInputChoice){
	case 1:
		do{
			char *pName = 0;
			char *pColor = 0;
			try{
				matchInput = true;
				int nLenght = 0;
				double dAliveInputPrice = 0;
				cout << "- - - - - INPUT ALIVE - - - - -" << endl;
				//
				cout << "Enter name: " << endl;			
				cin >> buffer;
				matchInput = regex_match(buffer, v.InputAliveNameValidation);
				if (!matchInput) throw false;
				nLenght = strlen(buffer) + 1;
				pName = new char[nLenght];
			    memcpy(pName, buffer, sizeof(char)*nLenght);
				//
				cout << "Enter color: " << endl;
				cin >> buffer;
				matchInput = regex_match(buffer, v.InputAliveColorValidation);
				if (!matchInput) throw false;
				nLenght = strlen(buffer) + 1;
				pColor = new char[nLenght];
				memcpy(pColor, buffer, sizeof(char)*nLenght);
				//
				cout << "Enter price: " << endl;
				cin >> buffer;
				matchInput = regex_match(buffer, v.InputAlivePriceValidation);
				if (!matchInput) throw false;
				dAliveInputPrice = atof(buffer);
				//
				if (!dynamic_cast<AliveFactory*>(mpCategory->GetBaseFactory()))
					mpCategory->CreateAliveFactory();
				mpCategory->CreateAlive();
				//
				AliveFactory *pAliveFactory = dynamic_cast<AliveFactory*>(mpCategory->GetBaseFactory());
				if (pAliveFactory->GetAliveInput() == NULL)
					pAliveFactory->CreateInput();
				pAliveFactory->SetProduct(mpCategory->GetAlive());
				pAliveFactory->SetOutputData(mpCategory->GetArrProducts(), mpCategory->GetCurrentProductIndex());
				AliveInput *pAliveInput = pAliveFactory->GetAliveInput();
				pAliveInput->SetProduct(mpCategory->GetAlive());
				//
				pAliveInput->SetName(pName);
				pAliveInput->SetColor(pColor);
				pAliveInput->SetPrice(dAliveInputPrice);
				//
				delete[]pName;
				delete[]pColor;
			}
			catch (bool rStatus){
				cout << "Validation error! Please, enter correct value." << endl;
				nInputChoice = 0;
				rStatus = false;
				matchInput = false;

				if (pName != NULL) delete[]pName;
				if (pColor != NULL) delete[]pColor;
			}
			catch (bad_alloc &ba){
				cout << "Memory allocation error!" << endl << ba.what() << endl;
			}
		} while (!matchInput);
		break;
	case 2:
		do{
			char *pName = 0;
			try{
				int nLenght = 0;
				int nWarranty = 0;
				double dAliveInputPrice = 0;
				cout << "- - - - - INPUT TOOL - - - - -" << endl;
				//
				cout << "Enter name: " << endl;
				cin >> buffer;
				matchInput = regex_match(buffer, v.InputToolsNameValidation);
				if (!matchInput) throw false;
				nLenght = strlen(buffer) + 1;
				pName = new char[nLenght];
				memcpy(pName, buffer, sizeof(char)*nLenght);
				//
				cout << "Enter warranrty: " << endl;
				cin >> buffer;
				matchInput = regex_match(buffer, v.InputToolsWarrantyValidation);
				if (!matchInput) throw false;
				nWarranty = atoi(buffer);
				//
				cout << "Enter price: " << endl;
				cin >> buffer;
				matchInput = regex_match(buffer, v.InputToolsPriceValidation);
				if (!matchInput) throw false;
				dAliveInputPrice = atof(buffer);		
				//
				if (!dynamic_cast<ToolsFactory*>(mpCategory->GetBaseFactory()))
					mpCategory->CreateToolsFactory();
				mpCategory->CreateTool();
				ToolsFactory *pToolsFactory = dynamic_cast<ToolsFactory*>(mpCategory->GetBaseFactory());
				if (pToolsFactory->GetToolsInput() == NULL)
					pToolsFactory->CreateInput();
				pToolsFactory->CreateInput();
				pToolsFactory->SetProduct(mpCategory->GetTool());
				pToolsFactory->SetOutputData(mpCategory->GetArrProducts(), mpCategory->GetCurrentProductIndex());
				ToolsInput *pToolsInput = pToolsFactory->GetToolsInput();
				pToolsInput->SetProduct(mpCategory->GetTool());
				//
				pToolsInput->SetName(pName);
				pToolsInput->SetWarranty(nWarranty);
				pToolsInput->SetPrice(dAliveInputPrice);
				//
				delete []pName;
				//
			}
			catch (bool rStatus){
				cout << "Validation error! Please, enter correct value." << endl;
				nInputChoice = 0;
				rStatus = false;
				matchInput = false;
				//
				delete[]pName;
			}
			catch (bad_alloc &ba){
				cout << "Memory allocation error!" << endl << ba.what() << endl;
			}
		} while (!matchInput);
		break;
	case 3:
		break;
	}
}

void BaseText::WorkBalance(){
	int nBalanceChoice = 0;
	bool matchBalance = false;

	do{
		cout << "- - - - - BALANCE - - - - -" << endl;
		cout << "Current balance: " << mpBalance->GetBalance() << endl;
		cout << "1 - Add balance" << endl;
		cout << "2 - Substruct balance" << endl;
		cout << "3 - Clear balance" << endl;
		cout << "4 - Back to menu" << endl;
		//validation
		try{
			cin >> buffer;
			matchBalance = regex_match(buffer, v.BalanceValidation);
			if (!matchBalance) throw false;
			nBalanceChoice = atoi(buffer);
		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			nBalanceChoice = 0;
			rStatus = false;
		}
	} while (!nBalanceChoice);

	switch (nBalanceChoice){
	case 1:
		do{
			try{
				double addValue;
				cout << "- - - - - ADD BALANCE - - - - -" << endl;
				cout << "Enter ADD value: " << endl;
				cin >> buffer;
				matchBalance = regex_match(buffer, v.EditBalanceValidation);
				if (!matchBalance) throw false;
				addValue = atof(buffer);
				mpBalance->AddBalance(addValue);
			}
			catch (bool rStatus){
				cout << "Validation error! Please, enter correct value." << endl;
				nBalanceChoice = 0;
				rStatus = false;
			}
		} while (!matchBalance);
		break;
	case 2:
		do{
			try{
				double subValue;
				cout << "- - - - - SUBSTRACT BALANCE - - - - -" << endl;
				cout << "Enter SUBSTRACT value: " << endl;
				cin >> buffer;
				matchBalance = regex_match(buffer, v.EditBalanceValidation);
				if (!matchBalance) throw false;
				subValue = atof(buffer);
				mpBalance->SubstractBalance(subValue);
			}
			catch (bool rStatus){
				cout << "Validation error! Please, enter correct value." << endl;
				nBalanceChoice = 0;
				rStatus = false;
			}
		} while (!matchBalance);
		break;
	case 3:
		mpBalance->ClearBalance();
		break;
	case 4:
		break;
	}
}

void BaseText::WorkBuyStuff(){

	bool matchInput = false;
	int nInputChoice = 0;
	Alive *pAlive = 0;
	Tools *pTool = 0;
	do{
		cout << "- - - - - BUY STUFF - - - - -" << endl;
		cout << "1 - Buy Alive" << endl;
		cout << "2 - Buy Tools" << endl;
		cout << "3 - Back to menu" << endl;
		//validation
		try{
			cin >> buffer;
			matchInput = regex_match(buffer, v.InputBuyStaffValidation);
			if (!matchInput) throw false;
			nInputChoice = atoi(buffer);
		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			nInputChoice = 0;
			rStatus = false;
		}
	} while (!matchInput);

	switch (nInputChoice){
	case 1:
		cout << "Enter #id number to buy Alive" << endl;
		try{
			cin >> buffer;
			matchInput = regex_match(buffer, v.InputBuyStaffAliveNumberValidation);
			nInputChoice = atoi(buffer);
			if ((!matchInput) || (nInputChoice == 0)) throw false;
			nInputChoice = atoi(buffer);

			if (!dynamic_cast<AliveFactory*>(mpCategory->GetBaseFactory()))
				mpCategory->CreateAliveFactory();
			AliveFactory *pAliveFactory = dynamic_cast<AliveFactory*>(mpCategory->GetBaseFactory());
			if (pAliveFactory->GetAliveOutput() == NULL)
				pAliveFactory->CreateOutput();
			AliveOutput *pAliveOutput = pAliveFactory->GetAliveOutput();
			pAliveOutput->SetOutputData(mpCategory->GetArrProducts(), mpCategory->GetCurrentProductIndex());
			pAlive = pAliveOutput->GetProductById(nInputChoice);
			if (pAlive != NULL){
				if (mpBalance->GetBalance() >= pAlive->GetPrice()){
					cout << "- - - - - You Bought Alive Successfully- - - - -" << endl;
					cout << "Alive NAME: " << pAlive->GetName() << endl;
					cout << "Alive COLOR: " << pAlive->GetColor() << endl;
					cout << "Alive PRICE: " << pAlive->GetPrice() << endl;
					//
					mpBalance->SubstractBalance(pAlive->GetPrice());
					mpCategory->DeleteProductFromArrProducts(pAlive);
					//
					cout << "Rest of BALANCE: " << mpBalance->GetBalance() << endl;
				}
				else{
					cout << "There are not enough money on your account!" << endl;
				}
			}
			else{
				cout << "There is no current product #id"<< endl;
			}

		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			nInputChoice = 0;
			rStatus = false;
		}
		break;
	case 2:
		cout << "Enter #id number to buy Tool" << endl;
		try{
			cin >> buffer;
			matchInput = regex_match(buffer, v.InputBuyStaffAliveNumberValidation);
			nInputChoice = atoi(buffer);
			if ((!matchInput) || (nInputChoice == 0)) throw false;
			nInputChoice = atoi(buffer);

			if (!dynamic_cast<ToolsFactory*>(mpCategory->GetBaseFactory()))
				mpCategory->CreateToolsFactory();
			ToolsFactory *pToolsFactory = dynamic_cast<ToolsFactory*>(mpCategory->GetBaseFactory());
			if (pToolsFactory->GetToolsOutput() == NULL)
				pToolsFactory->CreateOutput();
			ToolsOutput *pToolsOutput = pToolsFactory->GetToolsOutput();
			pToolsOutput->SetOutputData(mpCategory->GetArrProducts(), mpCategory->GetCurrentProductIndex());
			pTool = pToolsOutput->GetProductById(nInputChoice);
			if (pTool != NULL){
				if (mpBalance->GetBalance() >= pTool->GetPrice()){
					cout << "- - - - - You Bought Tool Successfully- - - - -" << endl;
					cout << "Tool NAME: " << pTool->GetName() << endl;
					cout << "Tool WARRANTY: " << pTool->GetWarranty() << endl;
					cout << "Tool PRICE: " << pTool->GetPrice() << endl;
					//
					mpBalance->SubstractBalance(pTool->GetPrice());
					mpCategory->DeleteProductFromArrProducts(pTool);
					//
					cout << "Rest of BALANCE: " << mpBalance->GetBalance() << endl;
				}
				else{
					cout << "There are not enough money on your account!" << endl;
				}
			}
			else{
				cout << "There is no current product #id" << endl;
			}

		}
		catch (bool rStatus){
			cout << "Validation error! Please, enter correct value." << endl;
			nInputChoice = 0;
			rStatus = false;
		}
		break;
	case 3:
		break;
	}
}

void BaseText::Info(){
	//system("cls");
	cout << "Graduate work \"Shop\"" << endl;
	cout << "C++ for professional" << endl;
	cout << "Perspectiva XXI vek" << endl;
	cout << "Kolomiitsev Pavlo" << endl;
	cout << "2015" << endl;
}