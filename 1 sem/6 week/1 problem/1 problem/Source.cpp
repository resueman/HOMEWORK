#include "stack.h"
#include "test.h"
#include <iostream>

using namespace stack;

int performingOperation(int number1, int number2, char operation)
{
	int result = 0;
	switch (operation)
	{
	case '+':
		result = number1 + number2;
		break;
	case '-':
		result = number1 - number2;
		break;
	case '*':
		result = number1 * number2;
		break;
	case '/':
		result = number1 / number2;
		break;
	}
	return result;
}

int calculation(const std::string &str, bool &result)
{
	Stack *stack = createStack();
	int length = str.length();
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			int number2 = pop(stack, result);
			int number1 = pop(stack, result);
			int resultOfOperation = performingOperation(number1, number2, str[i]);
			push(stack, resultOfOperation);
		}
		else
		{
			const char numInStr = str[i];
			if (numInStr >= '0' && numInStr <= '9')
			{
				const int numInInt = numInStr - '0';
				push(stack, numInInt);
			}
		}
	}
	const int resultOfCalculation = pop(stack, result);
	deleteStack(stack);
	return resultOfCalculation;
}

int main()
{
	if (!test())
	{
		std::cout << "Program doesn't work ;(";
		return -1;
	}
	std::string str = "";
	std::cout << "Enter string  ";
	std::cin >> str;
	bool result = true;
	int resultOfCalculation = calculation(str, result);
	if (!result) 
	{
		std::cout << "Incorrect input";
		return -2;
	}
	std::cout << resultOfCalculation;

	return 0;
}
