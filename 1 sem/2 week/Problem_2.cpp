#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cstdlib>

double exponentRecursive(int x, int exponent)
{
	if (exponent >= 0) 
	{
		if (exponent == 0)
		{
			return 1;
		}
		else if (exponent % 2 == 1)
		{
			return x * exponentRecursive(x, exponent - 1);
		}
		else
		{	
			int current = exponentRecursive(x, exponent / 2);
			return current * current;
		}
	}
	else 
	{
		if (exponent == 0)
		{
			return -1;
		}
		else if (abs(exponent % 2) == 1)
		{
			return exponentRecursive(x, exponent + 1) / x;
		}
		else
		{
			int current = exponentRecursive(x, exponent / 2);
			return current * current;
		}
	}
}

double exponentPrevious(int x, int exponent) 
{
	double result = 1;

	for (int i = 0; i < abs(exponent); ++i) 
	{
		if (exponent > 0) 
		{
			result *= x;
		}
		if (exponent < 0)
		{
			result /= x;
		}
	}
	return result;
}

bool test()
{
	if (exponentRecursive(2, 5) == 32 && exponentRecursive(2, -1) == 0.5 &&
		exponentRecursive(-5, 3) == -125 && exponentRecursive(-5, 2) == 25 &&
		exponentPrevious(2, 5) == 32 && exponentPrevious(2, -1) == 0.5 && 
		exponentPrevious(-5, 3) == -125 && exponentPrevious(-5, 2) == 25 &&
		exponentPrevious(-2, 0) == 1 && exponentRecursive(-2, 0) == 1)
	{ 
		return true;
	}
	else
	{
		return false;
	}
}

int main() 
{
	if (test())
	{
		int	x = 0;
		int exponent = 0;

		printf("%s", "Enter foundation of degree  =  ");
		scanf("%d", &x);
		printf("%s", "Enter exponent  =  ");
		scanf("%d", &exponent);
		
		printf("%s%f", "Result of recursive exponentiation  =  ", exponentRecursive(x, exponent));
		printf("\n");
		printf("%s%f", "Result of sequential exponentiation  =  ", exponentPrevious(x, exponent));
	}
	else
	{
		printf("Everything is bad :( ");
	}

	return 0;
}
