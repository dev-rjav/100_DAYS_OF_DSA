#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* create_node(int coeff, int exp) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insert_node(Node** head, int coeff, int exp) {
    Node* node = create_node(coeff, exp);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* curr = *head;
        while (curr->next != NULL && curr->exp < exp) {
            curr = curr->next;
        }
        if (curr->exp >= exp) {
            node->next = curr;
            *head = node;
        } else {
            curr->next = node;
        }
    }
}

void print_polynomial(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%dx^%d", curr->coeff, curr->exp);
        if (curr->next != NULL) {
            printf(" + ");
        }
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        insert_node(&head, coeff, exp);
    }
    print_polynomial(head);
    return 0;
}