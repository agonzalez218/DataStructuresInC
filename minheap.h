#ifndef MINHEAP_H
#define MINHEAP_H
 
typedef struct Heap{
  int *arr;
  int count;
  int capacity;
} Heap;

Heap *createHeap(int capacity);
void insertIntoMinHeap(Heap *h, int key);
void removeMinHeap(Heap *h, int key);
void printHeap(Heap *h);
void heapBottomUp(Heap *h,int index);
void heapTopDown(Heap *h, int parent);
Heap *createMinHeapWArr( int size, int *data);
void printMinHeap( Heap *root);
void freeMinHeap( Heap *root);
void testMinHeap(int size, int *array);

#endif