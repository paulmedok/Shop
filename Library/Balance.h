#pragma once
class Balance
{
private:
	double mBalance;
public:
	Balance(double balance = 0.0);
	virtual ~Balance();
	virtual void SetBalance(double balance);
	virtual double GetBalance();
	virtual void AddBalance(double balance);
	virtual void SubstractBalance(double balance);
	virtual void ClearBalance();
};

