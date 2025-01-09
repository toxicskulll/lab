#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int hashTable[MAX];

// Hash function to create a key
int hashFunc(int key) {
    return key % MAX;
}

// Insert a key using linear probing
void insert(int key) {
    int index = hashFunc(key);

    // Linear probing to resolve collisions
    while (hashTable[index] != -1) {
        printf("Collision at index %d! Probing...\n", index);
        index = (index + 1) % MAX;
    }
    hashTable[index] = key;
    printf("Inserted key %d at index %d\n", key, index);
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < MAX; i++) {
        if (hashTable[i] != -1)
            printf("%d -> %d\n", i, hashTable[i]);
        else
            printf("%d -> EMPTY\n", i);
    }
}

int main() {
    for (int i = 0; i < MAX; i++) hashTable[i] = -1;

    int key, choice;
    do {
        printf("\nEnter a 4-digit Employee Key: ");
        scanf("%d", &key);
        insert(key);

        printf("Do you want to continue? (1-Yes / 0-No): ");
        scanf("%d", &choice);
    } while (choice);

    display();
    return 0;
}
