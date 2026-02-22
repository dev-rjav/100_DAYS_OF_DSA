#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i;
    struct Node* head = NULL;
    struct Node* temp = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}