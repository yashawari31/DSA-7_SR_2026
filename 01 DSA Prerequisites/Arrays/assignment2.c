#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, unique;
    int *arr;

    printf("Enter size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        while(1)
        {
            printf("Enter element %d: ", i + 1);
            scanf("%d", arr + i);

            unique = 1;

            for(j = 0; j < i; j++)
            {
                if(*(arr + i) == *(arr + j))
                {
                    unique = 0;
                    break;
                }
            }

            if(unique == 1)
                break;

            printf("Element already exists! Enter a different element.\n");
        }
    }

    printf("\nArray with unique elements:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}