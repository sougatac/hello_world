/*
 * Search for a number in a 2D array where elements increase from left to right 
 * and top to bottom. If element is found, return TRUE...and print the position. 
 *
 * 1   2   3   5   9
 * 2   4   5   6   10
 * 4   7   8   10  12
 * 8   11  13  14  17
 * 15  18  19  21  23
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>

#define NUM_COLUMNS 5
#define NUM_ROWS 5
#define FALSE 0
#define TRUE 1

/*
 * The matrix where elements are increasing from left to right and from top to
 * bottom.
 */

int matrix[NUM_COLUMNS][NUM_ROWS] = {{1,2,3,5,9},
                                     {2,4,5,6,10},
                                     {4,7,8,10,12},
                                     {8,11,13,14,17},
                                     {15,18,19,21,23}};
/*
 * Routine to find whether an element is present.
 * Start with top right and return when a match is found.
 * If element is more than target, move left, else move down.
 *
 * Complexity: for a N X M array, complexity is O[N+M]
 */
bool find_Element(int target)
{
  int i = 0, j = NUM_COLUMNS-1, elem;

  while(i>=0 && j>=0)
  {
    elem = matrix[i][j];
    if(target == elem)
    {
      printf("\nMatch of %d found at [%d,%d]\n", target, i, j);
      return TRUE;
    }
    else if(elem < target)
      i++;
    else j--;
  }
  return FALSE;
}


int main()
{

  int target = 23;
  bool ispresent = find_Element(target);
  printf("\nElement %d search status: %u\n",target, ispresent);
  return 0;
 }
