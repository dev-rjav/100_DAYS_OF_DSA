#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}