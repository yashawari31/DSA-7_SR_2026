#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count = 0;
    int *arr, *unique;

    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    unique = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < count; j++)
        {
            if(*(arr + i) == *(unique + j))
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            *(unique + count) = *(arr + i);
            count++;
        }
    }

    printf("Array after removing duplicates:\n");

    for(i = 0; i < count; i++)
    {
        printf("%d ", *(unique + i));
    }

    free(arr);
    free(unique);

    return 0;
}