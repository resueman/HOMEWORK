#include "test.h"

bool test()
{
	const std::string strTrue1 = "(jk[ckm]nd{}jnfkjn[f(f[{}])fdfgg])";
	const std::string strTrue2 = "[]{ ( [[ { [()] } ]] )}  [] {} ([])";
	const std::string strTrue3 = "[787]";
	const std::string strTrue4 = "[[][]{}([{}{}(){}])]";
	const std::string strFalse1 = "[0]00{0)0";
	const std::string strFalse2 = "( [] ({}0) [999 )";
	const std::string strFalse3 = "((())";
	const std::string strFalse4 = "][";
	return checkBalance(strTrue1) && checkBalance(strTrue2) && checkBalance(strTrue3)
			&& checkBalance(strTrue4) && (!checkBalance(strFalse1)) && (!checkBalance(strFalse2))
			&& (!checkBalance(strFalse3)) && (!checkBalance(strFalse4));
}
