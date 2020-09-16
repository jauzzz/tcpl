/*  Exercise 4-8. 
    Suppose that there will never be more than one character of pushback. 
    Modify getch and ungetch accordingly.

    假定最多只压回一个字符，请相应地修改 getch 与 ungetch 这两个函数
*/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 1
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
    char *s = "he";
    int c;

    ungets(s);
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}