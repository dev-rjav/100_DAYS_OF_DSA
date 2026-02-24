
#include<stdio.h>

int main()
{
    int n,i;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    /*Your code to detect cycle in the list */
}