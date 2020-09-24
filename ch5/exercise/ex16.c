/*  Exercise 5-16. 
    Add the -d (``directory order'') option, 
    which makes comparisons only on letters, numbers and blanks. 
    
    Make sure it works in conjunction with -f.

    增加选项-d(代表目录顺序)。
    该选项表明，只对字母、数字和空格进行比较。
    要保证该选项可以和-f 组合在一起使用。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int reverse, int (*comp)(void *, void *));
int reverseCmp(int a, int reverse);
int numcmp(char *, char *);
char toLower(char s);

int numeric = 0;
int reverse = 0;
int ignore = 0;
int isdir = 0;

int reverseCmp(int a, int revsere)
{
    if (revsere == 1)
        return a > 0;
    else
        return a < 0;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strCmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int strlowCmp(char *s, char *t)
{
    int s1, t1;
    for (; s1 = toLower(*s), t1 = toLower(*t), s1 == t1; s++, t++)
        if (*s == '\0')
            return 0;
    return s1 - t1;
}

int strlowdirCmp(char *s, char *t)
{
    char a, b;

    for (;;)
    {
        if (isdir)
        {
            do
            {
                a = *s++;
            } while (!isalnum(a) && !isspace(a) && a != '\0');

            do
            {
                b = *t++;
            } while (!isalnum(b) && !isspace(b) && b != '\0');
        }
        else
        {
            a = *s++;
            b = *t++;
        }

        if (ignore)
        {
            a = tolower(a);
            b = tolower(b);
        }

        if (a != b)
            break;
        else if (a == '\0')
            return 0;
    }

    return a - b;
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else
        return ch;
}

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int exit = 0;
    int c;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c)
            {
            case 'r':
                reverse = 1;
                break;
            case 'n':
                numeric = 1;
                break;
            case 'f':
                ignore = 1;
                break;
            case 'd':
                isdir = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                exit = 1;
                break;
            }

    if (exit == 1)
        return exit;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void **)lineptr, 0, nlines - 1, reverse,
              (int (*)(void *, void *))(numeric ? numcmp : strlowdirCmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int getLine(char *, int);
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int reverse, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);

    last = left;
    for (i = left + 1; i <= right; i++)
        if (reverseCmp((*comp)(v[i], v[left]), reverse))
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last - 1, reverse, comp);
    qsort(v, last + 1, right, reverse, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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