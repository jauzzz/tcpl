/*  Exercise 4-12. 
    Adapt the ideas of printd to write a recursive version of itoa; 
    that is, convert an integer into a string by calling a recursive routine.

    运用printd函数的设计思想编写一个递归版本的itoa函数，即通过递归调用把整数转换为字符串
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
    static int i;

    if (n / 10 != 0)
        itoa2(n / 10, s);
    else
    {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }

    s[i++] = ((n < 0) ? -(n % 10) : n % 10) + '0';
}

int main()
{
    int n = -2147483648;
    // int n = -123;
    char s[100];

    itoa(n, s);
    printf("s: %s\n", s);

    return 0;
}
