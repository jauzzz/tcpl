/*  Exercise 1.15. 
    Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

#include <stdio.h>

/*  print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

float f2c(float fahr)
{
    float celsius;

    celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}

int main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%3d %6.1f\n", fahr, f2c(fahr));
    }
}