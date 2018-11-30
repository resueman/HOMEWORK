#pragma once

struct Queue;

bool isEmpty(Queue* queue);

void enqueue(Queue* queue, int data);

int dequeue(Queue* queue);

void deleteQueue(Queue* queue);

Queue* createQueue();