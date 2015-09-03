#ifndef _Structures
#define _Structures
#include <regex>
#include <string>
using namespace std;

struct Validation{
	regex MenuValidation;
	regex BalanceValidation;
	regex EditBalanceValidation;
	regex InputValidation;
	regex InputAliveNameValidation;
	regex InputAliveColorValidation;
	regex InputAlivePriceValidation;
	regex InputToolsNameValidation;
	regex InputToolsWarrantyValidation;
	regex InputToolsPriceValidation;
	regex InputBuyStaffValidation;
	regex InputBuyStaffAliveNumberValidation;
	regex OutputValidation;
	
	Validation(){
		MenuValidation.assign("[1-9]");
		BalanceValidation.assign("[1-4]");
		EditBalanceValidation.assign("[-+]?[0-9]*\.?[0-9]+");
		InputValidation.assign("[1-3]");
		InputAliveNameValidation.assign("^[a-zA-Z0-9]{4,20}$");
		InputAliveColorValidation.assign("^[a-zA-Z]{3,10}$");
		InputAlivePriceValidation.assign("[0-9]*\.?[0-9]+");
		InputToolsNameValidation.assign("^[a-zA-Z0-9]{4,20}$");
		InputToolsPriceValidation.assign("[0-9]*\.?[0-9]+");
		InputToolsWarrantyValidation.assign("[0-9]*");
		InputBuyStaffValidation.assign("[1-3]");
		InputBuyStaffAliveNumberValidation.assign("[1-9]?[0-9]+");
		OutputValidation.assign("[1-3]");
	}
};

#endif