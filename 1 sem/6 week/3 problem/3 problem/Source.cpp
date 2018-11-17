#include <iostream>
#include <conio.h>
#include "stack.h"
#include "test.h"

using namespace stack;

bool isOperand(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isOpeningParantheses(char symbol)
{
	return symbol == '(';
}

bool isClosingParantheses(char symbol)
{
	return symbol == ')';
}

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
	return 3; //for opening parantheses and numbers
}

bool topHasLowerPrec(Stack* stack, char operation)
{
	return prioritet(top(stack)) <= prioritet(operation);
}

void infixToPostfix(std::string &infixStr, std::string &postfixStr)
{	
	Stack *stack = createStack();
	int length = infixStr.length();
	bool correctness = true;
	for (int i = 0; i < length; ++i)
	{
		if (isOperand(infixStr[i]))
		{
			postfixStr += infixStr[i];
		}

		if (isOpeningParantheses(infixStr[i]))
		{
			push(stack, infixStr[i]);
		}
		
		if (isOperator(infixStr[i]))
		{
			while (!isEmpty(stack) && topHasLowerPrec(stack, infixStr[i]) && !isOpeningParantheses(infixStr[i]))
			{
				postfixStr += top(stack);
				pop(stack);
			}
			push(stack, infixStr[i]);
		}

		if (isClosingParantheses(infixStr[i]))
		{
			while (!isEmpty(stack) && !isOpeningParantheses(top(stack)))
			{
				postfixStr += top(stack);
				pop(stack);
			}
			if (isEmpty(stack))
			{
				correctness = false;
			}
			else
			{
				pop(stack);
			}
		}
	}

	while (!isEmpty(stack))
	{
		if (top(stack) == '(' || top(stack) == ')')
		{
			correctness = false;
			pop(stack);
		}
		else 
		{
			postfixStr += top(stack);
			pop(stack);
		}
	}
	if (!correctness)
	{
		postfixStr = "Error! Incorrect input...\n";
	}
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

	_getch();
	return 0;
}