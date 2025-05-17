/*
A program to print a hisotgram of the frequencies of different characters in its
input For simplicity, only alphabet and +ve numbers are allowed
*/

#include <ctype.h>
#include <stdio.h>

#define SIZE 256 // to accomodate all the ASCII characters

void drawHistogram(unsigned int *arr, int size) {
    unsigned int active_freq[SIZE] = {0};
    char active_char[SIZE] = {0};
    int active_index = 0;
    int max_value = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            active_freq[active_index] = arr[i];
            active_char[active_index] = i;
            if (max_value < arr[i]) {
                max_value = arr[i];
            }
            active_index++;
        }
    }

    if (max_value == 0 || active_index == 0) {
        printf("No relevant character to display\n");
        return;
    }

    for (int i = 0; i < max_value; ++i) {
        for (int j = 0; j < active_index; ++j) {
            if (max_value - i <= active_freq[j]) {
                printf("  █  ");
            } else {
                printf("     ");
            }
        }
        putchar('\n');
    }

    for (int i = 0; i < active_index; ++i) {
        printf("-----");
    }
    putchar('\n');

    for (int i = 0; i < active_index; ++i) {
        if (isprint(active_char[i]))
            printf("  %c  ", active_char[i]);
        else
            printf("  ?  ");
    }
    putchar('\n');

    for (int i = 0; i < active_index; ++i) {
        printf("%3d  ", active_freq[i]);
    }
    putchar('\n');
}

int main() {
    unsigned int freq[SIZE] = {0};
    int c;
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c <= 255)
            freq[c]++;
    }
    drawHistogram(freq, SIZE);
    return 0;
}
