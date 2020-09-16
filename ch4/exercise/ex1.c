/*  Exercise 4-1. 
    Write the function strindex(s,t) which returns 
    the position of the rightmost occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main()
{
    int index;
    char s[MAXLINE] = "abcdefgwwqefllj";
    char t[MAXLINE] = "ef";

    index = strindex(s, t);
    printf("strindex: %d", index);
}

/* strlen:  return length of s */
int strlen2(char s[])
{
    int i;
    while (s[i] != '\0')
        ++i;
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k, index;
    int len1, len2;

    len2 = strlen2(t);
    len1 = strlen2(s);
    index = len1 - len2;

    i = (index != 0) ? index : 0;
    for (; i >= 0; i--)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}