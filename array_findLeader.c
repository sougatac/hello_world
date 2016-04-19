/*
Leaders in an array
Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right
side. And the rightmost element is always a leader. For example int the
array {16, 17, 4, 3, 5, 2, 0}, leaders are 17, 5 and 2.

ALGO:
Start from the right. rightmost element is always the leader and make it max
if any element is greater than max, print it as leader and update max. 
*/


#include <stdio.h>
#include <stdlib.h>

void findLeader(int* arr, int len)
{
  int i, max = 0;
  max = arr[len-1];
  printf("\n Leaders are: \n %d", arr[len-1]);
  for(i=len-1; i>=0; i--)
  {
    if(arr[i] > max)
    {
      printf("\n %d", arr[i]);
      max = arr[i];
    }
  }
  printf("\n");
}

int main()
{
  int arr[] = {16,17,4,3,5,2,0};
  int len;
  len = sizeof(arr)/sizeof(arr[0]);
  findLeader(arr, len);
}
