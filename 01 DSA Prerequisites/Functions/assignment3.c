#include <stdio.h>

void copyString(char *source, char *destination);


int main()
{
    char str1[100], str2[100];

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    copyString(str1, str2);

    printf("Copied string: %s", str2);

    return 0;
}
void copyString(char *source, char *destination)
{
    while(*source != '\0')
    {
        *destination = *source;

        source++;
        destination++;
    }

    *destination = '\0';
}