#include "stack.h"

struct StackElement;

struct stack::Stack
{
	StackElement *head = nullptr;
};

struct StackElement
{
	char data;
	StackElement *next = nullptr;
};

stack::Stack *stack::createStack()
{
	return new Stack;
}

void stack::push(stack::Stack *stack, char data)
{
	auto newElement = new StackElement{ data, stack->head };
	stack->head = newElement;
}

int stack::pop(stack::Stack *stack, bool &result)
{
	if (isEmpty(stack))
	{
		result = false;
		return -1;
	}
	StackElement *temp = stack->head;
	stack->head = stack->head->next;
	char value = temp->data;
	delete temp;
	temp = nullptr;
	return value;
}

bool stack::isEmpty(stack::Stack *stack)
{
	return stack->head == nullptr;
}

void stack::deleteStack(stack::Stack *stack)
{
	while (stack->head != nullptr)
	{
		StackElement *temp = stack->head;
		stack->head = temp->next;
		delete temp;
		temp = nullptr;
	}
	delete stack;
	stack = nullptr;
}
