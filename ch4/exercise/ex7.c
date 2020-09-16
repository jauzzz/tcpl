/*  Exercise 4-7. 
    Write a routine ungets(s) that will push back an entire string onto the input.
    Should ungets know about buf and bufp, or should it just use ungetch?

    编写一个函数 ungets(s)，将整个字符串 s 压回到输入中。
    ungets 函数 需要使用 buf 和 bufp 吗?
    它能否仅使用 ungetch 函数?
*/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int len;

    len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

int main(void)
{
    char *s = "hello, world! ";
    int c;

    ungets(s);
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}