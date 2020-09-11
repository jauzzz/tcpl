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

int main()
{
    int n = -2147483648;
    // int n = -39;
    char s[100];

    itoa(n, s);
    printf("s: %s", s);

    return 0;
}