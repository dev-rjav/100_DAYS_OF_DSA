// Insert an Element in an Array

// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

// Example:
// Input:
// 5
// 1 2 4 5 6
// 3
// 3

// Output:
// 1 2 3 4 5 6

// Explanation: Insert 3 at position 3, elements [4,5,6] shift right

#include <stdio.h>

int main()
{
    int arr[100];
    int i,places,a,number=0;
    printf("Enter number of elements in array : ");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        printf("Enter %d element",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter where you want to insert element : ");
    scanf("%d",&places);
    printf("Enter number you want to enter : ");
    scanf("%d",&number);
    for(i=a-1;i>=places-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[places-1]=number;
    printf("The final array is : ");
    for (i=0;i<(a+1);i++){
        printf("%d ",arr[i]);
    }
    return 0;
}