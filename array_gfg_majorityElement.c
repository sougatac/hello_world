/*
 * Majority Element: A majority element in an array A[] of size n
 * is an element that appears more than n/2 times (and hence there
 * is at most one such element).

 * Write a function which takes an array and emits the majority element
 * (if it exists), otherwise prints NONE.
 */

/*
Algo:
METHOD 3 (Using Moore’s Voting Algorithm)
This is a two step process.

1. Get an element occurring most of the time in the array.
This phase will make sure that if there is a majority element
then it will return that only.

2. Check if the element obtained from above step is majority element.

1. Finding a Candidate:
The algorithm for first phase that works in O(n) is known as
Moore’s Voting Algorithm. Basic idea of the algorithm is if we cancel
out each occurrence of an element e with all the other elements that
are different from e then e will exist till end if it is a majority element.

Above algorithm loops through each element and maintains a count of
a[maj_index], If next element is same then increments the count, if next
element is not same then decrements the count, and if the count reaches 0
then changes the maj_index to the current element and sets count to 1.
First Phase algorithm gives us a candidate element.
In second phase we need to check if the candidate is really a majority element.
Second phase is simple and can be easily done in O(n). We just need to check
if count of the candidate element is greater than n/2.
*/

#include <stdio.h>

void find_majority(int* arr, int len)
{
  int candidate, i=0, count;

  candidate = arr[i];
  count = 1;

  for(i=0; i<len; i++)
  {
    if(candidate == arr[i])
      count++;
    else
      count--;

    if (count == 0)
    {
      candidate = arr[i];
      count =1;
    }
  }
  count = 0;
  for(i=0; i<len; i++)
  {
    if(arr[i] == candidate)
      count++;
  }
  if(count > len/2)
    printf("\nMajority Element: %d\n", candidate);
  else
    printf("\n NONE \n");
}

#include <stdio.h>

int main()
{
  int arr[] = {5,4,5,8,5,4,4,7,4};
  int len = sizeof(arr)/sizeof(arr[0]);
  find_majority(arr, len);
  return 0;
}
