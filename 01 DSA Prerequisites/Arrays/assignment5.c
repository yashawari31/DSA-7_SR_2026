#include<stdio.h>
#include<stdlib.h>


int secondLargestNumber(int *arr,int n);


int main()
{
    int size;
    printf("enter the size of array\n");
    scanf("%d",&size);

    int *arr=(int *)malloc(sizeof(int)*size);

    printf("Enter array elements\n");
    for(int i=0;i<size;i++)
       scanf("%d",&arr[i]);

    printf("The second largest element is: %d",secondLargestNumber(arr,size));  
    
    return 0;
}

int secondLargestNumber(int *arr,int n)
{
  int largest=arr[0];
  int secondLargest=arr[0];

  for(int i=0;i<n;i++)
  {
    if(arr[i]>largest)
    {
        secondLargest=largest;
        largest=arr[i];
    }
    else if(arr[i] > secondLargest && arr[i] != largest)
    {
        secondLargest = arr[i];
    }
  }

  return secondLargest;
}