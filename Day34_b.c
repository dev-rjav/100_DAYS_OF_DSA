
#include <stdio.h>
#define MAX_STACK_SIZE 100

// Function to evaluate a reverse polish notation expression
void evalRPN(char[] expr) {
    int stack[MAX_STACK_SIZE];
    int top = -1;
    char* token;
    char* delim = " ";

    // Tokenize the input string
    while ((token = strtok(expr, delim)) != NULL) {
        expr = NULL;

        // Check if the token is a number or an operator
        if (isdigit(token[0])) {
            // Push the number onto the stack
            stack[++top] = atoi(token);
        } else {
            // Pop the top two elements from the stack
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            // Perform the operation and push the result onto the stack
            switch (token[0]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        }
    }

    // Print the final result
    printf("Result: %d\n", stack[top]);
}

int main() {
    char expr[] = "3 4 5 * +";
    evalRPN(expr);
    return 0;
}