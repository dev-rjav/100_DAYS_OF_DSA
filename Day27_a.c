
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

void printList(struct Node* head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            head1 = head1->next;
        }
    } else if (len2 > len1) {
        for (int i = 0; i < len2 - len1; i++) {
            head2 = head2->next;
        }
    }
    while (head1 != NULL && head2 != NULL && head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = NULL;
    struct Node* current1 = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head1 == NULL) {
            head1 = current1 = newNode;
        } else {
            current1->next = newNode;
            current1 = newNode;
        }
    }
    scanf("%d", &m);
    struct Node* head2 = NULL;
    struct Node* current2 = NULL;
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head2 == NULL) {
            head2 = current2 = newNode;
        } else {
            current2->next = newNode;
            current2 = newNode;
        }
    }
    struct Node* intersectionNode = getIntersectionNode(head1, head2);
    if (intersectionNode != NULL) {
        printf("Intersection node: %d\n", intersectionNode->data);
    } else {
        printf("No Intersection\n");
    }
    return 0;
}