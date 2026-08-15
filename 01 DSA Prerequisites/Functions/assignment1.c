#include <stdio.h>
#include<stdlib.h>
int sumArray(int *arr, int n);

int main()
{
    int n;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr=(int *)malloc(sizeof(int)*n);
    printf("Enter array elements:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Sum = %d", sumArray(arr, n));

    return 0;
}
int sumArray(int *arr, int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}