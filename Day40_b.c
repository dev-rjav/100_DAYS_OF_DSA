
#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns of the temperature matrix: ");
    scanf("%d %d", &rows, &cols);

    int temp[rows][cols];
    printf("Enter the daily temperatures: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the temperature for day %d: ", j+1);
            scanf("%d", &temp[i][j]);
        }
    }

    printf("The daily temperatures are: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }

    return 0;
}