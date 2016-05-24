#include <stdio.h>

#define uint unsigned int

/*
 * Given a number N, replace bits from position i to j with bits of M
 */
void maskbits(int N, int M, int i, int j)
{
  int idx, maskl = 0, maskr = 0, mask = 0;
  int max = ~0; //All 1-s
  maskl = max - ((1<<(j+1))-1); //all ones through j, then 0-s
  // MASKL = [ 11111111111111111111111110000000 ]
  maskr = (1<<i)-1; //all 1-s right of ith bit
  //MASKR = [ 00000000000000000000000000000011 ]
  mask = maskl|maskr;
  N = N & mask;
  N = N | (M<<i);
  //printf("\n maskl: %d, maskr: %d, mask: %d",maskl, maskr, mask);
  printf("\n N is %d \n", N);
}

/*
 * Count the number of set bits in a number
 */
uint count_NumBitsSet (uint num)
{
  uint count = 0;
  while(num)
  {
    count++;
    num = num&(num-1); //make the rightmost 1 to 0
  }
  return (count);
}


/*
 * Count the number of bits different between 2 numbers
 */
uint count_NumBitsDelta(uint val1, uint val2)
{
  uint XoredVal, bits_delta;
  XoredVal = val1 ^ val2;
  bits_delta = count_NumBitsSet(XoredVal);
  return(bits_delta);
}

int main()
{
  int N = 2016, M = 21, i=2, j=7;
  uint count, num_bitcounter = 7;
  uint val1 = 31, val2 = 14, bits_delta;
  maskbits(N,M,i,j);
  /* Count the number of bits set in a number */
  count = count_NumBitsSet(num_bitcounter);
  printf("\n %d has %d bits set \n ", num_bitcounter, count);
  /* Count the number of bits 2 nos differ by */
  bits_delta = count_NumBitsDelta(val1, val2);
  printf("\n %d and %d differs by %d bits \n ", val1, val2, bits_delta);


  return 0;
}
