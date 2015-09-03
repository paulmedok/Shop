// Library.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Library.h"

using namespace std;

// This is an example of an exported variable
LIBRARY_API int nLibrary=0;

// This is an example of an exported function.
LIBRARY_API int fnLibrary(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Library.h for the class definition
CLibrary::CLibrary()
{
	return;
}

LIBRARY_API int Mult(int a, int b){
	//cout << "From DLL" << endl;
	return (a*b);
}

LIBRARY_API BaseFactory* GetNewAliveFactory(){
	//cout << "New AliveFactory" << endl;
	return new AliveFactory();
}

LIBRARY_API BaseFactory* GetNewToolsFactory(){
	//cout << "New ToolsFactory" << endl;
	return new ToolsFactory();
}

LIBRARY_API Balance* GetNewBalance(){
	//cout << "New ToolsFactory" << endl;
	return new Balance();
}

LIBRARY_API Product* GetNewAlive(){
	//cout << "New AliveFactory" << endl;
	return new Alive(/*"Alive_Name_Dafault"*/);
}

LIBRARY_API Product* GetNewTool(){
	//cout << "New ToolsFactory" << endl;
	return new Tools(/*"Tools_Name_Dafault"*/);
}

//LIBRARY_API AliveInput* GetNewAliveInput(){
//	//cout << "New AliveFactory" << endl;
//	return new AliveInput();
//}