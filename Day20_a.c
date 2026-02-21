
#include <stdio.h>

int main() {
    int n; // size of array
    int arr[n]; // array of integers
    int count = 0; // counter for subarrays with sum zero

    // input the size of the array and the elements of the array
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // loop through the array and find subarrays with sum zero
    for (int i = 0; i < n; i++) {
        int sum = arr[i];
        if (sum == 0) {
            count++;
        } else {
            for (int j = i + 1; j < n; j++) {
                sum += arr[j];
                if (sum == 0) {
                    count++;
                    break;
                }
            }
        }
    }

    // output the number of subarrays with sum zero
    printf("%d\n", count);

    return 0;
}