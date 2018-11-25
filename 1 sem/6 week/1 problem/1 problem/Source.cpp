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

int calculation(const std::string &str)
{
	Stack *stack = createStack();
	int length = str.length();
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			int number2 = pop(stack);
			int number1 = pop(stack);
			int result = performingOperation(number1, number2, str[i]);
			push(stack, result);
		}
		else
		{
			const char numInStr = str[i];
			if (numInStr >= '0' && numInStr <= '9')
			{
				const int numInInt = atoi(&numInStr);
				push(stack, numInInt);
			}
		}
	}
	return pop(stack);
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
	int result = calculation(str);
	std::cout << result;
	return 0;
}