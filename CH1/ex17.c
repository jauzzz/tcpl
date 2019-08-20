/*  Exercise 1-17. 
    Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define MinLength 81
int getLine(char line[], int maxline);

int main()
{
    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > MinLength)
        {
            printf("LINE-CONTENTS:  %s\n", line);
        }

    return 0;
}

/* getline:  read a line into s, return length  */
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (i == (lim - 1))
    {
        while ((c = getchar()) != '\n')
        {
            ++i;
        }
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
