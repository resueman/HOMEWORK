#pragma once

namespace stack
{
	struct Stack;
	// Creates a new instance of stack.
	Stack *createStack();
	// Push element to stack
	void push(Stack *stack, char data);
	// Pop element from stack
	char pop(Stack *stack);
	//Check if stack is empty
	bool isEmpty(Stack *stack);
	//Delete stack
	void deleteStack(Stack &stack);
	char top(stack::Stack *stack);
}