
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void remove_cycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow == fast) {
        struct Node* temp = head;

        while (temp->next != slow) {
            temp = temp->next;
        }

        temp->next = NULL;
    }
}

int main() {
    struct Node* head = NULL;
    int n, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i + 1;
        new_node->next = head;
        head = new_node;
    }

    printf("The linked list is: ");
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    remove_cycle(head);

    printf("\nAfter removing cycle: ");
    temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}