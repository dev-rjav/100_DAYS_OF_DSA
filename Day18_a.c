#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    // Rotate the array to the right by k positions
    for (int i = 0; i < k; i++) {
        int temp = arr[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            arr[j + 1] = arr[j];
        }
        arr[0] = temp;
    }

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}