#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList *createLinkedList( int value )
{
  return createLinkedListNode(value);
}

LinkedList *createLinkedListNode( int value )
{
  LinkedList *temp = (LinkedList*)malloc(sizeof(LinkedList));
  temp->data = value;
  temp->next = NULL;
  return temp;
}

LinkedList *insertLinkedList( LinkedList *node, int key )
{
  if( node == NULL)
  {
    return createLinkedList(key);
  }
  node->next = insertLinkedList(node->next, key);
  return node;
}

LinkedList *removeLinkedList( LinkedList *node, int key )
{
  return node;
}

LinkedList *createLinkedListWArr( int size, int *data )
{
  int i = 0;
  LinkedList *root = createLinkedList(data[0]);
  for(i = 1; i < size; i++)
  {
    root = insertLinkedList(root, data[i]);    
  }
  return root;
}

void freeLinkedList(LinkedList *root )
{
  if (root == NULL)
  {
    return;
  }
  freeLinkedList(root->next);
  free(root);
}

void printLinkedList(LinkedList *root )
{
  if( root == NULL )
  {
    return;
  }
  printf("%d ", root->data);
  printLinkedList(root->next);
}

void testLinkedList(int size, int *array)
{
  LinkedList *root = createLinkedListWArr(size, array);
  printLinkedList(root);
  freeLinkedList(root);
}