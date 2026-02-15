
#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);
    
    int matrix[m][n];
    printf("\nEnter %d elements:\n", m*n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }
    printf("\nSum of primary diagonal elements: %d\n", sum);
    
    return 0;
}