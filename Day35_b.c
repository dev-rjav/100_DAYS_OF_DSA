
#include <stdio.h>

int main() {
    int n, m; // dimensions of the matrix
    int numCalls; // number of recent calls
    int i, j; // loop variables

    // Get input for dimensions of the matrix
    printf("Enter the dimensions of the matrix: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    // Get input for the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count the number of recent calls
    numCalls = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                numCalls++;
            }
        }
    }

    // Print the number of recent calls
    printf("Number of recent calls: %d\n", numCalls);

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}