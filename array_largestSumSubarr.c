/*

Write an efficient C program to find the sum of contiguous subarray
within a one-dimensional array of numbers which has the largest sum.

Kadane’s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
Explanation:
Simple idea of the Kadane's algorithm is to look for all positive
contiguous segments of the array (max_ending_here is used for this).
And keep track of maximum sum contiguous segment among all positive
segments (max_so_far is used for this). Each time we get a positive
sum compare it with max_so_far and update max_so_far if it is greater
than max_so_far

Notes:
Algorithm doesn't work for all negative numbers. It simply returns 0 if
all numbers are negative. For handling this we can add an extra phase before
actual implementation. The phase will look if all numbers are negative,
if they are it will return maximum of them (or smallest in terms of absolute
value). There may be other ways to handle it though.
*/


#include <stdio.h>
#include <stdlib.h>

int maxSubarrSum(int* arr, int len)
{
int i, sum = 0, maxSum = 0;
for(i=0; i<len; i++)
{
  sum+=arr[i];
  if(sum<0)
    sum = 0;
  if(maxSum < sum)
    maxSum = sum;
}
return(maxSum);
}

int main()
{
  //int arr[] = {2,3,5,-7,1,-2,4,5,-2,1,9,-11,-15,20};
  int arr[] = {-2,-3,4,-1,-2,1,5,-3};
  //int arr[] = {-2,-3,-1};
  int len, maxSum;
  len = sizeof(arr)/sizeof(arr[0]);
  maxSum = maxSubarrSum(arr, len);
  printf("\n Max sum of the subarray : %d \n", maxSum);
}
