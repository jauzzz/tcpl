/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 * 
 * 编写程序 detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止的地方。
 * 制表符：将光标移到最接近 8 的倍数的位置，使得后面的输出从此开始
 */

#include <stdio.h>

#define TAB 8

//将制表符替换为适当的空格，并且空格填充到下一个制表符终止位
void main()
{
    int c, pos, i, nbs;
    pos = 1;
    nbs = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            // nbs 需要填补的空格
            nbs = (TAB - pos % TAB) % TAB + 1;
            i = 0;
            for (; i < nbs; i++)
            {
                putchar(' ');
            }
            pos += nbs;
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 1;
            nbs = 0;
        }
        else
        {
            pos++;
            putchar(c);
        }
    }
}