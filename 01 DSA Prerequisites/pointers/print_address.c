#include <stdio.h>

int main()
{
    int a[5];
    int i;
    int *ptr;

    ptr = a;

    printf("Enter 5 array elements:\n");

    for(i = 0; i < 5; i++)
        scanf("%d", ptr + i);

    printf("\nArray elements and their addresses:\n");

    for(i = 0; i < 5; i++)
    {
        printf("Element = %d\tAddress = %p\n",
               *(ptr + i), (ptr + i));
    }

    return 0;
}