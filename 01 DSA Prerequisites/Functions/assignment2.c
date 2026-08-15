#include <stdio.h>

int stringLength(char *str);

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Length = %d", stringLength(str));

    return 0;
}

int stringLength(char *str)
{
    int length = 0;

    while(str[length]!= '\0' && str[length]!='\n')
    {
        length++;
    }

    return length;
}