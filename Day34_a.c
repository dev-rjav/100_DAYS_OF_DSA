#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures for linked list and node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// Function to initialize stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to push operand onto the stack
void push(Stack* stack, int operand) {
    // Create a new node for the operand
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = operand;
    newNode->next = NULL;

    // Push the new node onto the stack
    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

// Function to pop operand from the stack
int pop(Stack* stack) {
    // Check if the stack is empty
    if (stack->top == NULL) {
        return -1;
    }

    // Get the top node's data
    int result = stack->top->data;

    // Remove the top node from the stack
    Node* temp = stack->top;
    stack->top = stack->top->next;

    // Free the memory of the removed node
    free(temp);

    return result;
}

// Function to evaluate postfix expression using linked list with dynamic memory allocation
void evaluatePostfix(char* expression) {
    // Create a new stack
    Stack stack;
    initStack(&stack);

    // Loop through the expression and evaluate it
    for (int i = 0; expression[i] != '\0'; i++) {
        // Check if the current character is an operand
        if (isdigit(expression[i])) {
            // Push the operand onto the stack
            push(&stack, expression[i] - '0');
        } else {
            // Get the two operands from the stack
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            // Apply the operator on the operands
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    // Print the result of the expression
    printf("%d\n", pop(&stack));
}

int main() {
    char* expression = "2 3 1 * + 9 -";
    evaluatePostfix(expression);
    return 0;
}