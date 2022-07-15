#ifndef STACK_H
#define STACK_H
 
typedef struct Stack{
  int data;
  struct Stack *next;
} Stack;

Stack* createStack(int capacity);
Stack* createStackWArr(int capacity, int *arr);
Stack* push(Stack *stack, int value);
Stack* pop(Stack *stack);
int returnFirstInStack(Stack *s);
void printStack(Stack *stack);
void freeStack(Stack *stack);
void testStack(int size, int *array);

#endif