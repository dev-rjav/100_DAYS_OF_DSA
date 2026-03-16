#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct deque {
    Node* front;
    Node* rear;
} Deque;

void pushFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

void pushRear(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int popFront(Deque* deque) {
    if (deque->front == NULL) {
        return -1;
    }

    Node* temp = deque->front;
    deque->front = temp->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    }

    int data = temp->data;
    free(temp);
    return data;
}

int popRear(Deque* deque) {
    if (deque->rear == NULL) {
        return -1;
    }

    Node* temp = deque->rear;
    deque->rear = temp->next;
    if (deque->rear == NULL) {
        deque->front = NULL;
    }

    int data = temp->data;
    free(temp);
    return data;
}

int peekFront(Deque* deque) {
    if (deque->front == NULL) {
        return -1;
    }

    return deque->front->data;
}

int peekRear(Deque* deque) {
    if (deque->rear == NULL) {
        return -1;
    }

    return deque->rear->data;
}

int main() {
    Deque deque;
    deque.front = NULL;
    deque.rear = NULL;

    int n, data;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        pushFront(&deque, data);
    }

    while (deque.front != NULL) {
        printf("%d ", popFront(&deque));
    }

    return 0;
}