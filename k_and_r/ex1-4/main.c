/*
Write a program to print the corresponding Celsius to Fahrenheit table.
Formula: F = (C x 9/5) + 32
Formula: C = (F - 32) x 5/9
*/

#include <stdio.h>
int main() {
    float lower = 0, upper = 300, step = 20;
    float fahr, celsius;

    celsius = lower;
    printf("Celsius\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = ((celsius * (9.0 / 5.0))) + 32;
        printf("%5.0f\t%3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
