    #include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void print_list(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

bool is_palindrome(node* head) {
    int i, j;
    node* current = head;
    int size = 0;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    int forward[size];
    int backward[size];

    for (i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
        forward[i] = head->data;
        backward[j] = head->next->data;
        head = head->next;
    }

    for (i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
        if (forward[i] != backward[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    scanf("%d", &n);

    node* head = NULL;
    node* temp = NULL;

    for (int i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node));
        scanf("%d", &temp->data);
        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }
        current = temp;
    }

    printf("Is Palindrome: %s\n", is_palindrome(head) ? "true" : "false");

    return 0;
}