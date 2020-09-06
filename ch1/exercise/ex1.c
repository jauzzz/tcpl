/*  Exercise 1-1.
    Run the ``hello, world'' program on your system.
    Experiment with leaving out parts of the program, to see what error messages you get.
*/

#include <stdio.h>

main()
{
    printf("hello, world\n");
}

/*
    remove header: 【Error】include the header <stdio.h> or explicitly provide a declaration for 'printf'
    remove type int for main: 【Error】type specifier missing, defaults to 'int'
    remove (): 【Error】variable named 'main' with external linkage has undefined behavior
    remove {}: 【Error】expected function body after function declarator
    remove ": 【Error】missing terminating '"' character
    remove ;: 【Error】expected ';' after expression
 */