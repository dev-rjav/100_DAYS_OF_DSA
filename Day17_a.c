
#include <stdio.h>

int main() {
    int n, i;
    int arr[n];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Get input for each element in the array
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Find maximum and minimum elements
    int max = arr[0];
    int min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    // Print maximum and minimum elements
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    return 0;
}