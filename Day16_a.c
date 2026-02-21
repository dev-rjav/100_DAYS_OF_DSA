
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int* arr;

    // Get size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int*)malloc(n * sizeof(int));

    // Get elements of array from user
    printf("Enter %d integers separated by spaces: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency of each distinct element
    int count[100] = {0};
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Print result
    printf("Element Frequency\n");
    for (i = 0; i < 100; i++) {
        if (count[i] != 0) {
            printf("%d %d\n", i, count[i]);
        }
    }

    // Free memory allocated to array
    free(arr);

    return 0;
}