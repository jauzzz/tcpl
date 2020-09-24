/*
 * Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 * 
 * 编写程序entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。
 * 假设制表符终止位的位置与练习 1-20 的 detab 程序的情况相同。
 * 当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪一种替换字符比较好?
 */

#include <stdio.h>

#define TAB 8

int main()
{
    int c;
    int nb = 0;
    int ntab = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            nb++;
        }
        else
        {
            ntab = nb / TAB;
            nb = nb % TAB;

            while (ntab > 0)
            {
                putchar('\t');
                --ntab;
            }
            while (nb > 0)
            {
                putchar(' ');
                --nb;
            }
            putchar(c);
        }
    }

    return 0;
}