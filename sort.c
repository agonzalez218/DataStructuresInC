#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void swap(int *a, int *b)
{
  int tempPTR = *a;
  *a = *b;
  *b = tempPTR;
}

void printArray(int size, int *nums)
{
  int i = 0;
  for( i = 0; i < size; i++)
  {
    printf("%d ", nums[i]);    
  }
  printf("\n");
}

void selectionSort(int size, int *nums)
{
  int i, j, minIndx;
  for( i = 0; i < size - 1; i++ )
  {
    minIndx = i;
    for( j = i+1; j < size; j++ )
    {
      if( nums[j] < nums[minIndx] )
      {
        minIndx = j;
      }
    }
    swap(&nums[minIndx], &nums[i]);
  }
}

void bubbleSort(int size, int *nums)
{
  int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (nums[j] > nums[j + 1])
                swap(&nums[j], &nums[j + 1]);
}

void insertionSort(int size, int *nums)
{
  int i, key, j;
    for (i = 1; i < size; i++) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

void testSelectionSort(int size, int *array)
{
  printf("\n\nOriginal Array:\n");
  printArray(size, array);
  printf("Selection Sort Results:\n");
  clock_t t;
  t = clock();
  selectionSort(size, array);
  t = clock() - t;
  printArray(size, array);
  printf("Time taken to sort: %f s\n", ((double)t)/CLOCKS_PER_SEC);
}

void testInsertionSort(int size, int *array)
{
  printf("\nOriginal Array:\n");
  printArray(size, array);
  printf("Insertion Sort Results:\n");
  clock_t t;
  t = clock();
  insertionSort(size, array);
  t = clock() - t;
  printArray(size, array);
  printf("Time taken to sort: %f s\n", ((double)t)/CLOCKS_PER_SEC);
}

void testBubbleSort(int size, int *array)
{
  printf("\nOriginal Array:\n");
  printArray(size, array);
  printf("Bubble Sort Results:\n");
  clock_t t;
  t = clock();
  bubbleSort(size, array);
  t = clock() - t;
  printArray(size, array);
  printf("Time taken to sort: %f s\n", ((double)t)/CLOCKS_PER_SEC);
}

void testQuickSort(int size, int *array)
{
  printf("\nOriginal Array:\n");
  printArray(size, array);
  printf("Quick Sort Results:\n");
  clock_t t;
  t = clock();
  quickSort(array, 0, size-1);
  t = clock() - t;
  printArray(size, array);
  printf("Time taken to sort: %f s\n", ((double)t)/CLOCKS_PER_SEC);
}

void testMergeSort(int size, int *array)
{
  printf("\nOriginal Array:\n");
  printArray(size, array);
  printf("Merge Sort Results:\n");
  clock_t t;
  t = clock();
  mergeSort(array, 0, size-1);
  t = clock() - t;
  printArray(size, array);
  printf("Time taken to sort: %f s\n", ((double)t)/CLOCKS_PER_SEC);
}