#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct node* head = NULL;
    int n, i, data;
    scanf("%d", &n);

    // Input the linked list elements
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        if (head == NULL) {
            head = malloc(sizeof(struct node));
            head->data = data;
            head->next = NULL;
        } else {
            struct node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = malloc(sizeof(struct node));
            current->data = data;
            current->next = NULL;
        }
    }

    // Print the linked list elements
    printList(head);

    return 0;
}