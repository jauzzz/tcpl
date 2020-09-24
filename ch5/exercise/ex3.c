/*  Exercise 5-3. 
    Write a pointer version of the function strcat that we showed in Chapter 2:
    strcat(s,t) copies the string t to the end of s.

    用指针方式实现第 2 章中的函数 strcat。
    函数 strcat(s, t)将 t 指向的字符串复制到 s 指向的字符串的尾部。
*/

#include <stdio.h>

void strcat(char *s, char *t)
{
    while (*++s)
        ;

    while ((*s++ = *t++))
        ;
}

int main(void)
{
    char s1[8192] = "123";
    char s2[8192] = "456";

    printf("s1: (%s)\n", s1);
    printf("s2: (%s)\n", s2);

    strcat(s1, s2);
    printf("result: (%s)\n", s1);

    return 0;
}