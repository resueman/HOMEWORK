#include "test.h"

bool test()
{
	bool result = true;
	const std::string str1 = "5 4 3 2 1 - - - - ";
	const std::string str2 = "56789+-+-";
	const std::string str3 = "31-57+*7-2*";
	const std::string str4 = "64+73-1-*2+";
	const std::string str5 = "742/5+6*-";
	const std::string str6 = "867-3+3*-1+";
	const std::string str7 = "537*-";
	const std::string str8 = "09-";
	const std::string str9 = "6	2	/";
	return calculation(str1, result) == 3 && calculation(str2, result) == 9 && calculation(str3, result) == 34
		&& calculation(str4, result) == 32 && calculation(str5, result) == -35 && calculation(str6, result) == 3
		&& calculation(str7, result) == -16 && calculation(str8, result) == -9 && calculation(str9, result) == 3;
}
