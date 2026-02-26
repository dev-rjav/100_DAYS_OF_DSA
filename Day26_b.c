
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data and return it
Node* create_node(int data) {
    // Allocate memory for the new node
    Node* new_node = (Node*) malloc(sizeof(Node));

    // Set the data for the new node
    new_node->data = data;

    // Set the next pointer to NULL
    new_node->next = NULL;

    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(Node** head, int data) {
    // Create a new node with the given data
    Node* new_node = create_node(data);

    // If the linked list is empty, set the head pointer to point to the new node
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Set the next pointer of the new node to point to the current head of the linked list
        new_node->next = *head;

        // Set the head pointer to point to the new node
        *head = new_node;
    }
}

// Function to insert a node at the end of the linked list
void insert_at_end(Node** head, int data) {
    // Create a new node with the given data
    Node* new_node = create_node(data);

    // If the linked list is empty, set the head pointer to point to the new node
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Traverse to the end of the linked list and insert the new node there
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the elements of the linked list in forward direction
void print_forward(Node* head) {
    // Traverse through the linked list and print each node's data
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Function to print the elements of the linked list in reverse direction
void print_reverse(Node* head) {
    // Traverse through the linked list and print each node's data in reverse order
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    // Create an empty linked list
    Node* head = NULL;

    // Insert nodes at the beginning and end of the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_beginning(&head, 5);

    // Print the elements of the linked list in forward direction
    print_forward(head);

    printf("\n");

    // Print the elements of the linked list in reverse direction
    print_reverse(head);

    return 0;
}