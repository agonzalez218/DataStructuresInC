#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(int val)
{
  Stack *s = (Stack*)malloc(sizeof(Stack));
  s->data = val;
  s->next = NULL;
  return s;
}

Stack* createStackWArr(int size, int *arr)
{
  int i = 0;
  Stack *s = createStack(arr[0]);
  for(i = 1; i < size; i++)
  {
    s = push(s, arr[i]);    
  }
  return s;
}

Stack* push(Stack *s, int value)
{
  if( s == NULL )
  {
    return createStack(value);
  }
  s->next = push(s->next, value);
  return s;
}

Stack* pop(Stack *s)
{
  Stack* ptr;
  ptr = s;
  while(ptr->next->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = NULL;
  return s;
}

int returnFirstInStack(Stack *s)
{
  while(s->next != NULL)
  {
    s = s->next;
  }
  return s->data;
}

void printStack(Stack *s)
{
  if(s == NULL)
  {
    return;
  }
  printStack(s->next);
  printf("%d ",s->data);
}

void freeStack(Stack *s)
{
  if (s == NULL)
  {
    return;
  }
  freeStack(s->next);
  free(s);
}

void testStack(int size, int *array)
{
  Stack *root = createStackWArr(size, array);
  printStack(root);
  printf("\nFirst in Stack: %d", returnFirstInStack(root));
  root = pop(root);
  printf("\nPop...\n");
  printStack(root);
  freeStack(root);
}