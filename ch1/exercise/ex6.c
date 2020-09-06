/* Exercsise 1-6. 
    Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main()
{
    int c;
    int value;
    while ((c = getchar()) != EOF)
    {
        printf("the expression getchar() != EOF is %d\n", c != EOF);
        putchar(c);
    }
}