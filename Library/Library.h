// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LIBRARY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LIBRARY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include <iostream>
#include "Balance.h"
#include "AliveFactory.h"
#include "ToolsFactory.h"
#include "Shop.h"
#include "BaseText.h"
#include "Category.h"
#include "Alive.h"
#include "Tools.h"
#include "AliveInput.h"


#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

// This class is exported from the Library.dll
class LIBRARY_API CLibrary {
public:
	CLibrary(void);
	// TODO: add your methods here.
};

extern LIBRARY_API int nLibrary;

LIBRARY_API int fnLibrary(void);

/*Test export function*/
extern "C" LIBRARY_API
int Mult(int a, int b);

extern "C" LIBRARY_API
LIBRARY_API BaseFactory* GetNewAliveFactory();

extern "C" LIBRARY_API
LIBRARY_API BaseFactory* GetNewToolsFactory();

extern "C" LIBRARY_API
LIBRARY_API Product* GetNewAlive();

extern "C" LIBRARY_API
LIBRARY_API Product* GetNewTool();

extern "C" LIBRARY_API
LIBRARY_API Balance* GetNewBalance();

//extern "C" LIBRARY_API
//LIBRARY_API AliveInput* GetNewAliveInput()
