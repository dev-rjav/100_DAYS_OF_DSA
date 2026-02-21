#include <stdio.h>
int main() {
    int n, max_so_far = 0, max_ending_here = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        max_ending_here += arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        else if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    printf("Maximum contiguous sum is: %d\n", max_so_far);
}