#include "linklist.h"
#include "insertion.h"
#include "reverse.h"
#include <stdio.h>


int main() {
    printf("Enter how many list do you want to create: ");
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; ++i) {
        printf("Enter the %d%s number: ", i+1, (i == 0)?"st":(i == 1)?"nd":(i == 2)?"rd":"th");
        int helper;
        scanf("%d", &helper);
        insertAtEnd(helper);
    }
    displayList();
    reverse();
    displayList();
    return 0;
}
