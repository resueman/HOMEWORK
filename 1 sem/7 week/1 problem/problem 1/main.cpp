#include "interaction.h"
#include "test.h"

int main()
{
	if (!test())
	{
		std::cout << "Program doesn't work";
		return -11;
	}
	interaction();
	return 0;
}
