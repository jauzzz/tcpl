/*  Exercise 5-4. 
    Write the function strend(s,t), which returns 1 
    if the string t occurs at the end of the string s, and zero otherwise.

    编写函数 strend(s, t)。
    如果字符串 t 出现在字符串 s 的尾部，该函数返回 1;否则返回 0。
*/

#include <stdio.h>

int strend(char *s, char t)
{
    while (*++s)
        ;

    if (*--s == t)
        return 1;
    else
        return 0;
}

int main(void)
{
    char s1[8192] = "123";
    char s2 = '2';
    char s3 = '3';
    char s4 = '4';

    int f2, f3, f4;

    f2 = strend(s1, s2);
    f3 = strend(s1, s3);
    f4 = strend(s1, s4);

    printf("f2: %d\n", f2);
    printf("f3: %d\n", f3);
    printf("f4: %d\n", f4);

    return 0;
}