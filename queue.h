#ifndef QUEUE_H
#define QUEUE_H
 
typedef struct Queue{
  int data;
  struct Queue *next;
} Queue;

Queue* createQueue(int capacity);
Queue* createQueueWArr(int capacity, int *arr);
Queue *enqueue(Queue *queue, int value);
Queue *dequeue(Queue *queue);
int returnFirstInQueue(Queue *q);
void printQueue(Queue *queue);
void freeQueue(Queue *queue);
void testQueue(int size, int *array);

#endif