
#include <stdio.h>

int main() {
    int n, k;
    int arr[n];

    // Input array size and k-th largest element
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Input array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the k-th largest element
    printf("The %d-th largest element is: %d\n", k, arr[k - 1]);

    return 0;
}