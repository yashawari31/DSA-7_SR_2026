#include <stdio.h>

int* sumArray(int *a, int *b, int n);

int main()
{
    int a[100], b[100], *result;
    int n, i;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    printf("Enter elements of first array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter elements of second array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    result = sumArray(a, b, n);

    printf("Sum array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", *(result + i));

    return 0;
}
int* sumArray(int *a, int *b, int n)
{
    static int result[100];
    int i;

    for(i = 0; i < n; i++)
    {
        result[i] = *(a + i) + *(b + i);
    }

    return result;
}