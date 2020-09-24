/*  Exercise 5-9. 
    Rewrite the routines day_of_year and month_day with pointers instead of indexing.

    用指针方式代替数组下标方式改写函数 day_of_year 和 month_day
*/

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    p = daytab[leap];
    while (--month)
        day += *++p;

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];

    while (yearday > *++p)
        yearday -= *p;

    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
}