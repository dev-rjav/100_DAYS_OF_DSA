#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // count the frequency of each distinct element
    int freq[100] = {0};
    for (i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // print the result
    printf("Element: Frequency\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], freq[arr[i]]);
    }

    return 0;
}