#include<stdio.h>
#include<stdlib.h>

int *merge(int *array1,int *array2,int n1,int n2);
void sort(int *arr,int size);

int main()
{
    int *arr1=NULL;
    int *arr2=NULL;

    int size1,size2;

    printf("enter the size of first array\n");
    scanf("%d",&size1);

    printf("enter the size of second array\n");
    scanf("%d",&size2);

    arr1=(int *)malloc(sizeof(int)*size1);
    arr2=(int *)malloc(sizeof(int)*size2);

    printf("enter first array elements:\n");
    for(int i=0;i<size1;i++)
    {
        scanf("%d",&arr1[i]);
    }

    printf("enter the second array elements:\n");
    for(int i=0;i<size2;i++)
       scanf("%d",&arr2[i]);


    int *arr=merge(arr1,arr2,size1,size2);   
    printf("merged array is:\n");
    for(int i=0;i<size1+size2;i++)
    {
        printf("%d ",arr[i]);
    }
    sort(arr,size1+size2);
     printf("\nmerged and sorted array is:\n");
    for(int i=0;i<size1+size2;i++)
    {
        printf("%d ",arr[i]);
    }
}


int *merge(int *array1,int *array2,int n1,int n2)
{
     int *merged=(int *)malloc(sizeof(int)*(n1+n2));

    for(int i=0;i<n1+n2;i++)
    {
        if(i<n1)
          merged[i]=array1[i];


        if(i>=n1)
           merged[i]=array2[i-n1];  
    }
    return merged;
}

void sort(int *arr,int size)
{
    int temp=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
