
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the median of a stream of integers
void findMedian(int *arr, int n) {
    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the median
    if (n % 2 == 0) {
        printf("Median = %d\n", (arr[n / 2 - 1] + arr[n / 2]) / 2);
    } else {
        printf("Median = %d\n", arr[n / 2]);
    }
}

int main() {
    int arr[10];
    int n;

    // Get input from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Call the function to find the median
    findMedian(arr, n);

    return 0;
}