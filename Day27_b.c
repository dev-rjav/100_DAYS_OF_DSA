
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void removeCycle(Node** head) {
    // Check if the list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Find the cycle
    Node* slow = *head;
    Node* fast = (*head)->next->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Check if the cycle is not just a self-loop
    if (slow == *head) {
        return;
    }

    // Find the start of the cycle
    Node* cycleStart = slow;
    while (cycleStart->next != slow) {
        cycleStart = cycleStart->next;
    }

    // Remove the cycle
    cycleStart->next = NULL;
}

int main() {
    int n, i;
    Node* head = NULL;
    Node* temp = NULL;

    // Get the number of nodes in the list
    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);

    // Create a linked list with n nodes
    for (i = 0; i < n; i++) {
        temp = malloc(sizeof(Node));
        temp->data = i + 1;
        temp->next = head;
        head = temp;
    }

    // Remove the cycle in the linked list
    removeCycle(&head);

    // Print the linked list
    printf("Linked List: ");
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }

    return 0;
}