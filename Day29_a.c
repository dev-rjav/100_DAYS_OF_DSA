
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to rotate a linked list right by k places
void rotateRight(struct Node** head, int k) {
    // If the list is empty or has only one node, return
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Find the tail of the list
    struct Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Connect the last node to the head forming a circular list
    tail->next = *head;

    // Find the (n-k+1)th node from the tail and set its next to NULL
    struct Node* newHead = *head;
    int count = 0;
    while (count < k) {
        newHead = newHead->next;
        count++;
    }
    newHead->next = NULL;

    // Update the head pointer to the (n-k+1)th node
    *head = newHead;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with n nodes
    int n, k;
    scanf("%d", &n);
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Rotate the linked list right by k places
    scanf("%d", &k);
    rotateRight(&head, k);

    // Print the rotated linked list
    printList(head);

    return 0;
}