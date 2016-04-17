/*
 * WAP to find the missing number (between 1 ..... n+1) in an array of size n

Algo:
1) XOR all the array elements, let the result of XOR be X1.
2) XOR all numbers from 1 to n, let XOR be X2.
3) XOR of X1 and X2 gives the missing number.



Alternate Algo
1. Get the sum of numbers
       total = n*(n+1)/2
2  Subtract all the numbers from sum and
   you will get the missing number.

 */

 #include <stdio.h>

 int find_missing(int arr[], int len)
 {
   int x1 = 0, x2 = 0, num, i;
   for(i=0; i<len; i++)
     x1 = x1^arr[i];
   for(i=1; i<=len+1; i++)
     x2 = x2^i;
   return(x1^x2);
 }

int find_missing_bySum(int arr[], int len)
{
  //len is the number of elements in the array.
  //so array is 1...len+1
  int val = ((len+1)*(len+2))/2;
  int idx, sum=0;
  for(idx=0; idx<len; idx++)
  {
    sum+=arr[idx];
  }
  return(val-sum);
}

 int main()
 {
   int arr[] = {1,2,3,4,5,7,8,9,10,11,12,13};
   int len = sizeof(arr)/sizeof(arr[0]);
   int missing = find_missing(arr, len);
   printf("\n Missing no (by XOR) is: %d \n", missing);
   missing = find_missing_bySum(arr, len);
   printf("\n Missing no (by Sum) is: %d \n", missing);
   return 0;
 }
