
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* mergeLists(Node* head1, Node* head2) {
    Node* result = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            Node* temp = malloc(sizeof(Node));
            temp->data = head1->data;
            temp->next = result;
            result = temp;
            head1 = head1->next;
        } else {
            Node* temp = malloc(sizeof(Node));
            temp->data = head2->data;
            temp->next = result;
            result = temp;
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        Node* temp = malloc(sizeof(Node));
        temp->data = head1->data;
        temp->next = result;
        result = temp;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        Node* temp = malloc(sizeof(Node));
        temp->data = head2->data;
        temp->next = result;
        result = temp;
        head2 = head2->next;
    }

    return result;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head1 = NULL, *head2 = NULL;
    int n, m, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        Node* temp = malloc(sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = head1;
        head1 = temp;
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        Node* temp = malloc(sizeof(Node));
        scanf("%d", &temp->data);
        temp->next = head2;
        head2 = temp;
    }

    Node* result = mergeLists(head1, head2);
    printList(result);

    return 0;
}