/*
 * Exercise 1-23
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest.
 * 
 * 写一个删除 C 语言程序中所有的注释语句。
 * 要正确处理带引号的字符串与字符常量。在 C 语言中，注释不允许嵌套
 */

#include <stdio.h>

int main()
{
    int c;
    int init = 1;    // 是否第一个字符
    int current = 0; // 前一个字符
    int former = 0;  // 注释标记，0表示无标记，1=/, 2=*
    int status = 0;  // 标记状态，0表示无标记，1表示在标记状态中
    int comment = 0; // 注释状态，0未注释，1注释中
    int type = 0;    // 注释类型，0表示无注释，1表示//，2表示 /*

    while ((c = getchar()) != EOF)
    {
        // 使用 former 记录上一个的字符的值
        if (init == 0)
        {
            former = current;
            current = c;
        }
        if (init == 1)
        {
            current = c;
            init = 0;
        }

        // printf("former: %c, ch: %c\n", former, c);
        // 注释状态的判定
        if (c == '/')
        {
            if (former == '/')
            {
                comment = 1;
            }
            else if (former == '*')
            {
                comment = 0;
            }
            else
            {
                status = 1;
            }
        }

        else if (c == '*')
        {
            if (former == '/')
            {
                comment = 1;
                type = 2;
            }
            else
            {
                status = 1;
            }
        }

        else if (c == '\n')
        {
            if (comment == 1 && type == 1)
            {
                status = 0;
                comment = 0;
                type = 0;
            }
            if (comment == 0 && type == 2)
            {
                status = 0;
                type = 0;
            }
        }

        else
        {
            if (comment == 0 && status == 1 && (former == '/' || former == '*'))
            {
                putchar(former);
                status = 0;
                comment = 0;
            }
        }

        // 主流程
        if (comment == 0 && status == 0)
        {
            putchar(c);
        }
    }

    return 0;
}