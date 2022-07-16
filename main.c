#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "BST.h"
#include "LinkedList.h"
#include "minheap.h"
#include "queue.h"
#include "stack.h"
#include "set.h"
#include "sort.h"

int *createArray();
void generateTestData(int, int, int, int);

int main(void) {
  int size;
  generateTestData(20,1, 1000, 0);
  int *nums = createArray(&size);
  if( nums == NULL )
  {
    return 0;
  }
  printf("Array = ");
  printArray( size, nums);
  printf("Size = %d\n", size);
  printf("Binary Search Tree Results:\n");
  testBST(size, nums);
  printf("\n\nLinked List Results:\n");
  testLinkedList(size, nums);
  printf("\n\nMin Heap Results:\n");
  testMinHeap(size, nums);
  printf("\n\nQueue Results:\n");
  testQueue(size, nums);
  printf("\n\nStack Results:\n");
  testStack(size, nums);
  printf("\n\nSet Results:\n");
  testSet(size, nums);
  nums = createArray(&size);
  testSelectionSort( size, nums );
  nums = createArray(&size);
  testInsertionSort( size, nums );
  nums = createArray(&size);
  testBubbleSort( size, nums );
  nums = createArray(&size);
  testQuickSort(size, nums );
  nums = createArray(&size);
  testMergeSort(size, nums );
  
  return 0;
}

int *createArray(int *size)
{
  FILE* file = fopen("array.txt", "r");
  if( file == NULL )
  {
    return NULL;
  }
  char line[256];
  char *val = fgets(line, sizeof(line), file);
  if( val == NULL )
  {
    return NULL;
  }
  *size = atoi(line);
  int i = 0;
  int *nums = (int*)malloc(sizeof(int)**size);
  while (fgets(line, sizeof(line), file)) {
    nums[i] = atoi(line);
    i++;
  }
  fclose(file);
  return nums;
}

void generateTestData(int maxSize, int minSize, int maxNum, int minNum)
{
  FILE* file = fopen("array.txt", "w");
  if( file == NULL )
  {
    return;
  }
  char line[256];
  srand(time(0));
  int size = rand() % (maxSize + 1 - minSize) + minSize;
  int i = 0;
  fprintf(file,"%d\n",size);
  for(i = 0; i < size; i++)
  {
    fprintf(file,"%d\n",(rand() % (maxNum + 1 - minNum) + minNum));
  }
  fclose(file);
}