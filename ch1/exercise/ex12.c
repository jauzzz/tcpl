/* Exercise 1-12. 
    Write a program that prints its input one word per line. */

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, state;

    state = IN;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        if (state == IN)
        {
            putchar(c);
        }
        if (state == OUT)
        {
            putchar('\n');
            state = IN;
        }
    }
}