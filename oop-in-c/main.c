#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array {
        /*
         * Pointer to 'self'
         * In other languages, called 'this'
         */
        struct array *self;

        /*
         * Actual 'member variables'
         */
        int *data;
        size_t size;

        /*
         * 'member functions' or 'methods' that we implement from scratch
         */
        void (*pfnSet)(struct array *, size_t, int);
        int (*pfnGet)(struct array *, size_t);
} array_t;

// Retrieve data
int Get_array_t(array_t *self, size_t index) { return self->data[index]; }

void Set_array_t(array_t *self, size_t index, int value) {
    if (self == NULL)
        return;
    if (index >= 0 && index < self->size) {
        self->data[index] = value;
    }
}

/*
 * Array Constructor
 * Sometimes abbreviated 'ctor'
 */
array_t *init_array(size_t capacity) {
    array_t *newArray = (array_t *)malloc(sizeof(array_t));
    if (newArray == NULL)
        return NULL;
    // Store the pointer back to the memory that holds our actual objects
    newArray->self = newArray;
    newArray->data = (int *)malloc(sizeof(int) * capacity);
    if (newArray->data == NULL) {
        free(newArray);
        return NULL;
    }
    newArray->size = capacity;

    // Set up the function pointers
    newArray->pfnGet = Get_array_t;
    newArray->pfnSet = Set_array_t;

    return newArray;
}

/*
 * Array Destructor
 * Sometimes abbreviated 'dtor'
 */
void destroy_array(array_t *self) {
    free(self->data);
    free(self);
}

int main() {
    array_t *test = init_array(10);

    // Set all of the varialbles
    for (int i = 0; i < test->size; ++i) {
        test->pfnSet(test->self, i, i);
    }
    // Retrieve all the values
    for (int i = 0; i < test->size; ++i) {
        printf("%d ", test->pfnGet(test->self, i));
    }
    printf("\n");
    destroy_array(test);
    return 0;
}
