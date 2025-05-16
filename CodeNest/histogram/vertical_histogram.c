#include <stdio.h>
#include <stdlib.h>

#define WORD_LIMIT 100

typedef enum state_t { IN, OUT } state_t;

int maxValue(int arr[], int size);
void drawVerticalHistogram(int arr[], int size, int maxValue);

int main() {
    int word[WORD_LIMIT] = {0};
    int c, index = 0;
    state_t state = OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (state == OUT)
                state = IN;
            word[index]++;
        } else if (index < WORD_LIMIT) {
            if (state == IN) {
                state = OUT;
                index++;
            } else if (state == OUT)
                continue;
        } else {
            fprintf(stderr, "Word limit Exceed\n");
            exit(1);
        }
    }
    drawVerticalHistogram(word, index + 1, maxValue(word, index + 1));
    return 0;
}

int maxValue(int arr[], int size) {
    int local_max = 0;
    for (int i = 0; i < size; ++i) {
        if (local_max < arr[i]) {
            local_max = arr[i];
        }
    }
    return local_max;
}
void drawVerticalHistogram(int arr[], int size, int maxValue) {
    for (int i = 0; i < maxValue; ++i) {
        for (int j = 0; j < size; ++j) {
            if (maxValue - i <= arr[j])
                printf("  █ ");
            else
                printf("    ");
        }
        putchar('\n');
    }
    for (int i = 0; i < size - 1; ++i)
        printf("----");
    putchar('\n');

    for (int i = 0; i < size - 1; ++i)
        printf("%3d ", arr[i]);
    putchar('\n');
}
