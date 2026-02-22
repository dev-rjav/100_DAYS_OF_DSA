[C]
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to reverse a linked list
void reverseList(struct Node **head) {
    // Initialize three pointers to head, previous and current node
    struct Node *current = *head;
    struct Node *previous = NULL;
    struct Node *temp = NULL;

    // Traverse the list and keep changing the links
    while (current != NULL) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    // Update head to point to the last node
    *head = previous;
}

int main() {
    int i, n;
    struct Node *head = NULL;
    struct Node *temp = NULL;

    // Get the number of nodes in the linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Get input from the user for each node and insert it at the end of the list
    for (i = 1; i <= n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    // Print the linked list in forward direction
    printf("Forward Direction: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    // Reverse the linked list and print it in reverse direction
    reverseList(&head);
    printf("\nReverse Direction: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}
