
/* =============================================================
 *
 *   UTILS FILE TREE_UTILS.C
 * Contains definition of all the common functions used in all
 * the tree programs. These functions are declared in tree_utils.c
 * =============================================================
 */

/* =========================================
 * Header includes
 * include all public standard defined libraries in
 * tree utils.h
 * ========================================= */

#include "tree_utils.h"

/* =========================================
 * FUNCTION DEFINITIONS
 * ========================================= */

/*
 ==================== Create a Node ====================
 This function creates a node and stores the value passed to
 it. The children are set to NULL.
 Return: the pointer to the new node
*/
Node* create(int data)
{
  Node* temp = (Node*) malloc(sizeof(Node));
  temp->val = data;
  temp->left = temp->right = NULL;
  return(temp);
}


/*
 ===================== In order traversal ===================
 This function does an inorder traversal of a tree and prints
 the nodes in-order
 Return: None
 */
void inorder(Node* root)
{
  if(root == NULL)
    return;

  inorder(root->left);
  printf("\t %d", root->val);
  inorder(root->right);
}


/*
 ===================== Pre order traversal ===================
 This function does an preorder traversal of a tree and prints
 the nodes pre-order
 Return: None
 */
void preorder(Node* root)
{
  if(root == NULL)
    return;

  printf("\t %d", root->val);
  preorder(root->left);
  preorder(root->right);
}


/*
 ===================== Post order traversal ===================
 This function does an postorder traversal of a tree and prints
 the nodes post-order
 Return: None
 */
void postorder(Node* root)
{
  if(root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("\t %d", root->val);
}


/*
 ===================== Max-depth of a tree ===================
 This function finds the maximum depth of a tree. It's the number
 of nodes from the root to the leaf. the longest path is the
 max-depth.
 Return: [int] max - depth of the tree
 */
int max_depth(Node* root)
{
  int height;
  if(root == NULL)
    return 0;

  if(max_depth(root->left) > max_depth(root->right))
    height = max_depth(root->left) + 1;
  else
    height = max_depth(root->right) + 1;

  return height;
}


/*================ Level-wise traversal of a tree ==============
 Traverses levewise and prints a tree
 Return : None
 */

 /*
  * Prints a binary tree level wise
  * Traverse from level 1(root) to level 'h' (height)

 Function to print level order traversal of tree:
 printLevelorder(tree)
 for d = 1 to height(tree)
    printGivenLevel(tree, d);

 Function to print all nodes at a given level
 printGivenLevel(tree, level)
 if tree is NULL then return;
 if level is 1, then
     print(tree->data);
 else if level greater than 1, then
     printGivenLevel(tree->left, level-1);
     printGivenLevel(tree->right, level-1);

 */
void print_level(Node* root, int dep)
{
  if(root == NULL)
    return;
  if(dep == 0)
    printf("\t %d", root->val);

  while(dep>0)
  {
    print_level(root->left, dep-1);
    print_level(root->right, dep-1);
    dep-=1;
    return;
  }
}

void print_levelwise(Node* root)
{
  int max_dep, dep;
  if(root == NULL)
    return;
  max_dep = max_depth(root);
  printf("\n ===========================");
  printf("\n Tree depth: %d\n", max_dep);
  for(dep=0; dep<max_dep; dep++)
  {
    //printf("\n printing level: %d \n", dep);
    printf("\n");
    print_level(root, dep);
  }
  printf("\n ===========================\n");
}
