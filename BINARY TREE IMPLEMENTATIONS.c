#include <stdio.h>
#include <stdlib.h>  // Include for malloc

struct node {
    int data;
    struct node *right;
    struct node *left;
};  // Added semicolon

struct node* create();  // Function prototype

int main() {
    struct node *root;
    root = create();
    return 0;  // Return 0 at the end of main
}

struct node* create() {
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));  // Use struct node
    if (newnode == NULL) {  // Check if malloc failed
        printf("Memory allocation failed\n");
        return NULL;  // Handle malloc failure
    }
    printf("Enter the data (-1 to stop): ");
    scanf("%d", &x);
    if (x == -1) {
        free(newnode);  // Free allocated memory if user wants to stop
        return NULL;
    }
    newnode->data = x;
    printf("Enter left child of %d: ", x);
    newnode->left = create();
    printf("Enter right child of %d: ", x);
    newnode->right = create();
    return newnode;
}
