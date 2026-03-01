
#include <stdio.h>

int main() {
    int num1, num2;

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculate sum
    int sum = num1 + num2;

    // Print output
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}