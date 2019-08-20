/*  Read a character
        while (charater is not end-of-file indicator)
            output the character just read
            read a character
 */

#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}