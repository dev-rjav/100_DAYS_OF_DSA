#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find intersection point of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    // Calculate lengths of both lists
    int length1 = 0, length2 = 0;
    struct Node* temp1 = head1, *temp2 = head2;
    while (temp1 != NULL) {
        length1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        length2++;
        temp2 = temp2->next;
    }
    
    // Advance pointer in longer list
    if (length1 > length2) {
        for (int i = 0; i < length1 - length2; i++) {
            head1 = head1->next;
        }
    } else if (length2 > length1) {
        for (int i = 0; i < length2 - length1; i++) {
            head2 = head2->next;
        }
    }
    
    // Traverse both lists simultaneously
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // No intersection found
    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = NULL, *head2 = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        if (head1 == NULL) {
            head1 = createNode(data);
        } else {
            struct Node* temp = head1;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = createNode(data);
        }
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        if (head2 == NULL) {
            head2 = createNode(data);
        } else {
            struct Node* temp = head2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = createNode(data);
        }
    }
    
    // Find intersection point of the two lists
    struct Node* intersection = findIntersection(head1, head2);
    
    if (intersection != NULL) {
        printf("Intersection point: %d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }
    
    return 0;
}