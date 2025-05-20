/*
Modify the temperature conversion program to print the table in reverse order,
that is, from 300 to 0
*/

#include <stdio.h>
#define LOW 0
#define UPPER 300
#define STEP 20

int main() {
    float fahr1, cel1, fahr2, cel2;
    printf("Fahrenheit\tCelsius\n");
    for(fahr1 = UPPER; fahr1 >= LOW; fahr1 -= STEP) {
        cel1 = (5.0/9.0) * (fahr1 - 32);
        printf("%8.0f\t%6.1f\n", fahr1, cel1);
    }
    printf("Celsius\tFahrenheit\n");
    for(cel2 = UPPER; cel2 >= LOW; cel2 -= STEP) {
        fahr2 = (9.0/5.0) * cel2 + 32;
        printf("%5.0f\t%5.0f\n", cel2, fahr2);
    }
    return 0;
}
