#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    // Initialize a counter to keep track of the number of nodes
    int count = 0;

    // Loop through the linked list and increment the counter for each node
    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int main() {
    struct Node* head = NULL;
    int n, i, data;

    // Get the number of elements in the linked list from the user
    scanf("%d", &n);

    // Create a new node for each element and add it to the end of the list
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            // Add the new node to the end of the list
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    // Print the total number of nodes in the linked list
    printf("%d\n", countNodes(head));

    return 0;
}