/*  Exercise 1-2. 
    Experiment to find out what happens when prints's argument string contains \c, 
    where c is some character not listed above.
*/

#include <stdio.h>

main()
{
    printf("hello, ");
    printf("world");
    printf("\n");
}

// ex2.c:12:18: warning: unknown escape sequence '\h' [-Wunknown-escape-sequence]