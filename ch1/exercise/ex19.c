/*  Exercise 1-19. 
    Write a function reverse(s) that reverses the character string s. 
    Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getLine(char line[], int maxline);
int reverse(char line[], int length);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (reverse(line, len) > 0)
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

int reverse(char line[], int len)
{
    char ch;
    int i = 0;
    int j = len - 1;

    // blank line length is 1
    // printf("i: %d, j:%d \n", i, j);
    while (j > 1 && i < j)
    {
        ch = line[i];
        line[i] = line[j - 1];
        line[j - 1] = ch;
        ++i;
        --j;
    }

    line[len - 1] = '\n';

    return len;
}