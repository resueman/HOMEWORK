#include "priorityQueue.h"

struct Edge
{
	int key = 0;
	int begin = 0;
	int end = 0;
	Edge* next = nullptr;
};

struct Queue
{
	Edge* head = nullptr;
};

Queue* createQueue()
{
	return new Queue;
}

bool isEmpty(Queue* queue)
{
	return queue->head == nullptr;
}

void deleteQueue(Queue*& queue)
{
	while (!isEmpty(queue))
	{
		Edge* temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	delete queue;
	queue = nullptr;
}

int getHeadBegin(Queue* queue)
{
	return queue->head->begin;
}

int getHeadEnd(Queue* queue)
{
	return queue->head->end;
}

void dequeue(Queue* queue)
{
	if (!isEmpty(queue))
	{
		Edge* temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
}

void enqueue(Queue* queue, const int begin, const int end, const int pathLength)
{
	Edge* newEdge = new Edge{ pathLength, begin, end, nullptr };
	if (isEmpty(queue))
	{
		queue->head = newEdge;
		return;
	}
	if (newEdge->key < queue->head->key)//to begin
	{
		newEdge->next = queue->head;
		queue->head = newEdge;
		return;
	}
	Edge* current = queue->head;
	while (current->next != nullptr && newEdge->key >= current->next->key)
	{
		current = current->next;
	}
	newEdge->next = current->next;
	current->next = newEdge;
}
