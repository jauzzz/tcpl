/*  Exercise 1-14. 
    Write a program to print a histogram of the frequencies of different characters in its input. */

#include <stdio.h>

int main()
{
    int freq[94];
    int heigth;
    int c, i, k;

    heigth = 0;

    for (i = 0; i <= 93; ++i)
        freq[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (33 <= c && c <= 126)
        {
            ++freq[c - 33];
            if (freq[c - 33] >= heigth)
                heigth = freq[c - 33];
        }
    }

    for (i = heigth; i > 0; --i)
    {
        printf("%4d|", i);
        for (k = 0; k <= 93; ++k)
        {
            if (freq[k] >= i)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("    +");
    for (i = 0; i <= 93; ++i)
        printf("-");
    printf("\n     ");

    for (i = 0; i <= 93; ++i)
    {
        printf("%c", i + 33);
    }
    printf("\n");

    return 0;
}
