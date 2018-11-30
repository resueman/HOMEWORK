#include "queue.h"

struct QueueElement
{
	int data = 0;
	QueueElement* next = nullptr;
};

struct Queue
{
	QueueElement* head = nullptr;
	QueueElement* tail = nullptr;
};

bool isEmpty(Queue* queue)
{
	return queue->head == nullptr;
}

void enqueue(Queue* queue, int data)
{
	auto newElement = new QueueElement{ data, nullptr };
	if (isEmpty(queue))
	{
		queue->head = newElement;
		queue->tail = queue->head;
	}
	else
	{
		queue->tail->next = newElement;
		queue->tail = newElement;
	}
}

int dequeue(Queue* queue)
{

	int const value = queue->head->data;
	if (queue->head == queue->tail)
	{
		queue->head = nullptr;
		queue->tail = nullptr;
		delete queue->head;
	}
	else
	{
		QueueElement* temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	return value;
}

void deleteQueue(Queue* queue)
{
	while (!isEmpty(queue))
	{
		QueueElement* temp = queue->head;
		queue->head = queue->head->next;
		delete temp;
	}
	queue = nullptr;
	delete queue;
}

Queue* createQueue()
{
	return new Queue;
}
