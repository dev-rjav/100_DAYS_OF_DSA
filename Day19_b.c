
#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int max_sum = arr[0], curr_sum = arr[0];
    for (int i = 1; i < n; i++) {
        if (curr_sum + arr[i] > arr[i]) {
            curr_sum += arr[i];
        } else {
            curr_sum = arr[i];
        }
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    printf("Maximum subarray sum: %d\n", max_sum);

    return 0;
}