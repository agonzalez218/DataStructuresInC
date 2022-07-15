#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

BST *createBST( int num ) // create BST and return root node
{
	return createBSTNode(num);
}

BST *createBSTNode( int value )
{
  BST *tempBST = (BST*)malloc(sizeof(BST));
  tempBST->data = value;
  tempBST->left = NULL;
  tempBST->right = NULL;
  return tempBST;
}
 
BST *insertBST( BST *node, int key) // insert key into BST
{ 
  if (node == NULL)
  {
    return createBSTNode(key); 
  }
  if (key < node->data) 
  {
    node->left  = insertBST(node->left, key);
  } 
  else if (key > node->data) 
  {
    node->right = insertBST(node->right, key);    
  }
  return node; 
} 

BST *removeBST( BST *node, int key)
{ 
  
  return node; 
} 

BST *createBSTWArr( int size, int *data )
{
  int i = 0;
  BST *BSTRoot = createBST( data[ 0 ] );
  for(i = 1; i < size; i++)
  {
    BSTRoot = insertBST(BSTRoot, data[i]);
  }
  return BSTRoot;
}

void freeBST( BST* root)  
{ 
  if (root == NULL)
  {
    return; 
  }
  freeBST(root->left); 
  freeBST(root->right); 
  free(root); 
}  

void inorder_traversal( BST* root) {
   if(root != NULL) {
      inorder_traversal(root->left);
      printf("%d ",root->data);          
      inorder_traversal(root->right);
   }
}

void testBST(int size, int *array)
{
  BST *root = createBSTWArr(size, array);
  inorder_traversal(root);
  freeBST(root);
}