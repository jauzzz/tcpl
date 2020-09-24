/*  Exercise 5-5. 
    Write versions of the library functions strncpy, strncat, and strncmp, 
    which operate on at most the first n characters of their argument strings. 
    For example, strncpy(s,t,n) copies at most n characters of t to s. 
    Full descriptions are in Appendix B.

    实现库函数 strncpy、strncat 和 strncmp，它们最多对参数字符串中的前 n 个字符进行操作。
    例如，函数 strncpy(s, t, n)将 t 中最多前 n 个字符复制到 s 中。更详细的说明请参见附录 B。
*/

#include <stdio.h>

/* strncpy: copy at most n characters of t to s */
void strncpy(char *s, char *t, int n)
{
    int x = 0;
    while ((++x <= n) && (*s++ = *t++))
        ;
}

void strncat(char *s, char *t, int n)
{
    int x = 0;
    while (*++s)
        ;

    while ((++x <= n) && (*s++ = *t++))
        ;
}

int strncmp(char *s, char *t, int n)
{
    int x = 0;
    for (; *s == *t; s++, t++, x++)
        if (*s == '\0')
            return 0;

    if (x == n)
        return 0;
    else
        return x - n;
}

int main()
{
    int flag1, flag2;
    char s1[100] = "abcdefghijklmnopqrstuvwxyz";
    char s2[10] = "0123456789";
    char s3[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char s4[100] = "01234567ijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQ";

    printf("\n");
    printf("-------- strncpy test --------\n");
    strncpy(s1, s2, 8);
    printf("result: %s\n", s1);
    printf("\n");

    printf("-------- strncat test --------\n");
    strncat(s1, s3, 17);
    printf("result: %s\n", s1);
    printf("\n");

    printf("-------- strncmp test1 --------\n");
    flag1 = strncmp(s1, s2, 3);
    printf("result: %d\n", flag1);
    printf("\n");

    printf("-------- strncmp test2 --------\n");
    flag2 = strncmp(s1, s4, 27);
    printf("result: %d\n", flag2);
    printf("\n");
}