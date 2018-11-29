#include "test.h"

bool test()
{
	bool result = true;
	const std::string infixStr1 = "7*(5+6)";
	std::string postfixStr1 = "";
	infixToPostfix(infixStr1, postfixStr1);

	const std::string infixStr2 = "(5+6)*7";
	std::string postfixStr2 = "";
	infixToPostfix(infixStr2, postfixStr2);
	
	const std::string infixStr3 = "5-(4-(3-(2-1)))";
	std::string postfixStr3 = "";
	infixToPostfix(infixStr3, postfixStr3);
	
	const std::string infixStr4 = "5+6-7*8*9/2-2*7+8-6*3";
	std::string postfixStr4 = "";
	infixToPostfix(infixStr4, postfixStr4);
	
	const std::string infixStr5 = "(5-(3*(4-(6-7)-7)*5-(7-(6*5-3))))-1";
	std::string postfixStr5 = "";
	infixToPostfix(infixStr5, postfixStr5);
	
	const std::string infixStr6 = "3-1-2";
	std::string postfixStr6 = "";
	infixToPostfix(infixStr6, postfixStr6);
	
	const std::string infixStr7 = "(9-6)+(4-3";
	std::string postfixStr7 = "";
	infixToPostfix(infixStr7, postfixStr7);
	
	const std::string infixStr8 = "9+7-(6+8";
	std::string postfixStr8 = "";
	infixToPostfix(infixStr8, postfixStr8);

	const std::string infixStr9 = "9+7-(8+6)-0)";
	std::string postfixStr9 = "";
	infixToPostfix(infixStr9, postfixStr9);
	
	const std::string infixStr10 = "9+7)+3";
	std::string postfixStr10 = "";
	infixToPostfix(infixStr10, postfixStr10);
	
	return postfixStr1 == "756+*" 
		&& postfixStr2 == "56+7*" 
		&& postfixStr3 == "54321----" 
		&& postfixStr4 == "56+78*9*2/-27*-8+63*-" 
		&& postfixStr5 == "53467--7-*5*765*3----1-" 
		&& postfixStr6 == "31-2-" 
		&& postfixStr7 == "Error! Incorrect input...\n" 
		&& postfixStr8 == "Error! Incorrect input...\n"
		&& postfixStr9 == "Error! Incorrect input...\n" 
		&& postfixStr10 == "Error! Incorrect input...\n";
}