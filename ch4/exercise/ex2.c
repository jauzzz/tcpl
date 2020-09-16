/*  Exercise 4-2. 
    Extend atof to handle scientific notation of the form 123.45e-6
    where a floating-point number may be followed by e or E and an optionally signed exponent.
*/

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* atof:  convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, exp, sign2;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign2 = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }

        for (exp = 0; isdigit(s[i]); i++)
        {
            exp = exp * 10 + (s[i] - '0');
        }

        if (sign2 == 1)
        {
            while (exp > 0)
            {
                exp--;
                val *= 10.0;
            }
        }

        if (sign2 == -1)
        {
            while (exp > 0)
            {
                exp--;
                val /= 10.0;
            }
        }
    }

    return sign * val / power;
}

/* atoi:  convert string s to integer using atof */
int atoi(char s[])
{
    double atof(char s[]);
    return (int)atof(s);
}

/* getline:  get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* rudimentary calculator */
main()
{
    double sum, atof(char[]);
    char line[MAXLINE];
    int getLine(char line[], int max);

    sum = 0;
    while (getLine(line, MAXLINE) > 0)
        printf("%g\n", sum += atof(line));

    return 0;
}