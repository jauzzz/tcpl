/*  Exercise 5-6. 
    Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. 
    Good possibilities include getline (Chapters 1 and 4), atoi, itoa, 
    and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).

    采用指针而非数组索引方式改写前面章节和练习中的某些程序，
    例如:
        - getline(第 1、4 章)
        - atoi、itoa 以及它们的变体形式(第 2、3、4 章)
        - reverse(第 3 章)
        - strindex
        - getop(第 4 章) 等等。
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define NUMBER '0' /* signal that a number was found */
int getLine(char line[], int maxline);

/* getline:  read a line into s, return length  */
int getLine(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *s++ = c;
    if (c == '\n')
    {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

/* atoi:  convert s to integer */
int atoi(char *s)
{
    int i, n;
    n = 0;
    for (i = 0; *s >= '0' && *s <= '9'; ++i)
        n = 10 * n + (*s++ - '0');
    return n;
}

/* reverse:  reverse string s in place */
void reverse(char *s)
{
    int c;
    char *t;

    for (t = s + strlen(s) - 1; s < t; s++, t--)
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char *s)
{
    int i, sign;
    char *t = s;

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */

    i = 0;
    do
    {                        /* generate digits in reverse order */
        *s++ = n % 10 + '0'; /*getnextdigit*/
    } while ((n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';

    *s = '\0';
    reverse(t);
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    int i;
    char *j, *k;
    for (i = 0; *s != '\0'; s++, i++)
    {
        for (j = s, k = t; *k != '\0' && *j == *k; j++, k++)
            ;
        if (k > 0 && *k == '\0')
            return i;
    }
    return -1;
}

int getop(char *s)
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) /* collect integer part */
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(*++s = c = getch()))
            ;

    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int main()
{

    printf("\n");
    printf("-------- getLine test --------\n");
    printf("please enter your line:");
    int len;
    char line[MAXLINE];
    len = getLine(line, MAXLINE);
    printf("line: %s\n", line);

    printf("-------- atoi test --------\n");
    int num;
    char nums[100] = "137213987";
    num = atoi(nums);
    printf("num: %d\n", num);

    printf("-------- itoa test --------\n");
    int num1 = -1234567890;
    char nums1[100] = "";
    itoa(num1, nums1);
    printf("num1: %s\n", nums1);

    printf("-------- strindex test --------\n");
    int index;
    char strings[] = "chabdouldqwe";
    char pattern[] = "ould";
    index = strindex(strings, pattern);
    printf("index: %d\n", index);

    return 0;
}