#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 
typedef struct LinkedList
{
  int data;
  struct LinkedList *next;
} LinkedList;

LinkedList *createLinkedList( int value );
LinkedList *createLinkedListNode( int value );
LinkedList *insertLinkedList( LinkedList *node, int key );
LinkedList *removeLinkedList( LinkedList *node, int key );
LinkedList *createLinkedListWArr( int size, int *data );
void freeLinkedList(LinkedList *root );
void printLinkedList(LinkedList *root );
void testLinkedList(int size, int *array);

#endif