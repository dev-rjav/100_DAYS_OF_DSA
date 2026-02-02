#include <stdio.h>

int main()
{
    int arr[100], n, target;
    int i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("Indices: %d and %d\n", i, j);
                printf("Values: %d + %d = %d\n", arr[i], arr[j], target);
                return 0;
            }
        }
    }

    printf("No two elements found\n");
    return 0;
}
