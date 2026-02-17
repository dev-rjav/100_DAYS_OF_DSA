#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int check = 1;  // Assume it is identity

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || 
                (i != j && matrix[i][j] != 0)) {
                check = 0;
                break;
            }
        }
        if (check == 0)
            break;
    }

    if (check == 1)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
