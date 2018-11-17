#include "test.h"

bool test()
{
	std::string strTrue1 = "(jk[ckm]nd{}jnfkjn[f(f[{}])fdfgg])";
	std::string strTrue2 = "[]{ ( [[ { [()] } ]] )}  [] {} ([])";
	std::string strTrue3 = "[787]";
	std::string strTrue4 = "[[][]{}([{}{}(){}])]";
	std::string strFalse1 = "[0]00{0)0";
	std::string strFalse2 = "( [] ({}0) [999 )";
	std::string strFalse3 = "((())";
	std::string strFalse4 = "][";
	return checkBalance(strTrue1) && checkBalance(strTrue2) && checkBalance(strTrue3) && checkBalance(strTrue4) &&
		(!checkBalance(strFalse1)) && (!checkBalance(strFalse2)) && (!checkBalance(strFalse3)) && (!checkBalance(strFalse4));
}