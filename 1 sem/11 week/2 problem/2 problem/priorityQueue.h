#pragma once

struct Queue;

///create queue
Queue* createQueue();

///delete queue
void deleteQueue(Queue*& queue);

///if queue is empty return true, else return false
bool isEmpty(Queue* queue);

///add element to priority queue by key(in ascending order)
void enqueue(Queue* queue, const int begin, const int end, const int pathLength);

///delete element from queue
void dequeue(Queue* queue);
