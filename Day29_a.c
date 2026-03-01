
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* rotate_list(Node* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the last node in the list
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Connect the last node to the first node, forming a circular list
    current->next = head;

    // Traverse to the (n-k)th node and set its next pointer to NULL
    int i = 0;
    while (i < k - 1) {
        current = current->next;
        i++;
    }
    Node* last_node = current->next;
    current->next = NULL;

    // Update the head pointer to point to the (n-k+1)th node
    head = last_node->next;

    return head;
}

int main() {
    int n, k;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        if (head == NULL) {
            head = (Node*)malloc(sizeof(Node));
            head->data = data;
            head->next = NULL;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = (Node*)malloc(sizeof(Node));
            current->next->data = data;
            current->next->next = NULL;
        }
    }

    scanf("%d", &k);
    head = rotate_list(head, k);

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}