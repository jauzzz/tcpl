/*  Exercise 1-8. 
    Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main()
{
    int c;
    int blanks = 0;
    int tabs = 0;
    int lines = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            blanks++;
        }
        else if (c == '\t')
        {
            tabs++;
        }
        else if (c == '\n')
        {
            lines++;
        }
    }

    printf("\n");
    printf("%d blanks, %d tabs, %d lines\n", blanks, tabs, lines);
}