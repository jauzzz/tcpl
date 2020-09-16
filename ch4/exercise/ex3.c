/*  Exercise 4-3. 
    Given the basic framework, it's straightforward to extend the calculator. 
    Add the modulus (%) operator and provisions for negative numbers.

    在有了基本框架后，对计算器程序进行扩充就比较简单了。
    在该程序中加入 取模(%)运算符，并注意考虑负数的情况
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double f);
double pop(void);

int main()
{

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            printf("number: %s\n", s);
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                // fmod: 对浮点数取余
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}

/* 每次调用，返回一个操作数或操作符 */
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int c, p;
    int i = 0;

    // 忽略空格和制表符
    while ((c = getch()) == ' ' || c == '\t')
        ;

    // 符号
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    // - 符号（负数还是负号）
    if (c == '-')
    {
        p = c;
        c = getch();
        // 是负数
        if (isdigit(c))
        {
            s[i++] = p;
            s[i++] = c;
            while (isdigit(c = getch()))
                s[i++] = c;
            if (c == '.')
                while (isdigit(c = getch()))
                    s[i++] = c;
        }
        // 是负号
        else
        {
            // 将预先读取的字符存储在缓冲区
            if (c != EOF)
                ungetch(c);

            return p;
        }
    }

    // 数字
    if (isdigit(c))
    {
        s[i++] = c;
        while (isdigit(c = getch()))
            s[i++] = c;
    }

    if (c == '.')
        while (isdigit(c = getch()))
            s[i++] = c;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* 缓冲区 */
#define BUFSIZE 100
char buffer[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[bufp++] = c;
}

/* 栈区域和栈操作 */
#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}