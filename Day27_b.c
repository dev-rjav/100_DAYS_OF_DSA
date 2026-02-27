
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void removeCycle(struct node *head) {
    // check if list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return;
    }

    // get the last node in the list
    struct node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    // check if there is a cycle in the list
    struct node *cur = head;
    while (cur != last) {
        cur = cur->next;
    }

    // remove the cycle by making the last node point to NULL
    last->next = NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL;
    for (int i = 0; i < n; i++) {
        // create a new node and add it to the list
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = i + 1;
        newNode->next = head;
        head = newNode;
    }

    // remove cycle in the linked list
    removeCycle(head);

    // print the linked list
    struct node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    return 0;
}