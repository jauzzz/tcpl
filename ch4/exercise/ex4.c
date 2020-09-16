/*  Exercise 4-4. 
    Add the commands to print the top elements of the stack without popping, 
    to duplicate it, and to swap the top two elements. 
    Add a command to clear the stack.

    在栈操作中添加几个命令，分别用于
        - 在不弹出元素的情况下打印栈顶元素
        - 复制栈顶元素
        - 交换栈顶两个元素的值
        - 另外增加一个命令用于清空栈
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

void showtop(void);
double copytop(void);
void swaptop(void);
void clear(void);

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
    double top;

    printf("------\n");
    showtop();
    // top = copytop();
    // printf("copy top: %g\n", top);

    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* showtop: 打印栈顶元素 */
void showtop(void)
{
    printf("top: stack[%d] = %g\n", sp - 1, val[sp - 1]);
}

/* copytop: 复制栈顶元素 */
double copytop(void)
{
    double s = pop();
    push(s);
    push(s);
}

/* swaptop: 交换栈顶两个元素的值 */
void swaptop(void)
{
    double s1, s2;
    s1 = pop();
    s2 = pop();
    push(s1);
    push(s2);
}

void clear(void)
{
    sp = 0;
}