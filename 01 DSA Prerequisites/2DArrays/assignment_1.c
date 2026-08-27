#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int i, j, temp;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter number of columns: ");
    scanf("%d", &m);

    // Dynamic allocation of 2D array
    int **arr = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Accept elements
    printf("Enter matrix elements:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display matrix
    printf("\nMatrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // 1. Sum of all elements
    int sum = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            sum = sum + arr[i][j];
        }
    }

    printf("\nSum of all elements = %d\n", sum);

    // 2. Sum of elements from 2nd column
    int columnSum = 0;

    if(m >= 2)
    {
        for(i = 0; i < n; i++)
        {
            columnSum = columnSum + arr[i][1];
        }

        printf("Sum of 2nd column = %d\n", columnSum);
    }
    else
    {
        printf("2nd column does not exist.\n");
    }

    // Diagonal operations only make sense for square matrix
    if(n == m)
    {
        // 3. Display left diagonal
        printf("\nLeft diagonal: ");

        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i][i]);
        }

        // 4. Display right diagonal
        printf("\nRight diagonal: ");

        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i][n - 1 - i]);
        }

        // 5. Sum of left diagonal
        int leftSum = 0;

        for(i = 0; i < n; i++)
        {
            leftSum = leftSum + arr[i][i];
        }

        printf("\n\nSum of left diagonal = %d\n", leftSum);

        // 6. Sum of right diagonal
        int rightSum = 0;

        for(i = 0; i < n; i++)
        {
            rightSum = rightSum + arr[i][n - 1 - i];
        }

        printf("Sum of right diagonal = %d\n", rightSum);

        // 7. Larger and smaller from left diagonal
        int leftLargest = arr[0][0];
        int leftSmallest = arr[0][0];

        for(i = 0; i < n; i++)
        {
            if(arr[i][i] > leftLargest)
                leftLargest = arr[i][i];

            if(arr[i][i] < leftSmallest)
                leftSmallest = arr[i][i];
        }

        printf("Larger element from left diagonal = %d\n", leftLargest);
        printf("Smaller element from left diagonal = %d\n", leftSmallest);

        // 8. Larger and smaller from right diagonal
        int rightLargest = arr[0][n - 1];
        int rightSmallest = arr[0][n - 1];

        for(i = 0; i < n; i++)
        {
            if(arr[i][n - 1 - i] > rightLargest)
                rightLargest = arr[i][n - 1 - i];

            if(arr[i][n - 1 - i] < rightSmallest)
                rightSmallest = arr[i][n - 1 - i];
        }

        printf("Larger element from right diagonal = %d\n", rightLargest);
        printf("Smaller element from right diagonal = %d\n", rightSmallest);

        // 9. Sort left diagonal
        // Bubble sort
        for(i = 0; i < n - 1; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                if(arr[i][i] > arr[j][j])
                {
                    temp = arr[i][i];
                    arr[i][i] = arr[j][j];
                    arr[j][j] = temp;
                }
            }
        }

        printf("\nLeft diagonal after sorting: ");

        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i][i]);
        }

        // 10. Sort right diagonal
        for(i = 0; i < n - 1; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                if(arr[i][n - 1 - i] > arr[j][n - 1 - j])
                {
                    temp = arr[i][n - 1 - i];
                    arr[i][n - 1 - i] = arr[j][n - 1 - j];
                    arr[j][n - 1 - j] = temp;
                }
            }
        }

        printf("\nRight diagonal after sorting: ");

        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i][n - 1 - i]);
        }
    }
    else
    {
        printf("\nDiagonal operations require a square matrix.\n");
    }

    // Free memory
    for(i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}