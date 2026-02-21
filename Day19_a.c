#include <stdio.h>

int main() {
    int n, arr[n], i, j;
    int min = 1000000; // initialize minimum sum to a large value
    int first, second;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // iterate through the array and find the pair with the smallest sum
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < min) {
                min = abs(sum);
                first = arr[i];
                second = arr[j];
            }
        }
    }

    // print the pair of elements whose sum is closest to zero
    printf("%d %d\n", first, second);

    return 0;
}