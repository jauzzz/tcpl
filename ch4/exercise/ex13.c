/*  Exercise 4-13. 
    Write a recursive version of the function reverse(s), which reverses the string s in place.

    编写一个递归版本的reverse(s)函数，以将字符串s倒置
*/

#include <stdio.h>
#include <string.h>

/* reverse:  reverse string s in place */
void reverse(char s[], int i, int j)
{
    static int c;

    if (i < j)
        reverse2(s, ++i, --j);
    else
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    char s[256] = "abc";
    int i = 0;
    int j = strlen(s) - 1;

    reverse(s, i, j);

    printf("s: %s\n", s);
    return 0;
}