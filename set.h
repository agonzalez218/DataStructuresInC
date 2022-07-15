#ifndef SET_H
#define SET_H

typedef struct Set{
  int data;
  struct Set *left;
  struct Set *right;
}Set;

Set* createSet(int data);
Set* createSetWArr(int size, int *arr);
void removeFromSet(Set *s, int value);
Set* insertIntoSet(Set *s, int value);
void printSet(Set *s);
void freeSet(Set *s);
void testSet(int size, int *array);

#endif