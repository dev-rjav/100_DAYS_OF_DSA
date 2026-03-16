
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a min heap node
typedef struct HeapNode {
    int value;
    struct HeapNode* left;
    struct HeapNode* right;
} HeapNode;

// Function to create a new min heap node
HeapNode* newHeapNode(int value) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new element into the min heap
void insert(HeapNode** root, int value) {
    // If the heap is empty, create a new root node
    if (*root == NULL) {
        *root = newHeapNode(value);
        return;
    }

    // If the value is less than the root node, create a new left child node
    if (value < (*root)->value) {
        (*root)->left = newHeapNode(value);
        return;
    }

    // If the value is greater than the root node, create a new right child node
    if (value > (*root)->value) {
        (*root)->right = newHeapNode(value);
        return;
    }
}

// Function to extract the minimum element from the min heap
int extractMin(HeapNode** root) {
    // If the heap is empty, return -1
    if (*root == NULL) {
        return -1;
    }

    // If the root node has no left child, delete the root node and return its value
    if ((*root)->left == NULL) {
        int value = (*root)->value;
        HeapNode* temp = *root;
        *root = (*root)->right;
        free(temp);
        return value;
    }

    // If the root node has a left child, find the minimum element in the left subtree
    // and delete it
    HeapNode* current = (*root)->left;
    HeapNode* parent = *root;
    while (current->left != NULL) {
        parent = current;
        current = current->left;
    }

    int value = current->value;
    if (parent->left == current) {
        parent->left = current->right;
    } else {
        parent->right = current->right;
    }
    free(current);
    return value;
}

// Function to peek the minimum element in the min heap
int peek(HeapNode* root) {
    // If the heap is empty, return -1
    if (root == NULL) {
        return -1;
    }

    // If the root node has no left child, return its value
    if (root->left == NULL) {
        return root->value;
    }

    // If the root node has a left child, find the minimum element in the left subtree
    // and return its value
    HeapNode* current = root->left;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->value;
}

int main() {
    // Create an empty min heap
    HeapNode* root = NULL;

    // Read the number of heap operations
    int n;
    scanf("%d", &n);

    // Read the heap operations
    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);

        if (operation == 1) { // Insert
            int value;
            scanf("%d", &value);
            insert(&root, value);
        } else if (operation == 2) { // ExtractMin
            int value = extractMin(&root);
            if (value != -1) {
                printf("%d\n", value);
            } else {
                printf("-1\n");
            }
        } else if (operation == 3) { // Peek
            int value = peek(root);
            if (value != -1) {
                printf("%d\n", value);
            } else {
                printf("-1\n");
            }
        }
    }

    return 0;
}