
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a deque
typedef struct {
    int *arr;
    int front;
    int rear;
} deque;

// Function to create a deque of given size
deque *createDeque(int size) {
    deque *dq = (deque *)malloc(sizeof(deque));
    dq->arr = (int *)malloc(size * sizeof(int));
    dq->front = 0;
    dq->rear = 0;
    return dq;
}

// Function to add an element to the front of the deque
void addFront(deque *dq, int element) {
    if (dq->front == 0) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->arr[dq->front] = element;
}

// Function to add an element to the rear of the deque
void addRear(deque *dq, int element) {
    dq->rear = (dq->rear + 1) % MAX_SIZE;
    dq->arr[dq->rear] = element;
}

// Function to remove an element from the front of the deque
int removeFront(deque *dq) {
    if (dq->front == dq->rear) {
        return -1;
    }
    int element = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX_SIZE;
    return element;
}

// Function to remove an element from the rear of the deque
int removeRear(deque *dq) {
    if (dq->front == dq->rear) {
        return -1;
    }
    int element = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return element;
}

// Function to display the elements of the deque
void display(deque *dq) {
    printf("The elements of the deque are: ");
    for (int i = dq->front; i != dq->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", dq->arr[i]);
    }
    printf("\n");
}

int main() {
    int size, element, choice;
    printf("Enter the size of the deque: ");
    scanf("%d", &size);
    deque *dq = createDeque(size);

    printf("Enter your choice: \n");
    printf("1. Add element to the front\n");
    printf("2. Add element to the rear\n");
    printf("3. Remove element from the front\n");
    printf("4. Remove element from the rear\n");
    printf("5. Display elements\n");
    printf("6. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &element);
                addFront(dq, element);
                break;
            case 2:
                printf("Enter the element to be added: ");
                scanf("%d", &element);
                addRear(dq, element);
                break;
            case 3:
                element = removeFront(dq);
                if (element != -1) {
                    printf("The element removed from the front is: %d\n", element);
                } else {
                    printf("The deque is empty\n");
                }
                break;
            case 4:
                element = removeRear(dq);
                if (element != -1) {
                    printf("The element removed from the rear is: %d\n", element);
                } else {
                    printf("The deque is empty\n");
                }
                break;
            case 5:
                display(dq);
                break;
            case 6:
                return 0;
        }
    }

    return 0;
}