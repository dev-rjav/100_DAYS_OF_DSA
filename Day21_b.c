
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;
    int new_data, i;

    for (i = 0; i < 10; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &new_data);
        insertAtEnd(&head, new_data);
    }

    printList(head);

    return 0;
}