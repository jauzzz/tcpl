/*
 * Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
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