/*  Exercise 1-18. 
    Write a program to remove trailing blanks and tabs from each line of input,
    and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getLine(char line[], int maxline);
int strip(char line[], int length);

/* print the longest input line */
int main()
{
    int len;
    char line[MAXLINE];
    char longest[MAXLINE]; /* longest line saved here */
    /* current line length */
    /* maximum length seen so far */

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (strip(line, len) > 0)
        {
            printf("%s", line);
        }
    }
    return 0;
}

/* getLine:  read a line into s, return length  */
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

int strip(char line[], int len)
{
    int s;
    int end = 0;
    int j = len - 2;

    while (j >= 0 && end == 0)
    {
        s = line[j];

        if (s == ' ' || s == '\t')
        {
            --j;
        }
        else
        {
            end = 1;
        }
    }

    // clear blank and tabs
    line[j + 1] = '\n';
}