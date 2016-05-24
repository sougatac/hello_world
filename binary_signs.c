/*
 * WAP to find out:
 * 1. if a number id positive or -ve
 * 2. if 2 numbers have different signs
 */

#include <stdio.h>
#include <stdbool.h>

#define CHAR_BITS 8

/* Check if a number is positive */
bool ispositive (int num)
{
  //sizeof(int) = 4, multiply by 8 gives 32, sub 1 gives 31.
  //Rightshift num by 31 bits and see if it's 1 or 0
  return ~(num >> (sizeof(int) * CHAR_BITS - 1));
}

/* check if 2 numbers are of same sign */
bool isSameSign(int x, int y)
{
  return ~((x^y) >> ((sizeof(int)) * CHAR_BITS - 1));
}

/* Main driver func */
int main()
{
  int num = -234;
  int num1 = 5, num2 = 476;
  bool sign;
  sign = ispositive(num);
  if(sign)
    printf("\n Number: %d is positive\n", num);
  else
    printf("\n Number: %d is negetive\n", num);

  if(isSameSign(num2, num1))
    printf("\n %d and %d are of same sign \n", num1, num2);
  else
    printf("\n %d and %d are not of same sign \n", num1, num2);
}
