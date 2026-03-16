
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the top k frequent elements in a given array
void topKFrequent(int arr[], int n, int k) {
    // Create a hash map to store the count of each element
    int hashMap[1000] = {0};
    for (int i = 0; i < n; i++) {
        hashMap[arr[i]]++;
    }

    // Create a priority queue to store the top k elements
    int queue[1000];
    int front = -1, rear = -1;
    for (int i = 0; i < n; i++) {
        if (hashMap[arr[i]] > hashMap[queue[front]]) {
            front = (front + 1) % k;
            queue[front] = arr[i];
        }
    }

    // Print the top k elements
    for (int i = 0; i < k; i++) {
        printf("%d ", queue[(front + i) % k]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    topKFrequent(arr, n, k);
    return 0;
}
