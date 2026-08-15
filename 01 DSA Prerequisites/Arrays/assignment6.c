#include<stdio.h>
#include<stdlib.h>

void reverseArray(int *arr,int size);
void display(int *arr,int size);
int main()
{
    int size;
    printf("enter the size of array\n");
    scanf("%d",&size);

    int *arr=(int *)malloc(sizeof(int)*size);

    printf("Enter Array elements\n");

    for(int i=0;i<size;i++)
       scanf("%d",&arr[i]);
   
   display(arr,size);
   reverseArray(arr,size);
   printf("Array after reverse\n");
   display(arr,size);
   
   free(arr);

   return 0;

}
void display(int *arr,int size)
{
    printf("\nArray Elements:\n");
    for(int i=0;i<size;i++)
       printf("%d\n",arr[i]);
}

void reverseArray(int *arr,int size)
{
    int temp;
    for(int i=0;i<((size)/2);i++)
    {
      temp=arr[i];
      arr[i]=arr[size-i-1];
      arr[size-i-1]=temp;
    }
}