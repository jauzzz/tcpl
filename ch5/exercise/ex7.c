/*  Exercise 5-7. 
    Rewrite readlines to store lines in an array supplied by main, 
    rather than calling alloc to maintain storage. 
    How much faster is the program?

    重写函数 readlines，将输入的文本行存储到由 main 函数提供的一个数组中，
    而不是存储到调用 alloc 分配的存储空间中。
    该函数的运行速度比改写前快多少?
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000   /* max length of any input line */
#define MAXSTORE 5000

char *lineptr[MAXLINES]; /* pointers to text lines */
char linestore[MAXLEN];

int readlines(char *lineptr[], char *linestore, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    if ((nlines = readlines(lineptr, linestore, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

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
int readlines(char *lineptr[], char *linestore, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestore;
    char *lineend = linestore + MAXSTORE;

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > lineend)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
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
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
