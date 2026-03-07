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

void enqueue(struct queue* q, int value) {
    // Create a new node
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;

    // If the queue is empty, set both front and rear to new node
    if (q->front == NULL && q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        // Add new node at the end of the queue
        q->rear->next = n;
        q->rear = n;
    }
}

int dequeue(struct queue* q) {
    int value;
    struct node* temp = q->front;

    // If the queue is empty, return -1
    if (q->front == NULL && q->rear == NULL) {
        return -1;
    }

    // Remove the front node from the queue
    value = q->front->data;
    q->front = q->front->next;

    // If the queue is empty after removing front node, set both front and rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return value;
}

void displayQueue(struct queue* q) {
    struct node* temp = q->front;

    printf("The queue is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;

    int n, value;
    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    displayQueue(q);

    // Dequeue elements and display the queue
    while (dequeue(q) != -1) {
        printf("Dequeued element: %d\n", dequeue(q));
        displayQueue(q);
    }

    return 0;
}