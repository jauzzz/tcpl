/*  Exercise 4-9. 
    Our getch and ungetch do not handle a pushed-back EOF correctly. 
    Decide what their properties ought to be if an EOF is pushed back, then implement your design.

    以上介绍的getch与ungetch函数不能正确地处理压回的EOF。
    考虑压回 EOF 时应该如何处理?
    请实现你的设计方案。
*/

#include <stdio.h>
#define BUFSIZE 100

/* 
    主要的改动在于: char buf[BUFSIZE] --> int buf[BUFSIZE]
    将缓冲区里面的元素当做 int 类型对待;

    原先是 char 类型，EOF = -1，会被进行转化：
    ===================================
    负数(-1)        字符         整数
    0xFFFF         0xFF        0x00FF(255)
    0xFFFF         0xFF        0xFFFF(-1)
    ===================================
    所以，如果将里面的元素，定义为 int 类型，就不需要进行转化了

*/
int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error: stack is full, can't execute ungetch()\n");
    else
        buf[bufp++] = c;
}