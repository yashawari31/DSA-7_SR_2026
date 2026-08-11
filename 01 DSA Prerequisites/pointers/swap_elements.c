#include <stdio.h>

int main()
{
    int a[5], b[5];
    int i, temp;

    printf("Enter elements of first array:\n");
    for(i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    printf("Enter elements of second array:\n");
    for(i = 0; i < 5; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < 5; i++)
    {
        temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }

    printf("\nFirst array after swapping:\n");
    for(i = 0; i < 5; i++)
        printf("%d ", *(a + i));

    printf("\nSecond array after swapping:\n");
    for(i = 0; i < 5; i++)
        printf("%d ", *(b + i));

    return 0;
}