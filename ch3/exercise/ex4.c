/*  Exercise 3-4. 
    In a two's complement number representation, our version of itoa does not handle the largest negative number, 
    that is, the value of n equal to -(2wordsize-1). 
    Explain why not. 
    Modify it to print that value correctly, regardless of the machine on which it runs.
*/

/*
    当 n 为 -(2wordsize-1) 时，即 n = 2147483648 时，n = -n 得到的是原来的数
*/

#include <stdio.h>
#include <string.h>

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */

    i = 0;
    printf("n: %d\n", n);
    do
    {                          /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /*getnextdigit*/
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void itoa2(int n, char s[])
{
    int i, sign;
    sign = n;
    i = 0;

    do
    {                                                     /* generate digits in reverse order */
        s[i++] = ((sign < 0) ? -(n % 10) : n % 10) + '0'; /*getnextdigit*/
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n1 = -2147483648;
    int n2 = -2147483648;
    // int n = -39;
    char s1[100];
    char s2[100];

    itoa(n1, s1);
    printf("s1: %s\n", s1);

    itoa2(n2, s2);
    printf("s2: %s\n", s2);

    return 0;
}
