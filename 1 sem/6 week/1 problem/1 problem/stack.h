#pragma once


namespace stack
{
	struct Stack;

	//Creates a new instance of stack.
	Stack *createStack();

	//Add element to stack
	void push(Stack *stack, char data);

	//This function pop element from stack and return it's value 
	int pop(Stack *stack);

	//This function return true if stack is empty
	bool isEmpty(Stack *stack);

	//Delete stack
	void deleteStack(Stack &stack);
}