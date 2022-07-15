#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"

Heap *createHeap(int capacity)
{
  Heap *h = (Heap *)malloc(sizeof(Heap));
  h->count = 0;
  h->capacity = capacity;
  h->arr = (int *) malloc(capacity*sizeof(int));
  return h;
}

void insertIntoMinHeap(Heap *h, int key){
  if( h->count < h->capacity)
  {
    h->arr[h->count] = key;
    heapBottomUp(h, h->count);
    h->count++;
  }
}

void removeMinHeap(Heap *h, int key)
{
  
}

void heapBottomUp(Heap *h, int index){
  int temp;
  int parent = (index-1)/2;
  if(h->arr[parent] > h->arr[index])
  {
    temp = h->arr[parent];
    h->arr[parent] = h->arr[index];
    h->arr[index] = temp;
    heapBottomUp(h,parent);
  }
}

void heapTopDown(Heap *h, int parent){
  int left = parent*2+1, right = parent*2+2;
  int min, temp;
  if(left >= h->count || left < 0)
  {
    left = -1;
  }
  if(right >= h->count || right < 0)
  {
    right = -1;
  }
  if(left != -1 && h->arr[left] < h->arr[parent])
  {
    min=left;
  }
  else
  {
    min =parent;
  }
  if(right != -1 && h->arr[right] < h->arr[min])
  {
    min = right;
  }
  if(min != parent)
  {
    temp = h->arr[min];
    h->arr[min] = h->arr[parent];
    h->arr[parent] = temp;
    heapTopDown(h, min);
  }
}

Heap *createMinHeapWArr( int size, int *data)
{
  int i = 0;
  Heap *heap = createHeap(size);
  for(i = 0; i < size; i++)
  {
    insertIntoMinHeap(heap, data[i]);
  }
  return heap;
}

void printMinHeap( Heap *root)
{
  int i = 0;
  for(i = 0; i < root->count; i++)
  {
    printf("%d ", root->arr[i]);    
  }
}

void freeMinHeap( Heap *root )
{
  free(root->arr);
  free(root);
}

void testMinHeap(int size, int *array)
{
  Heap *root = createMinHeapWArr(size, array);
  printMinHeap(root);
  freeMinHeap(root);
}