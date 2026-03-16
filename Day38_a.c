#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int priority;
    struct node* next;
};

struct priority_queue {
    struct node** queue;
    int size;
};

void init(struct priority_queue* pq) {
    pq->size = 0;
    pq->queue = (struct node**)malloc(sizeof(struct node*) * 100);
}

void enqueue(struct priority_queue* pq, int key, int priority) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->priority = priority;
    new_node->next = NULL;

    int i = pq->size;
    while (i > 0 && pq->queue[i - 1]->priority < priority) {
        pq->queue[i] = pq->queue[i - 1];
        i--;
    }

    pq->queue[i] = new_node;
    pq->size++;
}

void dequeue(struct priority_queue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }

    struct node* temp = pq->queue[0];
    pq->queue[0] = pq->queue[pq->size - 1];
    pq->queue[pq->size - 1] = temp;
    pq->size--;
    printf("%d\n", temp->key);
    free(temp);
}

void peek(struct priority_queue* pq) {
    if (pq->size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq->queue[0]->key);
}

int main() {
    int n;
    scanf("%d", &n);

    struct priority_queue* pq = (struct priority_queue*)malloc(sizeof(struct priority_queue));
    init(pq);

    char operation[100];
    int key, priority;
    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            scanf("%d%d", &key, &priority);
            enqueue(pq, key, priority);
        } else if (strcmp(operation, "delete") == 0) {
            dequeue(pq);
        } else if (strcmp(operation, "peek") == 0) {
            peek(pq);
        }
    }

    return 0;
}