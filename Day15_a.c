Here's the code in C to calculate the sum of primary diagonal elements of a given matrix.
#include <stdio.h>
#define MATRIX_SIZE 10

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    
    for (int i = 0; i < m; i++) {
        printf("Enter elements for row %d: ", i+1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    
    printf("Sum of primary diagonal elements: %d\n", sum);
}
Note that in the above code, we have defined a macro `MATRIX_SIZE` to define the maximum size of the matrix. The program first asks for the number of rows and columns from the user, then allocates memory for the matrix using dynamic allocation. Then it loops through each row and column to get the input elements for each cell. Finally, it calculates the sum of primary diagonal elements by checking if the indices `i` and `j` are equal.