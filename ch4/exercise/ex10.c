/*  Exercise 4-10. 
    An alternate organization uses getLine to read an entire input line; 
    this makes getch and ungetch unnecessary. 
    Revise the calculator to use this approach.

    另一种方法是通过 getLine 函数读入整个输入行，
    这种情况下可以不使用 getch 与 ungetch 函数。
    请运用这一方法修改计算器程序。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXLINE 1000

int getop(char[]);
void push(double);
double pop(void);
int getLine(char[], int);

char line[MAXLINE];
int lindex;

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while (getLine(line, MAXLINE) != 0)
    {
        lindex = 0;
        while ((type = getop(s)) != '\0')
        {
            switch (type)
            {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command \'%s\'\n", s);
                break;
            }
        }
    }

    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");

    return 0.0;
}

/* getLine:  get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

#include <ctype.h>

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = line[lindex++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = line[lindex++]))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = line[lindex++]))
            ;
    s[i] = '\0';
    lindex--;

    return NUMBER;
}
