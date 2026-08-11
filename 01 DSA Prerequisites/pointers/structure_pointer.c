#include <stdio.h>

struct Student
{
    int rollno;
    char name[50];
    float marks;
};

int main()
{
    struct Student s;
    struct Student *ptr;

    ptr = &s;

    printf("Enter roll number: ");
    scanf("%d", &ptr->rollno);

    printf("Enter name:");
    getchar();
    fgets(ptr->name,sizeof(ptr->name),stdin);

    printf("Enter marks: ");
    scanf("%f", &ptr->marks);

    printf("\nStudent Details:\n");
    printf("Roll Number = %d\n", ptr->rollno);
    printf("Name        = %s\n", ptr->name);
    printf("Marks       = %.2f\n", ptr->marks);

    return 0;
}