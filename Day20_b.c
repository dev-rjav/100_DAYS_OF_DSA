
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            if (arr[i] + arr[j] == 0) {
                printf("Found a triplet: %d, %d, %d\n", arr[i], arr[j], -arr[i] - arr[j]);
            }
        }
    }

    return 0;
}