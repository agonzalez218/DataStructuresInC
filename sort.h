#ifndef SORT_H
#define SORT_H

void swap(int *a, int *b);
void printArray(int size, int *nums);
void selectionSort(int size, int *nums);
void merge(int *nums, int l, int m, int r);
void bubbleSort(int size, int *nums);
void insertionSort(int size, int *nums);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high); 
void testSelectionSort(int size, int *array);
void testInsertionSort(int size, int *array);
void testMergeSort(int size, int *array);
void testBubbleSort(int size, int *array);
void testQuickSort(int size, int *array);

#endif