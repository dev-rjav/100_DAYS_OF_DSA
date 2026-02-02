// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left

#include <stdio.h>

int main()
{
    int arr[100];
    int i,places,a,number,temp=0;
    printf("Enter number of elements in array : ");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        printf("Enter %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter index of number you want to delete : ");
    scanf("%d",&number);
    arr[number-1]=arr[number];
    for(i=number;i<a;i++){
        arr[i]=arr[i+1];}
        printf("The final array is : ");
    for (i=0;i<(a-1);i++){
        printf("%d ",arr[i]);
    }
    return 0;
}