#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} queue;

void init(queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(queue *q) {
    return (q->front == q->rear);
}

int isFull(queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = item;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    return item;
}

void printQueue(queue *q) {
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    queue q;
    init(&q);

    int n, m;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);
        enqueue(&q, item);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int item = dequeue(&q);
        if (item != -1) {
            printf("%d ", item);
        }
    }
    printQueue(&q);

    return 0;
}