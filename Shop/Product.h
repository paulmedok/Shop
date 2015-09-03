#ifndef _Product
#define _Product

class Product
{
public:
	Product(){};
	virtual void SetName(char *name) = 0;
	virtual char* GetName() = 0;
	virtual void SetPrice(double price) = 0;
	virtual double GetPrice() = 0;
	virtual ~Product(){};
};

#endif