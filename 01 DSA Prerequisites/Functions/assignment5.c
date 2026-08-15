#include <stdio.h>

void reverseString(char *str)
{
    int length=0;
    char temp;

    for(int i=0;str[i]!='\0';i++)
    {
        length++;
    }


    for(int i=0;i<(length/2);i++)
    {
        temp = str[i];
        str[i]=str[length-1-i];
        str[length-1-i]=temp;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    reverseString(str);

    printf("Reversed string: %s", str);

    return 0;
}