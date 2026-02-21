
#include <stdio.h>

int main() {
    int arr[5];
    int i, j;
    int product = 1;

    // Input array elements from user
    printf("Enter the elements of the array: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the product of all elements except self
    for (i = 0; i < 5; i++) {
        if (i == j) continue;
        product *= arr[j];
    }

    // Print the result
    printf("The product of all elements except %d is: ", arr[i]);
    for (j = 0; j < 5; j++) {
        if (j == i) continue;
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}