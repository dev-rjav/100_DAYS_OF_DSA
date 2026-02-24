    #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void remove_elements(struct Node** head, int key) {
    // Return if the list is empty
    if (*head == NULL)
        return;
    
    // Store head node
    struct Node* current = *head;
    struct Node* previous = NULL;
    
    // Loop through the list
    while (current != NULL) {
        // If the node's value is equal to the key, delete it
        if (current->data == key) {
            // Skip the current node
            previous->next = current->next;
            
            // Free the memory of the deleted node
            free(current);
            
            // Update previous and current nodes
            current = previous->next;
        } else {
            // Move to the next node
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    int key;
    struct Node* head;
    
    scanf("%d", &key);
    head = (struct Node*)malloc(sizeof(struct Node));
    
    // Initialize the list
    head->data = 1;
    head->next = NULL;
    
    // Loop through the list and remove elements with value equal to key
    while (head != NULL) {
        if (head->data == key) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        } else {
            head = head->next;
        }
    }
    
    return 0;
}