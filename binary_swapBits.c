/*
 * Given a number x and two positions (from right side) in binary
 * representation of x, write a function that swaps n bits at given two
 * positions and returns the result. It is also given that the two sets of
 * bits do not overlap.

========== Example 1 ==========
Input:
x = 47 (00101111)
p1 = 1 (Start from second bit from right side)
p2 = 5 (Start from 6th bit from right side)
n = 3 (No of bits to be swapped)

so 001 gets swapped with 111
Output:
227 (11100011)
The 3 bits starting from the second bit (from right side) are
swapped with 3 bits starting from 6th position (from right side)


========== Example 2 ==========
Input:
x = 28 (11100)
p1 = 0 (Start from first bit from right side)
p2 = 3 (Start from 4th bit from right side)
n = 2 (No of bits to be swapped)
11 gets swapped with 00
Output:
7 (00111)
The 2 bits starting from 0th postion (from right side) are
swapped with 2 bits starting from 4th position (from right side)
 */

#include<stdio.h>

int swapbits (int num, int p1, int p2, int n)
{
  int mask1 = 0, mask2 = 0, bitno=0, mask=0, val1=0, val2=0;

  bitno = n;
  while (bitno)
  {
    mask1 |= 1;
    mask1 = mask1 << 1;
    bitno--;
  }
  mask1 = mask1<<p1; //[00001110]

  bitno = n;
  while (bitno)
  {
    mask2 |= 1;
    mask2 = mask2 << 1;
    bitno--;
  }
  mask2 = mask2<<p2; //[11100000]

//Extract the portions to be swapped
  val1 = num & mask1;
  val2 = num & mask2;

  mask = mask1|mask2; //[11101110]
  num &= ~mask; //clear the relevant bits to be swapped

  /* swap */
  val1 = val1>>p1;
  val1 = val1<<p2;
  num|=val1;

  val2 = val2>>p2;
  val2 = val2<<p1;
  num|=val2;

  return num;
}

int main()
{
  int num = 47;
  int p1 = 1, p2 = 5;
  int n = 3;
  int res = 0;
  res = swapbits(num, p1, p2, n);
  printf("\n Num: %d swapped [... %d ... %d...] %d bits is %d \n",
           num, p1, p2, n, res);
 }
