/*  Exercise 3-3. 
    Write a function expand(s1,s2) that 
    expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. 
    Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
    Arrange that a leading or trailing - is taken literally.
*/

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[])
{
    int i, j, c, n, t, delta;
    i = j = 0;

    while ((c = s1[i++]) != '\0')
    {
        if (s1[i] == '-')
        {
            n = s1[i + 1];
            if (isalpha(c) && isalpha(n))
            {
                if (islower(c) && isupper(n))
                {
                    n = n + 32;
                }
                if (isupper(c) && islower(n))
                {
                    n = n - 32;
                }

                delta = n - c;
            }
            else if (isdigit(c) && isdigit(n))
            {
                delta = n - c;
            }
            else
            {
                s2[j++] = c;
            }

            // 符合条件，进行转换
            for (t = 0; delta > 0; delta--)
            {
                s2[j++] = c + t;
                t++;
            }
            if (t != 0)
            {
                i++;
                t = 0;
            }
        }
        else
        {
            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}

int main()
{
    char s1[512] = "-a-d-0-9";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}