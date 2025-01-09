//BST
#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int info;
    struct tnode *llink, *rlink;
};
typedef struct tnode *TNODE;

// Get new node
TNODE get_node() {
    TNODE temp = (TNODE)malloc(sizeof(struct tnode));
    temp->llink = temp->rlink = NULL;
    return temp;
}

// Insert a node into the BST
TNODE insert(TNODE root, int ele) {
    if (!root) {
        TNODE temp = get_node();
        temp->info = ele;
        return temp;
    }
    if (ele < root->info) root->llink = insert(root->llink, ele);
    else if (ele > root->info) root->rlink = insert(root->rlink, ele);
    return root;
}

// Preorder traversal
void preorder(TNODE root) {
    if (root) {
        printf("%d\t", root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

// Inorder traversal
void inorder(TNODE root) {
    if (root) {
        inorder(root->llink);
        printf("%d\t", root->info);
        inorder(root->rlink);
    }
}

// Postorder traversal
void postorder(TNODE root) {
    if (root) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->info);
    }
}

// Search for a key in the BST
int search(TNODE root, int key) {
    if (root) {
        if (root->info == key) return key;
        if (key < root->info) return search(root->llink, key);
        return search(root->rlink, key);
    }
    return -1;
}

// Main function
int main() {
    TNODE root = NULL;
    int choice, ele, key;

    printf("\n1. Insert \n2. Search \n3. Display \n4. Exit\n");
    for (;;) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &ele);
                key = search(root, ele);
                printf(key == -1 ? "Key not found\n" : "Key found\n");
                break;
            case 3:
                printf("Preorder: "); preorder(root);
                printf("\nInorder: "); inorder(root);
                printf("\nPostorder: "); postorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
}
