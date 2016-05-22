/*
Prob statement:
1. sumtree
2. levelwise print of tree

This function checks if the tree is a valid sum tree.
Then it checks if it has a valid child sum property.
If it doesn't have a valid child sum property, it converts
the tree into one that obeys the child sum proprty for each node.
*/


#include "tree_utils.h"

/*
Sample tree:
A sumtree is a tree that has every node as the sum of it's
left and right subtree

================== TREE 1 ==================
               80
      14                  26
  5       2          7         6
3   2       2      2   5     4   2



================== TREE 2 ==================

         10
   8                2
3       5       2

*/


int sum_subtree (Node* node)
{
  if(node == NULL)
    return 0;
  else
    return(node->val +
          sum_subtree(node->left) +
          sum_subtree(node->right));
}

/*
 * Sum Tree property :
 * Value of a node = value of it's child sub trees
 */

bool isValidSumTree(Node* root)
{
  int left_sum, right_sum;
  //terminate leaf too, as leaf val = NULL+NULL won't be true
  if((root == NULL) ||
     ((root->left == NULL) && (root->right == NULL)))
    return TRUE;

  //Get values of left subtree and right subtree and check if it's node
  left_sum = sum_subtree(root->left);
  right_sum = sum_subtree(root->right);

  //printf("\n DBG: node:%d, ls: %d, rs:%d ", root->data, left_sum, right_sum);
  //And recursively check left and right subtree.
  if((root->val == left_sum + right_sum)
      &&(isValidSumTree(root->left))
      &&(isValidSumTree(root->right)))
    return TRUE;

  return FALSE;
}
/*
 * Child Sum property
 * value of a node = sum of the values of it's child nodes
 */
bool isValidChildSumProp(Node* root)
{
  int leftdata = 0, rightdata = 0;
  //terminate leaf too, as leaf val = NULL+NULL won't be true
  if((root == NULL) ||
     ((root->left == NULL) && (root->right == NULL)))
    return TRUE;

  if(root->left != NULL)
    leftdata = root->left->val;
  if(root->right != NULL)
    rightdata = root->right->val;

  if((root->val == leftdata + rightdata) &&
     (isValidChildSumProp(root->left)) &&
     (isValidChildSumProp(root->right)))
    return TRUE;
  return FALSE;
}

/*
 * Convery a binary tree to have a valid child sum property
 * you can increment or decrement value of each node
 */
void makeValidChildSumTree(Node* root)
{
  int l_val = 0, r_val = 0;
  if(root == NULL)
    return;
  if((root->left == NULL) && (root->right == NULL))
    return;
  /*
   * We cannot use the same approach as checking if it's a
   * valid child-sum tree, coz the top-down approach won't
   * work here...so we have to go bottom up
   */
  makeValidChildSumTree(root->left);
  makeValidChildSumTree(root->right);
  if(root->left)
    l_val = root->left->val;
  if(root->right)
    r_val = root->right->val;

  root->val = l_val + r_val;
}

int main()
{
  Node *root, *root1;
  //Tree to test sumtree property

  root1 = create(80);
  root1->left = create(14);
  root1->right = create(26);
  root1->left->left = create(5);
  root1->left->right = create(2);
  root1->right->left = create(7);
  root1->right->right = create(6);
  root1->left->left->left = create(3);
  root1->left->left->right = create(2);
  root1->left->right->right = create(2);
  root1->right->left->left = create(2);
  root1->right->left->right = create(5);
  root1->right->right->left = create(4);
  root1->right->right->right = create(2);


//Tree to test child parent sum property
root = create(10);
root->left = create(8);
root->right = create(2);
root->left->left = create(3);
root->left->right = create(5);
root->right->left = create(2);


  print_levelwise(root1);
  if(isValidSumTree(root1))
    printf("\n Tree is a valid sum tree \n");
  else
    printf("\n Tree is NOT a valid sum tree \n");

    if(isValidChildSumProp(root1))
      printf("\n Tree has Valid Child-sum property \n");
    else
    {
      printf("\n Tree does NOT have valid Child-sum property");
      printf("\n Making it a valid child-sum property tree");
      makeValidChildSumTree(root1);
      print_levelwise(root1);
    }
  return 0;
}
