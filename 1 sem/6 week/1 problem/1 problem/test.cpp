#include "test.h"

bool test()
{
	std::string str1 = "5 4 3 2 1 - - - - ";
	std::string str2 = "56789+-+-";
	std::string str3 = "31-57+*7-2*";
	std::string str4 = "64+73-1-*2+";
	std::string str5 = "742/5+6*-";
	std::string str6 = "867-3+3*-1+";
	std::string str7 = "537*-";
	std::string str8 = "09-";
	std::string str9 = "6	2	/";
	return calculation(str1) == 3 && calculation(str2) == 9 && calculation(str3) == 34
		&& calculation(str4) == 32 && calculation(str5) == -35 && calculation(str6) == 3
		&& calculation(str7) == -16 && calculation(str8) == -9 && calculation(str9) == 3;
}