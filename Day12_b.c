#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    if (rows % 2 == 1 && cols % 2 == 1) {
        printf("Invalid input. The number of rows and columns must be even.\n");
        return 1;
    }
    
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element (%d, %d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int n = rows/2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (i+j) == (n-1)) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    
    return 0;
}