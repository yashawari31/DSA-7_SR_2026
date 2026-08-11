#include <stdio.h>

int main()
{
    char str[100];
    char *ptr;

    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);

    ptr = str;

    printf("String is: ");

    while(*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }

    return 0;
}