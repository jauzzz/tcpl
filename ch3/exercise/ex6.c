/*  Exercise 3-6. 
    Write a version of itoa that accepts three arguments instead of two. 
    The third argument is a minimum field width; 
    the converted number must be padded with blanks on the left if necessary to make it wide enough.

    修改 itoa 函数，使得该函数可以接收三个参数。
    第三个参数为最小字段宽度。
    为了保证转换后结果至少具有第三个参数指定的最小宽度，必要时在结果左边填充一定的空格。
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

void itoa(int n, int w, char s[])
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

    while (i < w)
    {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n1 = 37;
    int n2 = -2147483648;
    char s1[100];
    char s2[100];
    int w1 = 3;
    int w2 = 20;

    itoa(n1, w1, s1);
    printf("s1:%s\n", s1);

    itoa(n2, w2, s2);
    printf("s2:%s\n", s2);

    return 0;
}
