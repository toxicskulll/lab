#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int SSN, Sal;
    char Name[20], Dept[20], Designation[20], Ph_No[11];
    struct node *llink, *rlink;
};
typedef struct node *NODE;

// Get new node
NODE get_node() {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    printf("\nEnter Employee Details:\n");
    printf("SSN: "); scanf("%d", &temp->SSN);
    printf("Name: "); scanf("%s", temp->Name);
    printf("Dept: "); scanf("%s", temp->Dept);
    printf("Designation: "); scanf("%s", temp->Designation);
    printf("Salary: "); scanf("%d", &temp->Sal);
    printf("Phone: "); scanf("%s", temp->Ph_No);
    return temp;
}

// Insert at front
NODE insert_front(NODE first) {
    NODE temp = get_node();
    if (!first) return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

// Insert at rear
NODE insert_rear(NODE first) {
    NODE temp = get_node();
    if (!first) return temp;
    NODE cur = first;
    while (cur->rlink) cur = cur->rlink;
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

// Delete from front
NODE delete_front(NODE first) {
    if (!first) {
        printf("\nNo nodes to delete\n");
        return NULL;
    }
    NODE temp = first;
    printf("\nDeleted Employee SSN: %d\n", temp->SSN);
    first = first->rlink;
    if (first) first->llink = NULL;
    free(temp);
    return first;
}

// Delete from rear
NODE delete_rear(NODE first) {
    if (!first) {
        printf("\nNo nodes to delete\n");
        return NULL;
    }
    if (!first->rlink) {
        printf("\nDeleted Employee SSN: %d\n", first->SSN);
        free(first);
        return NULL;
    }
    NODE cur = first;
    while (cur->rlink) cur = cur->rlink;
    printf("\nDeleted Employee SSN: %d\n", cur->SSN);
    cur->llink->rlink = NULL;
    free(cur);
    return first;
}

// Display the list
void display(NODE first) {
    if (!first) {
        printf("\nNo nodes in the list\n");
        return;
    }
    int count = 0;
    printf("\nEmployee Details:\n");
    for (NODE temp = first; temp; temp = temp->rlink) {
        printf("SSN: %d\tName: %s\tDept: %s\tDesignation: %s\tSalary: %d\tPhone: %s\n",
               temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->Ph_No);
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
            case 3: first = delete_front(first); break;
            case 4: first = delete_rear(first); break;
            case 5: display(first); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
