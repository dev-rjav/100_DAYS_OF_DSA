
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert node at the end of the linked list
void insert_at_end(struct Node** head, int key) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        // Traverse to the end of the linked list
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert new node at the end of the linked list
        temp->next = new_node;
    }
}

// Function to count occurrences of a given key in the linked list
int count_occurrences(struct Node* head, int key) {
    // Initialize counter for number of occurrences
    int count = 0;

    // Traverse through the linked list
    while (head != NULL) {
        if (head->data == key) {
            // Increment count if current node's data matches the given key
            count++;
        }
        head = head->next;
    }

    return count;
}

int main() {
    struct Node* head = NULL;

    int n, key;
    scanf("%d", &n);

    // Insert nodes into the linked list
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert_at_end(&head, data);
    }

    // Get key to count occurrences of
    scanf("%d", &key);

    // Count occurrences of the given key in the linked list
    int count = count_occurrences(head, key);

    printf("Number of occurrences: %d\n", count);

    return 0;
}