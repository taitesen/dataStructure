#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct HashNode {
        char *key;
        int value;
        struct HashNode *next;
} HashNode;

typedef struct HashMap {
        HashNode **bucket;
        int size;
        int capacity;
} HashMap;

unsigned int hash(const char *key, int capacity) {
    unsigned int hash_value = 0;

    // simple hash function
    while (*key != '\0') {
        hash_value = ((hash_value << 5) + hash_value) + *key;
        key++;
    }
    return hash_value % capacity;
}

HashMap *createHashMap(int capacity) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    if (!map)
        return NULL;

    map->size = 0;
    map->capacity = capacity;
    map->bucket = (HashNode **)malloc(sizeof(HashNode *) * map->capacity);
    if (!map->bucket) {
        free(map);
        return NULL;
    }
    return map;
}

void insert(HashMap *map, const char *key, int value) {
    if (!map || !key)
        return;

    // Calculate bucket index
    unsigned int index = hash(key, map->capacity);

    // Check if key already exist
    HashNode *current = map->bucket[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            // update the existing value
            current->value = value;
            return;
        }
        current = current->next;
    }

    // if the key doesn't match, means its a new key
    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    if (!new_node)
        return;

    // dublicating the key(!important)
    new_node->key = strdup(key);
    new_node->value = value;

    // Inserting at the beginning of the list
    new_node->next = map->bucket[index];
    map->bucket[index] = new_node;

    map->size++;
}

int get(HashMap *map, const char *key, int *found) {
    if (!map || !key) {
        if (found)
            *found = 0;
        return 0;
    }

    unsigned int index = hash(key, map->capacity);

    // search the whole linklist
    HashNode *current = map->bucket[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (found)
                *found = 1;
            return current->value;
        }
        current = current->next;
    }

    // key not found
    if (found)
        *found = 0;
    return 0;
}

void remove_key(HashMap *map, const char *key) {
    if (!map || !key)
        return;

    // calcualte bucket index
    unsigned int index = hash(key, map->capacity);

    HashNode *current = map->bucket[index];
    HashNode *prev = NULL;

    // search for key
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                map->bucket[index] = current->next;
            }

            // free memory
            free(current->key);
            free(current);

            map->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void freeHashMap(HashMap *map) {
    if (!map)
        return;

    // free all nodes
    for (int i = 0; i < map->capacity; ++i) {
        HashNode *current = map->bucket[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;

            free(temp->key);
            free(temp);
        }
    }
    free(map->bucket);
    free(map);
}

// printing all key value pairs
void printHashMap(HashMap *map) {
    if (!map)
        return;

    printf("\nHashMap contents (%d items):\n", map->size);
    for (int i = 0; i < map->capacity; ++i) {
        HashNode *current = map->bucket[i];
        while (current) {
            printf("%s: INR.%d\n", current->key, current->value);
            current = current->next;
        }
    }
}

int main() {
    // Create a hashmap
    HashMap *employee = createHashMap(4);

    // Insert some key-value pairs
    insert(employee, "Arthur", 75000);
    insert(employee, "Tommy", 100000);
    insert(employee, "John", 45000);
    insert(employee, "Michael", 24000);

    // print hashmap table
    printHashMap(employee);

    // lookup values
    int found;

    int value = get(employee, "John", &found);
    printf("\nSalary for John: INR.%d (found %s)", value, found ? "Yes" : "No" );

    value = get(employee, "Duata", &found);
    printf("\nSalary for Duata: INR.%d (found %s)\n", value, found ? "Yes" : "No" );

    // updating value
    insert(employee, "John", 230);
    printf("\nAfter updating John");
    printHashMap(employee);

    // removing
    remove_key(employee, "Arthur");
    printf("\nAfter removing Arthur");
    printHashMap(employee);

    // freeing memory
    freeHashMap(employee);

    return 0;
}
