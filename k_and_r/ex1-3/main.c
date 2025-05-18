/*
Modify the temperature conversion program to print a heading above the table.
Formula:
Fahrenheit = ( Celsius x 9/5 ) + 32
Celsius = ( Fahrenheit x 5/9) +
*/

#include <stdio.h>

/* print Fahrenheit-Celsius table
        for fahr = 0, 20, ..., 300; floating-point conversion */

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0; // lower limit of temperature scale
    upper = 300; // upper limit
    step = 20; // step size

    fahr = lower;
    printf("Fahrenheit\tCelcius\n");
    while( fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%8.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
