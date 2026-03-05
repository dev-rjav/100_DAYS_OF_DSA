
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data) {
    // Allocate a new node and store the data in it
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);

    // Move the head to point to the new node
    (*top_ref) = new_node;
}

int pop(struct Node** top_ref) {
    // If stack is empty, return -1
    if ((*top_ref) == NULL) {
        return -1;
    }

    // Store the data of the head node
    int popped = (*top_ref)->data;

    // Move the head to point to the next node
    (*top_ref) = (*top_ref)->next;

    // Free the popped node
    free(popped);

    return popped;
}

void printStack(struct Node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;

    int n, i, x;

    // Get the number of elements to push
    scanf("%d", &n);

    // Push elements to stack
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(&top, x);
    }

    // Pop all the elements from stack
    while (pop(&top) != -1) {
        printf("%d ", top->data);
    }

    return 0;
}