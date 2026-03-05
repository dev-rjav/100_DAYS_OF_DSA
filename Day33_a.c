#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node** head, char data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

char pop(Node** head) {
    if (*head == NULL) {
        return '\0';
    }
    Node* temp = *head;
    char data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}

void infix_to_postfix(char* expression) {
    // Initialize stack
    Node* stack = NULL;

    // Loop through each character in the expression
    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        // If the character is an operand, output it directly
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("%c", c);
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!is_empty(stack)) {
                char data = pop(&stack);
                if (data != '(') {
                    printf("%c", data);
                } else {
                    break;
                }
            }
        } else {
            // If the character is an operator, push it onto the stack considering precedence
            int prec = get_precedence(c);
            while (!is_empty(stack) && (get_precedence(peek(&stack)) >= prec)) {
                char data = pop(&stack);
                printf("%c", data);
            }
            push(&stack, c);
        }
    }

    // Pop remaining operators from the stack and output them
    while (!is_empty(stack)) {
        char data = pop(&stack);
        printf("%c", data);
    }
}

int main() {
    int n;
    scanf("%d\n", &n);
    char expression[100];
    scanf("%s", expression);
    infix_to_postfix(expression);
    return 0;
}