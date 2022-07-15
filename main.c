#include <stdio.h>
#include "BST.h"
#include "LinkedList.h"
#include "minheap.h"
#include "queue.h"
#include "stack.h"
#include "set.h"
#include "sort.h"

int main(void) {
  
  int size = 6;
  int nums[] = {1,65,4,6,65,64};
  int origArray[] = {1,65,4,6,65,64};
  printf("Array = {1,65,4,6,65,64}\nSize = 6\n\n");
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
  int nums2[] = {1,65,4,6,65,64};
  testSelectionSort( size, nums2 );
  int nums3[] = {1,65,4,6,65,64};
  testInsertionSort( size, nums3 );
  int nums4[] = {1,65,4,6,65,64};
  testBubbleSort( size, nums4 );
  int nums5[] = {1,65,4,6,65,64};
  testQuickSort(size, nums5 );
  int nums6[] = {1,65,4,6,65,64};
  testMergeSort(size, nums6 );
  
  return 0;
}