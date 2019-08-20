/*  Exercise 1-4. 
    Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

int main()
{
    float lower, upper, step;
    float fahr, celsius;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (celsius + 32) * 9 / 5;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}