
#include <stdio.h>

int main() {
    int arr[5][5];

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The rotated array is: \n");
    for (int i = 4; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}