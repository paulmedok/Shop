#ifndef _AliveFactory
#define _AliveFactory

#include "BaseFactory.h"
#include "AliveInput.h"
#include "AliveOutput.h"
#include "AliveSave.h"
#include "AliveLoad.h"
#include "Alive.h"

class AliveFactory :
	public BaseFactory
{
private:
	AliveInput  *mpAliveInput  = 0;
	AliveOutput *mpAliveOutput = 0;
	AliveSave   *mpAliveSave = 0;
	AliveLoad   *mpAliveLoad = 0;
	Alive	   *mpAlive = 0;
	Product **mppArrProducts = 0;
	int mnCurrentProductIndex = 0;

public:
	AliveFactory();
	void CreateInput();
	void CreateOutput();
	void CreateLoad();
	void CreateSave();
	void SetProduct(Product *pAlive);
	void SetOutputData(Product **mppArrProducts, int mnCurrentProductIndex);
	Alive* GetProduct();
	virtual AliveInput* GetAliveInput();
	virtual AliveOutput* GetAliveOutput();
	virtual AliveSave* GetAliveSave();
	virtual AliveLoad* GetAliveLoad();
	~AliveFactory();
};

#endif