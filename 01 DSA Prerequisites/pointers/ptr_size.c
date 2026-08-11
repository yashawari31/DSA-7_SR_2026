#include <stdio.h>

int main()
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;

    printf("Size of int pointer    = %zu bytes\n", sizeof(p1));
    printf("Address of int pointer = %p\n\n", &p1);

    printf("Size of char pointer    = %zu bytes\n", sizeof(p2));
    printf("Address of char pointer = %p\n\n", &p2);

    printf("Size of float pointer    = %zu bytes\n", sizeof(p3));
    printf("Address of float pointer = %p\n\n", &p3);

    printf("Size of double pointer    = %zu bytes\n", sizeof(p4));
    printf("Address of double pointer = %p\n", &p4);

    return 0;
}