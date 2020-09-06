/*  Exercise 1-13. 
    Write a program to print a histogram of the lengths of words in its input. 
    It is easy to draw the histogram with the bars horizontal; 
    a vertical orientation is more challenging. */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLENGTH 10

int main()
{
    int c, i, j, max;
    int ndigit[MAXLENGTH + 1];

    int wc = 0;
    int state = OUT;
    for (i = 0; i <= MAXLENGTH; ++i)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            if (wc > 0)
            {
                if (wc > MAXLENGTH)
                {
                    ++ndigit[MAXLENGTH];
                }
                else
                {
                    ++ndigit[wc];
                }
            }
            wc = 0;
        }
        else
        {
            state = IN;
            wc++;
        }
    }

    // EOF
    if (wc > MAXLENGTH)
    {
        ++ndigit[MAXLENGTH];
    }
    else
    {
        ++ndigit[wc];
    }

    for (i = 1; i <= MAXLENGTH; ++i)
    {
        printf("| %d|", i);
        max = ndigit[i];

        for (j = 0; j < max; ++j)
        {
            printf("*");
        }

        printf("\n");
    }
}