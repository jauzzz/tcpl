/*  Exercise 5-10. 
    Write the program expr, which evaluates a reverse Polish expression from the command line, 
    where each operator or operand is a separate argument. 
    For example,
        expr 2 3 4 + *
    evaluates 2 * (3+4).

    编写程序 expr，以计算从命令行输入的逆波兰表达式的值，
    其中每个运算符或操作数用一个单独的参数表示。
    例如，命令 
        expr 2 3 4 + *
    将计算表达式 2 × (3 + 4)的值
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define INVALID -1

int getop(char[], char *);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while (--argc > 0)
    {
        type = getop(s, *++argv);
        switch (type)
        {
        case INVALID:
            printf("error: invalid number\n");
            break;
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
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    // means end
    printf("%.8g\n", pop());

    return 0;
}

int getop(char s[], char *arg)
{
    int i, c;

    if (!isdigit(s[0] = c = *arg) && c != '.')
    {
        s[1] = '\0';
        return c;
    }

    i = 0;
    /* collect integer part */
    if (isdigit(c))
        while (isdigit(s[i++] = c = *arg++))
            ;

    /* collect fraction part */
    if (c == '.')
        while (isdigit(s[i++] = c = *arg++))
            ;

    // non-number check
    if (c != '\0' && !isdigit(c))
    {
        // printf("error: invalid number\n");
        return INVALID;
    }

    s[i] = '\0';
    return NUMBER;
}

/* 定义栈及栈操作 */
#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    // printf("f: %f\n", f);
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