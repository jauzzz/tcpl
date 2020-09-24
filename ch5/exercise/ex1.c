/*  Exercise 5-1. 
    As written, getint treats a + or - not followed by a digit as a valid representation of zero. 
    Fix it to push such a character back on the input.

    在上面的例子中，如果符号+或-的后面紧跟的不是数字，getint函数将把符号视为数字 0 的有效表达方式。
    修改该函数，将这种形式的+或-符号重新写回到输入流中。
*/

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /*skip white space*/
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c))
        {
            ungetch(sign);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/* getch ungetch */
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*push character back on input*/
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}