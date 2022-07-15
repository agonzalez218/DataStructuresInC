#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set* createSet(int data)
{
  Set *s = (Set*)malloc(sizeof(Set));
  s->data = data;
  s->left = NULL;
  s->right = NULL;
  return s;
}

Set* createSetWArr(int size, int *arr)
{
  int i = 1;
  Set *s = createSet(arr[0]);
  for(i = 1; i < size; i++)
  {
    s = insertIntoSet(s, arr[i]); 
  }
  return s;
}

void removeFromSet(Set *s, int value)
{
  
}

Set *insertIntoSet(Set *s, int key)
{
  if (s == NULL)
  {
    return createSet(key); 
  }
  if (key < s->data) 
  {
    s->left = insertIntoSet(s->left, key);
  } 
  else if (key > s->data) 
  {
    s->right = insertIntoSet(s->right, key);    
  }
  return s; 
}

void printSet(Set *s)
{
  if(s != NULL) {
      printSet(s->left);
      printf("%d ",s->data);          
      printSet(s->right);
   }
}

void freeSet(Set *s)
{
  if (s == NULL)
  {
    return; 
  }
  freeSet(s->left); 
  freeSet(s->right); 
  free(s); 
}

void testSet(int size, int *array)
{
  Set *root = createSetWArr(size, array);
  printSet(root);
  freeSet(root);
}