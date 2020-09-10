/*  Exercise 2-6. 
    Write a function setbits(x,p,n,y) that returns x with the n bits that 
    begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
    
    编写一个函数 setbits(x, p ,n, y)，该函数返回对 x 执行下列操作后的结果值: 
    将 x 中从第 p 位开始的 n 个(二进制)位设置为 y 中最右边 n 位的值，x 的其余各位保持不变。
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((y & (~((~0) << n))) << (p - 1)) | (x & (~((~(~0 << n)) << (p - 1))));
}

int main()
{
    unsigned x = 0b0010110010010000;
    unsigned y = 0b0111011011101001;
    unsigned z;
    int p = 7;
    int n = 6;

    z = setbits(x, p, n, y);
    printf("z is %u\n", z);

    return 0;
}