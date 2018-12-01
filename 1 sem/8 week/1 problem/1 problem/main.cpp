#include "tree.h"
#include "test.h"
#include <iostream>

int main()
{
	if (!test())
	{
		std::cout << "Tests aren't passed";
		return -1;
	}

	return 0;
}