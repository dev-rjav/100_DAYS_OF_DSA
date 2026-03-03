
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data) {
    // Allocate a new node and put data there
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    *top_ref = new_node;
}

int pop(struct Node** top_ref) {
    // If stack is empty, return NULL.
    if ((*top_ref) == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    // Remove the element from the top of the stack and return it.
    struct Node* temp = *top_ref;
    int data = temp->data;
    (*top_ref) = temp->next;
    free(temp);
    return data;
}

void printStack(struct Node* top) {
    // Traverse the stack and print all elements from top to bottom.
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int n, new_data;

    // Get the number of elements to be inserted in stack.
    scanf("%d", &n);

    // Insert n elements into stack.
    for (int i = 0; i < n; i++) {
        scanf("%d", &new_data);
        push(&top, new_data);
    }

    // Print all elements from top to bottom.
    printStack(top);

    // Pop n-1 times and print each element.
    for (int i = 0; i < n - 1; i++) {
        int popped_data = pop(&top);
        printf("%d ", popped_data);
    }

    return 0;
}