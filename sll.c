//SLL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20], usn[10], branch[5], phno[10];
    int sem;
    struct node *link;
};
typedef struct node *NODE;

// Get new node
NODE get_node() {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("\nName: "); scanf("%s", temp->name);
    printf("USN: "); scanf("%s", temp->usn);
    printf("Branch: "); scanf("%s", temp->branch);
    printf("Sem: "); scanf("%d", &temp->sem);
    printf("Ph No: "); scanf("%s", temp->phno);
    return temp;
}

// Insert at front
NODE insert_front(NODE first) {
    NODE temp = get_node();
    temp->link = first;
    return temp;
}

// Insert at rear
NODE insert_rear(NODE first) {
    NODE temp = get_node(), cur = first;
    if (!first) return temp;
    while (cur->link) cur = cur->link;
    cur->link = temp;
    return first;
}

// Delete front
NODE del_front(NODE first) {
    if (!first) {
        printf("\nNo entries\n");
        return NULL;
    }
    NODE temp = first;
    first = first->link;
    free(temp);
    return first;
}

// Delete rear
NODE del_rear(NODE first) {
    if (!first) {
        printf("\nNo entries\n");
        return NULL;
    }
    if (!first->link) {
        printf("Deleted USN: %s\n", first->usn);
        free(first);
        return NULL;
    }
    NODE cur = first;
    while (cur->link->link) cur = cur->link;
    printf("Deleted USN: %s\n", cur->link->usn);
    free(cur->link);
    cur->link = NULL;
    return first;
}

// Display list
void display(NODE first) {
    if (!first) {
        printf("\nNo entries\n");
        return;
    }
    printf("\nStudent Info:\n");
    int count = 0;
    while (first) {
        printf("Name: %s\tUSN: %s\tBranch: %s\tSem: %d\tPh No: %s\n", first->name, first->usn, first->branch, first->sem, first->phno);
        first = first->link;
        count++;
    }
    printf("\nTotal Nodes: %d\n", count);
}

// Main function
int main() {
    NODE first = NULL;
    int choice;
    for (;;) {
        printf("\n1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: first = insert_front(first); break;
            case 2: first = insert_rear(first); break;
            case 3: first = del_front(first); break;
            case 4: first = del_rear(first); break;
            case 5: display(first); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
