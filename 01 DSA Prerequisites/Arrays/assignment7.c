#include<stdio.h>
#include<stdlib.h>

int search(int *arr,int size,int key);
void display(int *arr,int size)
{
    printf("\nArray Elements:\n");
    for(int i=0;i<size;i++)
       printf("%d\n",arr[i]);
}


int main()
{
    int size;
    printf("Enter the array size: ");
    scanf("%d",&size);

    int *arr=(int *)malloc(sizeof(int)*size);

    printf("Enter array elements:\n");
    for(int i=0;i<size;i++)
       scanf("%d",&arr[i]);

    int searchElement;   
    printf("Enter the element to search:");
    scanf("%d",&searchElement);
   int key=search(arr,size,searchElement);
   
   if(key==-1)
     printf("Element not found");

   else
     printf("Element found at position/index %d ",key);

    return 0;
}

int search(int *arr,int size,int key)
{
    int left=0;
    int right=size-1;

    while(left<right)
    {
        if(arr[left]==key)
        {
            return left;
        }
        else if(arr[right]==key)
        {
            return right;
        }

        left++;
        right--;
    }
}