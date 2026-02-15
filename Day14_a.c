#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &n);
    
    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Check if the matrix is an identity matrix
    int check = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-1; j++) {
            if (matrix[i][j] != 0 || matrix[i][j+1] != 1) {
                check = 0;
                break;
            }
        }
    }
    
    // Print the result
    if (check == 1) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    
    return 0;
}