/*  Exercise 5-8. 
    There is no error checking in day_of_year or month_day. 
    Remedy this defect.

    函数 day_of_year 和 month_day 中没有进行错误检查，请解决该问题
*/

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month < 1 || month > 12)
        return -1;
    if (day > daytab[leap][month])
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year < 1)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
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