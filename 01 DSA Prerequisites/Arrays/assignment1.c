#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count;
    int *arr;

    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    printf("Occurences of each element:\n");

    for(i = 0; i < n; i++)
    {
        count = 0;

        
        for(j = 0; j < i; j++)
        {
            if(*(arr + i) == *(arr + j))
            {
                count = -1;
                break;
            }
        }


        if(count == -1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(*(arr + i) == *(arr + j))
            {
                count++;
            }
        }

        printf("%d -> %d times\n", *(arr + i), count);
    }

    free(arr);

    return 0;
}