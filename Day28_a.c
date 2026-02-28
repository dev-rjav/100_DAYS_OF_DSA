
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(int n) {
    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            head = malloc(sizeof(struct Node));
            head->data = i + 1;
            head->next = NULL;
            current = head;
        } else {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode->data = i + 1;
            newNode->next = NULL;
            current->next = newNode;
            current = newNode;
        }
    }

    head->next = head;
}

void traverseList() {
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);
    createList(n);
    traverseList();
    return 0;
}