
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to perform inorder traversal of a binary tree
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to create a new node in the binary tree
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
void insertNode(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
}

// Function to print the binary tree in inorder traversal
void printInorder(struct node* root) {
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
}

int main() {
    // Initialize the binary tree as empty
    struct node* root = NULL;

    // Insert some nodes in the binary tree
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 18);

    // Print the binary tree in inorder traversal
    printInorder(root);

    return 0;
}