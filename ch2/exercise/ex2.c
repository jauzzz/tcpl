/*  Exercise 2-2. 
    Write a loop equivalent to the for loop above without using && or ||.
*/

#include <stdio.h>

#define lim 1000

int main()
{
    int i, c;
    char s[lim];

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        s[i] = c;
    }

    return 0;
}

// rewrite without using && or ||
int main()
{
    int i, c;
    char s[lim];

    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
            }
        }
    }

    return 0;
}