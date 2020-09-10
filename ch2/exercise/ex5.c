/*  Exercise 2-5. 
    Write the function any(s1,s2), which returns the first location in a string s1 
    where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
    (The standard library function strpbrk does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

/* find:  find the first c location from s */
int find(char s[], int c)
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return i;
    return -1;
}

/* find2: find the first location in a string s1 
    where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. */

int find2(char s1[], char s2[])
{
    int i, c;
    for (i = 0; (c = s2[i]) != '\0'; i++)
    {
        if ((i = find(s1, c)) != -1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int i;
    char s1[] = "abcdefghijklmnopqrstabcdefghijklmnopqrst";
    char s2[] = "jnq";
    i = find2(s1, s2);
    printf("result is %d", i);

    return 0;
}