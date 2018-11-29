#include "test.h"

bool test()
{
	bool result = true;
	const std::string strTrue1 = "(jk[ckm]nd{}jnfkjn[f(f[{}])fdfgg])";
	const std::string strTrue2 = "[]{ ( [[ { [()] } ]] )}  [] {} ([])";
	const std::string strTrue3 = "[787]";
	const std::string strTrue4 = "[[][]{}([{}{}(){}])]";
	const std::string strFalse1 = "[0]00{0)0";
	const std::string strFalse2 = "( [] ({}0) [999 )";
	const std::string strFalse3 = "((())";
	const std::string strFalse4 = "][";
	return checkBalance(strTrue1, result) && checkBalance(strTrue2, result) && checkBalance(strTrue3, result)
			&& checkBalance(strTrue4, result) && (!checkBalance(strFalse1, result)) && (!checkBalance(strFalse2, result))
			&& (!checkBalance(strFalse3, result)) && (!checkBalance(strFalse4, result));
}