/*
Experiment to find out what happens when `prints` argument string contains \c, where c is some
character not listed above.
*/
#include <stdio.h>
int main() {
    printf("hello world\c");
    return 0;
}
