
#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the size of first array: ");
    scanf("%d", &n);
    printf("Enter elements of first array:\n");
    int arr1[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of second array: ");
    scanf("%d", &m);
    printf("Enter elements of second array:\n");
    int arr2[m];
    for(int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    int result[100];
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr1[i] == arr2[j]) {
                result[count++] = arr1[i];
            }
        }
    }
    printf("Intersection of two arrays:\n");
    for(int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}