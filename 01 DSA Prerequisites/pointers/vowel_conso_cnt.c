#include <stdio.h>

int main()
{
    char str[20];
    char *ptr;
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    ptr = str;

    while(*ptr != '\0')
    {
        if((*ptr >= 'A' && *ptr <= 'Z') ||
           (*ptr >= 'a' && *ptr <= 'z'))
        {
            if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' ||
               *ptr == 'o' || *ptr == 'u' ||
               *ptr == 'A' || *ptr == 'E' || *ptr == 'I' ||
               *ptr == 'O' || *ptr == 'U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }

        ptr++;
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);

    return 0;
}