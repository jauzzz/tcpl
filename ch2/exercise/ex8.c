/*  Exercise 2-8. 
    Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.

    编写一个函数 rightrot(x,n)，该函数返回将 x 循环右移（即从最右端移出的位将从最左端移入）n （二进制）位后所得到的值.
*/

#include <limits.h>
#include <stdio.h>

unsigned rightrot(unsigned x, int n)

{
    return (x << ((sizeof(unsigned) * CHAR_BIT) - n)) | (x >> n);
}

int main()

{
    unsigned x, y;

    x = 0x10;
    printf("rightrot(0x%08x, 3) = 0x%08x\n", x, y = rightrot(x, 3));
    x = y;
    printf("rightrot(0x%08x, 3) = 0x%08x\n", x, y = rightrot(x, 3));

    return 0;
}