/*  Exercise 2-7. 
    Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted 
    (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return (x & (~((~(~0 << n)) << (p - 1)))) | ((~(x >> (p - 1))) & (~(~0 << n)) << (p - 1));
}

int main()
{
    unsigned x = 0b0010110010010000;
    unsigned z;
    int p = 7;
    int n = 3;

    // x = 0010 1100 1001 0000
    // z = 0010 1100 0001 0000
    z = invert(x, p, n);
    printf("z is %u\n", z);

    return 0;
}