#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];
    int sum = 0;

    // Read array elements
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Sum of first n natural numbers
    int expected_sum = n * (n + 1) / 2;

    // Missing number
    int missing = expected_sum - sum;

    printf("Missing element = %d\n", missing);

    return 0;
}
