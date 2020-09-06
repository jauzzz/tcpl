/*  Exercise 1-22. 
    Write a program to ``fold'' long input lines into two or more shorter lines 
    after the last non-blank character that occurs before the n-th column of input. 
    Make sure your program does something intelligent with very long lines, 
    and if there are no blanks or tabs before the specified column. 

    编写一个程序，把较长的输入行『折』成短一些的两行或者多行，折行的位置在输入行的第 n 列之前的最后一个非空格之后。
    要保证程序能够智能地处理输入行很长以及在指定的列前有空格或制表符时的情况。
*/

#include <stdio.h>

#define MAXLENGTH 10

int main()
{
    int c;
    int i = 1;
    int nb = 0;
    int nc = 0;
    int ntab = 0;

    /*
        1. 打印
        2. 判断是否要换行: 是否最后一个非空格
    */
    while ((c = getchar()) != EOF)
    {

        if (c == ' ')
        {
            ++nb;
        }
        else if (c == '\t')
        {
            ++ntab;
        }
        else
        {
            if (nc != 0)
            {
                while (nb > 0)
                {
                    putchar('!');
                    --nb;
                }
                while (ntab > 0)
                {
                    putchar('?');
                    --ntab;
                }
            }
            else
            {
                nb = 0;
                ntab = 0;
            }

            putchar(c);
            ++nc;
        }

        // 长度足够了，换行
        // printf("\ni: %d, c: %c\n", i, c);
        if (i == MAXLENGTH)
        {
            putchar('\n');
            i = 0;
            nc = 0;
        }
        ++i;
    }

    return 0;
}