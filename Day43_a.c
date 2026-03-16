
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct node* constructTree(int* arr, int n) {
    int i = 0;
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = arr[i];
    root->left = NULL;
    root->right = NULL;
    i++;
    while (i < n) {
        if (arr[i] == -1) {
            break;
        }
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->left = NULL;
        temp->right = NULL;
        if (arr[i] < root->data) {
            temp->left = root;
            root = temp;
        } else {
            temp->right = root;
            root = temp;
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct node* root = constructTree(arr, n);
    inorder(root);
    return 0;
}