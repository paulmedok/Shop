// Shop.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ShopApp.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <regex>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
		//Find libraries in directory - sample code
		/*HANDLE hFind;
		WIN32_FIND_DATA data;

		hFind = FindFirstFile(L"D:/Dropbox/CPP_PROF/Shop/Shop/Debug/*.*", &data);
		if (hFind != INVALID_HANDLE_VALUE) {
		do {
		_tprintf(TEXT("%s\n"), data.cFileName);
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
		}
		system("pause");
		*/
	{
		//Open Library *.dll
		//LoadLibrary(L"D:/Dropbox/CPP_PROF/Shop/Shop/Debug/Library.dll");
		HMODULE hMod = LoadLibrary(L"Library.dll");
		if (hMod == NULL){
			cout << "Error in hMod = LoadLibrary(\"D:/Dropbox/CPP_PROF/Shop/Shop/Debug/Library.dll\") " << endl;
			FreeLibrary(hMod);
			system("pause");
			return 0;
		}

		typedef Balance*(*GetBalance)();
		GetBalance pGB;

		try{
			pGB = (GetBalance)GetProcAddress(hMod, "GetNewBalance");
			if (pGB == NULL)  throw 1;
		}
		catch (int nErrNum){
			switch (nErrNum){

			case 1:
				cout << "Error in pGB =  (GetBalance)GetProcAddress(hMod, \"GetNewBalance\");" << endl;
				FreeLibrary(hMod);
				system("pause");
				return 0;
				break;
			}
		}

		Balance *pBalance = pGB();
		pBalance->SetBalance(1000.0); // Testing amount
		BaseText *pBaseText = new BaseText();
		Category *pCategory = new Category(hMod);

		Shop *pShop = new Shop(pBalance, pBaseText, pCategory);
		pShop->GetBaseText()->SetBalance(pShop->GetBalance());
		pShop->GetBaseText()->SetCategory(pShop->GetCategory());
		pShop->GetBaseText()->Menu();

		delete pShop;

		FreeLibrary(hMod);
	}
	if (_CrtDumpMemoryLeaks())
		cout << endl << "**************" << endl << "MemoryLeaks!!!" << endl << "**************" << endl;
	else
		cout << endl << "*************" << endl << "* Memory OK *" << endl << "*************" << endl;

	system("pause");
	return 0;
}

