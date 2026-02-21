 
#include <stdio.h>

void rotate_array(int arr[], int n, int k) {
    // Initialize the temporary array
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    // Rotate the elements of the original array
    for (int i = 0; i < k; i++) {
        int firstElement = temp[0];
        for (int j = 0; j < n - 1; j++) {
            temp[j] = temp[j + 1];
        }
        temp[n - 1] = firstElement;
    }

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    rotate_array(arr, 5, 2);
    return 0;
}