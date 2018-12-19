#pragma once

struct Queue;

Queue* createQueue();

void deleteQueue(Queue*& queue);

bool isEmpty(Queue* queue);

void enqueue(Queue* queue, const int begin, const int end, const int pathLength);

void dequeue(Queue* queue);
