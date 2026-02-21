#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createList(Node** head, int n) {
    Node* curr = *head;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (curr == NULL) {
            curr = malloc(sizeof(Node));
            curr->data = val;
            curr->next = NULL;
            *head = curr;
        } else {
            while (curr->next != NULL) {
                curr = curr->next;
            }
            Node* newNode = malloc(sizeof(Node));
            newNode->data = val;
            newNode->next = NULL;
            curr->next = newNode;
        }
    }
}

void traverseList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n;
    scanf("%d", &n);
    createList(&head, n);
    traverseList(head);
    return 0;
}