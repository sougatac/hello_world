/* =============================================================
 *
 *   HEADER FILE TREE_UTILS.H
 * Contains declaration of all the common functions used in all
 * the tree programs. These functions are defined in tree_utils.c
 * =============================================================
 */

/* =========================================
 * Header includes and Defines
 * ========================================= */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

/* =========================================
 * Typedefs
 * ========================================= */

 //Node type
typedef struct Node
{
  int val;
  struct Node *left, *right;
}Node;

/* =========================================
 * FUNCTION PROTOTYPES
 * ========================================= */

 //create a node
Node* create(int);

//Do an in-order traversal of  binary tree
void inorder(Node*);

//Do a pre-order traversal of  binary tree
void preorder(Node*);

//Do a post-order traversal of  binary tree
void postorder(Node*);

//Calculate maximum depth of a binary tree
int max_depth(Node*);

//Do a level-wise traversal of a tree
void print_levelwise(Node*);
