/*  Exercise 1-10. 
    Write a program to copy its input to its output, 
    replacing each tab by \t, each backspace by \b, and each backslash by \\. 
    This makes tabs and backspaces visible in an unambiguous way. */

#include <stdio.h>

int main()
{
    int c;
    int blanks = 0;
    int tabs = 0;
    int lines = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
        {
            putchar(c);
        }
    }
}