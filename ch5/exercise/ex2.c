/*  Exercise 5-2. 
    Write getfloat, the floating-point analog of getint. 
    What type does getfloat return as its function value?

    模仿函数 getint 的实现方法，编写一个读取浮点数的函数 getfloat。
    getfloat 函数的返回值应该是什么类型?
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

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
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(float *pn)
{
    int c, sign;
    int len = 0;
    int fraction = 0;

    /* skip white space and tabs */
    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        len++;
    }

    if (c == '.')
    {
        c = getch();
        for (; isdigit(c); c = getch())
        {
            *pn = 10.0 * *pn + (c - '0');
            len++;
            fraction++;
        }
        *pn /= pow(10, fraction);
    }

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return len;
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

int main(void)
{
    int ret;

    do
    {
        float f;

        fputs("Enter a number: ", stdout);
        fflush(stdout);
        ret = getfloat(&f);
        if (ret > 0)
        {
            printf("You entered: %f\n", f);
        }
    } while (ret > 0);

    if (ret == EOF)
    {
        puts("Stopped by EOF.");
    }
    else
    {
        puts("Stopped by bad input.");
    }

    return 0;
}