#ifndef BST_H
#define BST_H
 
typedef struct BST
{
  int data;
  struct BST *left;
  struct BST *right;
} BST;

BST *createBST( int value );
BST *createBSTNode( int value );
BST *insertBST( BST *node, int key );
BST *removeBST( BST *node, int key );
BST *createBSTWArr( int size, int *data );
void freeBST(BST *root );
void inorder_traversal( BST* root);
void testBST(int size, int *array);
 
#endif