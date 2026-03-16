#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void enqueue(struct queue* q, int x) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue* q) {
    if (q->front == NULL) {
        return -1;
    } else {
        int data = q->front->data;
        struct node* temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}

int main() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;

    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(q, x);
        } else if (strcmp(operation, "dequeue") == 0) {
            int data = dequeue(q);
            if (data != -1) {
                printf("%d\n", data);
            } else {
                printf("-1\n");
            }
        }
    }

    return 0;
}