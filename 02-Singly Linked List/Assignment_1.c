
/*
write a c program to create and display a node. with structure "Student" with following data members: 
-Name -Roll no -standard -Division 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stud
{
    char name[20];
    int rollno;
    char standard[5];
    char division;


}Student;

int main()
{
    Student *node;

    node = (Student *)malloc(sizeof(Student));

    if(node == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter name: ");
    fgets(node->name, sizeof(node->name), stdin);

    

    printf("Enter roll no: ");
    scanf("%d", &node->rollno);

    printf("Enter standard: ");
    scanf("%4s", node->standard);

    printf("Enter division: ");
    scanf(" %c", &node->division);

    // Display student details
    printf("\nStudent Details:\n");
    printf("Name      : %s\n", node->name);
    printf("Roll No   : %d\n", node->rollno);
    printf("Standard  : %s\n", node->standard);
    printf("Division  : %c\n", node->division);

    free(node);

    return 0;
}
