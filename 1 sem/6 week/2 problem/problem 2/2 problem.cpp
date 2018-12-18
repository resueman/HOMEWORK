#include "stack.h"
#include "test.h"
#include <iostream>

using namespace stack;

bool checkBalance(const std::string & str)
{
	Stack *stack = createStack();
	int length = str.length();
	bool result = true;
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == '[' || str[i] == '(' || str[i] == '{')
		{
			push(stack, str[i]);
		}
		if (str[i] == ']')
		{
			if (pop(stack, result) != '[')
			{
				deleteStack(stack);
				return false;
			}
		}
		if (str[i] == ')')
		{
			if (pop(stack, result) != '(')
			{
				deleteStack(stack);
				return false;
			}
		}
		if (str[i] == '}')
		{
			if (pop(stack, result) != '{')
			{
				deleteStack(stack);
				return false;
			}
		}
	}
	bool balance = isEmpty(stack);
	deleteStack(stack);
	return balance;
}

int main()
{
	if (!test())
	{
		std::cout << "Program doesn't work ;(";
		return -2;
	}
	std::string str = "";
	std::cout << "Enter string  ";
	std::cin >> str;
	if (checkBalance(str))
	{
		std::cout << "Balance";
	}
	else 
	{
		std::cout << "No balance";
	}
	return 0;
}
