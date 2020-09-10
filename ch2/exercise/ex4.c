/*  Exercise 2-4. 
    Write an alternative version of squeeze(s1,s2) that deletes 
    each character in s1 that matches any character in the string s2.
*/

#include <stdio.h>

/* squeeze:  delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze: deletes each character in s1 that matches any character in the string s2 */
void squeeze2(char s1[], char s2[])
{
    int i, c;
    for (i = 0; (c = s2[i]) != '\0'; i++)
    {
        squeeze(s1, c);
    }
}

int main()
{
    char s1[] = "abcdefghijklmnopqrstabcdefghijklmnopqrst";
    char s2[] = "auio";
    squeeze2(s1, s2);
    printf("result is %s", s1);

    return 0;
}