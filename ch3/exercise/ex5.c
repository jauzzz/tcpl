/*  Exercise 3-5. 
    Write the function itob(n,s,b) that 
    converts the integer n into a base b character representation in the string s. 
    In particular, itob(n,s,16) formats s as a hexadecimal integer in s.

    编写函数 itob(n, s, b) ,用于把整数 n 转换成以 b 为基数的字符串并存到字符串 s 中。
    例如，itob(n, s, 16) 表示将 n 转换成 16 进制数，并存入 s 中。
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

void itob(int n, int b, char s[])
{
    int i, sign;
    sign = n;
    i = 0;

    do
    {                                                     /* generate digits in reverse order */
        s[i++] = ((sign < 0) ? -(n % b) : n % b) + '0'; /*getnextdigit*/
    } while ((n /= b) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n1 = 144;
    int n2 = -2147483648;
    int b = 16;

    // int n = -39;
    char s1[100];
    char s2[100];

    itob(n1, b, s1);
    printf("s1: %s\n", s1);

    itob(n2, b, s2);
    printf("s2: %s\n", s2);

    return 0;
}
