
#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Put in the data
    new_node->data = new_data;

    // Make next of new node as head
    new_node->next = (*head_ref);

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to delete first occurrence of a key in a linked list
void deleteFirstOccurrence(struct Node** head_ref, int key) {
    // If linked list is empty, return
    if ((*head_ref) == NULL) {
        return;
    }

    // If the first node contains the key, remove it
    if ((*head_ref)->data == key) {
        struct Node* temp = (*head_ref);
        (*head_ref) = (*head_ref)->next;
        free(temp);
    } else {
        // Traverse through the list and find the first node containing the key
        struct Node* current = (*head_ref);
        while (current->next != NULL && current->next->data != key) {
            current = current->next;
        }

        if (current->next == NULL) {
            return;
        }

        // Remove the node with the key
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Function to print linked list elements after deletion
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, key;

    // Get the number of elements in the linked list and insert them at the beginning of the list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }

    // Get the key to be deleted and delete it from the list
    scanf("%d", &key);
    deleteFirstOccurrence(&head, key);

    // Print the linked list elements after deletion
    printList(head);

    return 0;
}