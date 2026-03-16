
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int min(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int min = INT_MAX;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->array[i] < min) {
            min = stack->array[i];
        }
    }
    return min;
}

void printStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    int capacity, size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    Stack* stack = createStack(size);

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            push(stack, 5);
            break;
        case 2:
            printf("%d\n", pop(stack));
            break;
        case 3:
            printf("%d\n", min(stack));
            break;
        case 4:
            printStack(stack);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}