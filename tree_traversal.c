/*
Depth First Traversals:
(a) Inorder
(b) Preorder
(c) Postorder

Breadth First or Level Order Traversal
Level wise traversal


================== TREE 1 ==================
               80
      14                  25
  5       2          17         6
3  42       21    2    55     4   12

*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ===================== typedef ===================

typedef struct Node
{
  int value;
  struct Node* left;
  struct Node* right;
}Node;

// ===================== Insert a node ===================

Node* insert (int val)
{
  Node* temp;
  temp = (Node*) malloc(sizeof(Node));
  temp->value = val;
  temp->left = NULL;
  temp->right = NULL;
  return(temp);
}

// ===================== In order traversal ===================
void inorder(Node* root)
{
  if(root == NULL)
    return;

  inorder(root->left);
  printf("\t %d", root->value);
  inorder(root->right);
}
// ===================== Pre order traversal ===================
void preorder(Node* root)
{
  if(root == NULL)
    return;

  printf("\t %d", root->value);
  preorder(root->left);
  preorder(root->right);
}
// ===================== Post order traversal ===================
void postorder(Node* root)
{
  if(root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("\t %d", root->value);
}

// ===================== Levelwise traversal ===================

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

void print_level(Node* root, int dep)
{
  if(root == NULL)
    return;
  if(dep == 0)
    printf("\t %d", root->value);

  while(dep>0)
  {
    print_level(root->left, dep-1);
    print_level(root->right, dep-1);
    dep-=1;
    return;
  }
}

void levelwise(Node* root)
{
  int max_dep, dep;
  if(root == NULL)
    return;
  max_dep = max_depth(root);
  printf("\n Tree depth: %d\n", max_dep);
  for(dep=0; dep<max_dep; dep++)
  {
    printf("\n printing level: %d \n", dep);
    print_level(root, dep);
  }
}
// ===================== MAIN ===================

int main ()
{
  Node* root;
  root = create(80);
  root->left = create(14);
  root->right = create (25);
  root->left->left = create(5);
  root->left->right = create(2);
  root->right->left = create (17);
  root->right->right = create (6);
  root->left->left->left = create(3);
  root->left->left->right = create(42);
  root->left->right->right = create(21);
  root->right->left->left = crete (2);
  root->right->left->right = create (55);
  root->right->right->left = create (4);
  root->right->right->right = create (12);

  //Traversals:
  printf("\n Depth first: \n ");
  printf("\n In order Traversal: \n");
  inorder(root);
  printf("\n");

  printf("\n Pre order Traversal: \n");
  preorder(root);
  printf("\n");

  printf("\n Post order Traversal: \n");
  postorder(root);
  printf("\n");

  printf("\n Breath first: \n ");
  printf("\n Level wise Traversal: \n");
  levelwise(root);
  printf("\n");

  return 0;
}
