/*  Exercise 4-6. 
    Add commands for handling variables. 
    (It's easy to provide twenty-six variables with single-letter names.) 
    Add a variable for the most recently printed value.

    给计算器程序增加处理变量的命令(提供 26 个具有单个英文字母变量名的变量很容易)。
    增加一个变量存放最近打印的值。
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC '1'
#define VAR '2'

int getop(char[]);
void push(double f);
double pop(void);
void func(char s[]);

int var;
double v;

int main()
{

    int i, type;
    double op2;
    char s[MAXOP];
    double variable[26];

    // 初始化变量
    for (i = 0; i < 26; i++)
        variable[i] = 0.0;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            printf("number: %s\n", s);
            push(atof(s));
            break;
        case FUNC:
            func(s);
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
        case VAR:
            if (var >= 'A' && var <= 'Z')
                push(variable[var - 'A']);
            else if (var == 'v')
                push(v);
            else
                printf("error: variable symbol out of range\n");
            break;
        case '=':
            if (var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("error: variable symbol out of range\n");
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
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

    // 函数或变量
    if (isalpha(c))
    {
        p = c;
        s[i++] = c;
        while (isalpha(c = getch()))
            s[i++] = c;

        s[i] = '\0';
        if (c != EOF)
            ungetch(c);

        // 单个长度的为变量，否则是函数
        if (i == 1)
        {
            var = p;
            return VAR;
        }
        else
            return FUNC;
    }

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
            {
                s[i++] = c;
                while (isdigit(c = getch()))
                    s[i++] = c;
            }
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
    {
        s[i++] = c;
        while (isdigit(c = getch()))
            s[i++] = c;
    }

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

/* 数学库 */
void func(char s[])
{
    double op2, res;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: %s not supported\n", s);
}