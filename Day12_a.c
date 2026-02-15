#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);
    int matrix[m][n];

    // Read elements of the matrix
    for(int i=0; i<m; i++) {
        printf("Enter %d elements of row %d: ", n, i+1);
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is symmetric
    int check = 0;
    for(int i=0; i<m/2; i++) {
        for(int j=0; j<n/2; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                check = 1;
                break;
            }
        }
        if(check == 1) {
            break;
        }
    }

    // Print result
    if(check == 0) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}