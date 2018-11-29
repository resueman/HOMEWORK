#include "stack.h"
#include "test.h"
#include <iostream>

using namespace stack;

int prioritet(char operation)
{
	switch (operation)
	{
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 1;
	case '/':
		return 1;
	}
	return 3;
}

bool topHasLowerPrec(Stack* stack, char operation)
{
	return prioritet(top(stack)) <= prioritet(operation);
}

bool isOpeningParantheses(char symbol)
{
	return symbol == '(';
}

bool isClosingParantheses(char symbol)
{
	return symbol == ')';
}

void doIfClosingParantheses(Stack* stack, std::string &postfixStr, bool &result)
{
	while (!isEmpty(stack) && !isOpeningParantheses(top(stack)))
	{
		postfixStr += top(stack);
		pop(stack, result);
	}
	pop(stack, result);
}

bool isOperand(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

void doIfOperator(Stack* stack, std::string &postfixStr, char symbol, bool &result)
{
	while (!isEmpty(stack) && topHasLowerPrec(stack, symbol) && !isOpeningParantheses(symbol))
	{
		postfixStr += top(stack);
		pop(stack, result);
	}
	push(stack, symbol);
}

void infixToPostfix(const std::string &infixStr, std::string &postfixStr)
{	
	Stack *stack = createStack();
	int length = infixStr.length();
	bool result = true;
	for (int i = 0; i < length; ++i)
	{
		if (isOperand(infixStr[i]))
		{
			postfixStr += infixStr[i];
		}
		else if (isOpeningParantheses(infixStr[i]))
		{
			push(stack, infixStr[i]);
		}
		else if (isOperator(infixStr[i]))
		{
			doIfOperator(stack, postfixStr, infixStr[i], result);
		}
		else if (isClosingParantheses(infixStr[i]))
		{
			doIfClosingParantheses(stack, postfixStr, result);
		}
	}
	while (!isEmpty(stack))
	{
		if (top(stack) == '(' || top(stack) == ')')
		{
			result = false;
			break;
		}
		else 
		{
			postfixStr += pop(stack, result);
		}
	}
	if (!result)
	{
		postfixStr = "Error! Incorrect input...\n";
	}
	deleteStack(stack);
}

int main()
{
	if (!test())
	{
		std::cout << "Program doesn't work ;(";
		return -1;
	}
	std::cout << "Enter infix string  ";
	std::string infixStr = "";
	std::cin >> infixStr;
	std::string postfixStr = "";
	infixToPostfix(infixStr, postfixStr);
	std::cout << postfixStr;

	return 0;
}