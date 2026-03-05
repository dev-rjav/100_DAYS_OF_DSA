#include <stdio.h>
int main(){
    int num1, num2;
    char operand;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operand);
    int result = 0;
    switch (operand){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid operand");
            return 0;
    }
    printf("%d %c %d = %d", num1, operand, num2, result);
    return 0;
}