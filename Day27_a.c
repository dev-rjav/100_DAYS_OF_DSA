#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to calculate length of the linked list
int getLength(Node *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point of two linked lists
void findIntersection(Node *list1, Node *list2) {
    int diff = getLength(list1) - getLength(list2);
    if (diff > 0) {
        while (diff--) list1 = list1->next;
    } else if (diff < 0) {
        diff = -diff;
        while (diff--) list2 = list2->next;
    }
    while (list1 != NULL && list2 != NULL) {
        if (list1 == list2) break;
        list1 = list1->next;
        list2 = list2->next;
    }
    printf("Intersection point: %d\n", list1 ? list1->data : -1);
}

int main() {
    Node *list1 = NULL, *list2 = NULL;
    int n, m, i;

    // Get input for first linked list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->next = list1;
        list1 = node;
    }

    // Get input for second linked list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->next = list2;
        list2 = node;
    }

    // Find intersection point of two linked lists
    findIntersection(list1, list2);

    return 0;
}