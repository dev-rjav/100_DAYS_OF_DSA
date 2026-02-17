
#include <stdio.h>

void rotateMatrix(int arr[5][5]);

int main() {
    int arr[5][5];
    printf("Enter elements:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    rotateMatrix(arr);
    return 0;
}

void rotateMatrix(int arr[][5]) {
    int temp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                continue;
            } else {
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
}