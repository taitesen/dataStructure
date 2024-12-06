#include "../include/lib.h"

int main() {
    Queue *my_queue = initQ();
    Enque(my_queue, 10);
    Enque(my_queue, 20);
    Enque(my_queue, 30);
    Deque(my_queue);
    Deque(my_queue);
    Enque(my_queue, 40);
    Enque(my_queue, 50);
    Enque(my_queue, 60);
    Front(my_queue);
    return 0;
}
