/*
 * Write a C program that, given an array A[] of n numbers
 * and another number x, determines whether or not there exist
 * two elements in S whose sum is exactly x.

 * Algo 1:
 *   Sort the array and then start looking from leftmost and
 *   rightmost together until l > r.
 *   If not found, return false.
 * Algo 2:
 *  Using Hashmap
 */


#include <stdio.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1

bool HASH[100] = {FALSE};

/* ========== Algo 1 ========== */
/*
 * By sorting, here complexity is time to sort, ie O[nLogn]
 * Once sorted, it's a linear time complexity.
 * Advantage is, it works scalably for +ve and -ve ints.
 */

void merge(int* arr, int left, int mid, int right)
{
 int size_l = (mid-left)+1;
 int size_r = (right-mid);
 int temp_l[size_l];
 int temp_r[size_r];
 int idx = left;
 int l=0,r=0;

 /* make temporary left and right sub arrays */
 for(int i=0; i<size_l; i++)
 {
   temp_l[i] = arr[left];
   left++;
 }
 for(int i=0; i<size_r; i++)
 {
   temp_r[i] = arr[mid+1];
   mid++;
 }

 /* merge sub-arrays until one of them is complete */
 while( l<size_l && r<size_r)
 {
   if(temp_l[l] < temp_r[r])
   {
     arr[idx] = temp_l[l];
     idx++;
     l++;
   }
   else
   {
     arr[idx] = temp_r[r];
     idx++;
     r++;
   }
 }

 /* once one is complete, merge the other blindly */
 if(l<size_l)
 {
   while(l<size_l)
   {
     arr[idx] = temp_l[l];
     l++;
     idx++;
   }
 }

 if(r<size_r)
 {
   while(r<size_r)
   {
     arr[idx] = temp_r[r];
     r++;
     idx++;
   }
 }
}
/*
* recursively call the same function until array size is broken down
* into single elements. Then start merging.
*/
void merge_sort(int * arr, int left, int right)
{
  int mid;
  if(left<right)
  {
    mid = (left+right)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1, right);
    merge(arr,left, mid, right);
  }
}

void findpair_BySorting(int* arr, int len, int sum)
{
  int l=0, r=len-1;
  merge_sort(arr,0,len-1);

 while(l<r)
 {
   if((arr[l]+arr[r]) == sum)
   {
     printf("\nSum: %d is found from adding %d and %d \n", sum, arr[l], arr[r]);
     return;
   }
   else if((arr[l]+arr[r]) < sum)
    l++;
   else
    r--;
 }
 printf("\nSum: %d not found by adding any 2 elements\n", sum);
 return;
}

/* ========== Algo 2 ========== */

/*
 * Using hashmap, time complexity is linear, but space complexity
 * increases.
 * Also, for -ve integers, we need a complicated hashing func.
 */

void findpair_ByHash (int* arr, int len, int sum)
{
  int i;
  for(i=0; i<len; i++)
  {
    if(HASH[sum-arr[i]])
    {
      printf("\nSum: %d is found from adding %d and %d \n", sum, arr[i], sum-arr[i]);
      return;
    }
    else
     HASH[arr[i]] = TRUE;
  }
    printf("\nSum: %d not found by adding any 2 elements\n", sum);
    return;
}


int main()
{
  int A[]={-2,1,12,3,9,4,-3,13,7,6,2,8,5,11,-5,14,15};
  int x1=17;
  int x2=29;
  int x3=50;
  int len = sizeof(A)/sizeof(A[0]);


  findpair_BySorting(A, len, x1);
  findpair_BySorting(A, len, x2);
  findpair_BySorting(A, len, x3);

//  findpair_ByHash(A, len, x1);
//  findpair_ByHash(A, len, x2);
//  findpair_ByHash(A, len, x3);

  return 0;
}
