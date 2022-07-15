#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(int value)
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->data = value;
  q->next = NULL;
  return q;
}

Queue* createQueueWArr(int size, int *arr)
{
  Queue *q = createQueue(arr[0]);
  int i = 1;
  for( i = 1; i < size; i++)
  {
    q = enqueue(q, arr[i]);    
  }
  return q;
}

Queue *enqueue(Queue *q, int val)
{
  if( q == NULL)
  {
    return createQueue(val);
  }
  q->next = enqueue(q->next, val);
  return q;
}

Queue *dequeue(Queue *q)
{
  q = q->next;
  return q;
}

int returnFirstInQueue(Queue *q)
{
  return q->data;
}

void printQueue(Queue *q)
{
  if(q == NULL)
  {
    return;
  }
  printf("%d ", q->data);
  printQueue(q->next);
}

void freeQueue(Queue *q)
{
  if (q == NULL)
  {
    return;
  }
  freeQueue(q->next);
  free(q);
}

void testQueue(int size, int *array)
{
  Queue *root = createQueueWArr(size, array);
  printQueue(root);
  printf("\nFirst in Queue: %d", returnFirstInQueue(root));
  root = dequeue(root);
  printf("\nDequeue...\n");
  printQueue(root);
  freeQueue(root);
}