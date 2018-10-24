#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int fibRecursive(int n)
{
	if (n < 0) 
	{
		return 0;
	}
	if (n > 2)
	{
		return fibRecursive(n - 1) + fibRecursive(n - 2);
	}
	else
	{
		return 1;
	}	
}

int fibIterative(int n)
{
	int prev1 = 1;
	int prev2 = 1;
	int current = 0;
	if (n > 2) 
	{
		for (int i = 0; i < n - 2; ++i)
		{
			current = prev1 + prev2;
			prev1 = prev2;
			prev2 = current;
		}
	}
	else if (n == 1 || n == 2) current = 1;
	return current;
}

int test()
{
	if (fibIterative(1) == 1 && fibIterative(5) == 5 && fibIterative(-3) == 0 && 
		fibRecursive(1) == 1 && fibRecursive(6) == 8 && fibRecursive(-3) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
int main() 
{	
	if (test() == 0)
	{
		printf("%s", "Everything is bad :( ");
	}
	else
	{
		int n = 0;

		printf("%s", "Enter N  =  ");
		scanf("%d", &n);

		if (n > 0) 
		{
			printf("%s", "**Iterative counting**\n");
			printf("%s%d", "F(N)  =  ", fibIterative(n));
			printf("%s", "\n");
			printf("%s", "**Recursive counting**\n");
			printf("%s%d", "F(N)  =  ", fibRecursive(n));
		}
		else 
		{
			printf("%s", "Incorrect input\n");
		}

		return 0;
	}
}
