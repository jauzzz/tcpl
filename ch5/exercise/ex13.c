/*  Exercise 5-13. 
    Write the program tail, which prints the last n lines of its input. 
    By default, n is set to 10, let us say, but it can be changed by an optional argument so that
        tail -n
    prints the last n lines. 
    The program should behave rationally no matter how unreasonable the input or the value of n. 
    Write the program so it makes the best use of available storage; 
    lines should be stored as in the sorting program of Section 5.6, n
    ot in a two-dimensional array of fixed size.

    编写程序 tail，将其输入中的最后 n 行打印出来。
    默认情况下，n 的值为 10，但可通过一个可选参数改变 n 的值，
    因此，命令
        tail -n
    将打印其输入的最后 n 行。
    无论输入或 n 的值是否合理，该程序都应该能正常运行。
    编写的程序要充分地利用存储空间;
    输入行的存储方式应该同 5.6 节中排序程序的存储方式一样，而不采用固定长度的二维数组。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
#define LINENUMS 10
#define MAXLEN 1000

char *lineptr[MAXLINES]; /* pointers to text lines */

int getLine(char line[], int maxline);
char *alloc(int);

/* getLine:  read a line into s, return length  */
int getLine(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *s++ = c;
    if (c == '\n')
    {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void taillines(char *lineptr[], int nlines, int linenum)
{
    int i, index;

    if (nlines < linenum)
        linenum = nlines;

    for (i = 0, index = linenum; i < linenum; i++)
        printf("%s\n", lineptr[--index]);
}

/* tail: print the last n lines of its input */
// tail -n10
int main(int argc, char *argv[])
{
    int nlines;
    int c, linenum, flag = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c)
            {
            case 'n':
                flag = 1;
                break;
            default:
                if (isdigit(c))
                {
                    linenum = linenum * 10 + ((flag == 1) ? (c - 48) : LINENUMS);
                }
                else
                {
                    argc = 0;
                    printf("tail: illegal option %c\n", c);
                }

                break;
            }

    printf("argc: %d\n", argc);
    if (argc != 1)
        printf("Usage: tail -n number\n");

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        taillines(lineptr, nlines, linenum);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }

    return 0;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        /* it fits and then return old p */
        allocp += n;
        return allocp - n;
    }
    else
        /* not enough room */
        return 0;
}