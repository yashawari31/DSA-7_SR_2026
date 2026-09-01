#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stud
{
    char name[20];
    int rollno;
    char standard[5];
    char division;
    
    struct stud *next;
    
}Student;

Student* create(Student *head);
void display(Student *head);

int main()
{
    Student *head=NULL;

    head=create(head);

    display(head);

    Student *temp=head;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}

Student* create(Student *head)
{
    int choice;
    Student *new,*lst;
    do
    {
        new=malloc(sizeof(Student));
        if(new == NULL)
      {
        printf("Memory allocation failed\n");
        return head;
      }
      new->next=NULL;
        printf("Enter the data of node: \n");

         printf("Enter name: ");
        fgets(new->name, sizeof(new->name), stdin);

        new->name[strcspn(new->name, "\n")] = '\0';
    

         printf("Enter roll no: ");
        scanf("%d", &new->rollno);

        printf("Enter standard: ");
        scanf("%4s", new->standard);

        printf("Enter division: ");
        scanf(" %c", &new->division);

        if(head==NULL)
        {
            head=new;
        }
        else{
            lst->next=new;
        }
        lst=new;
        printf("Do you want to continue(0 0r 1)");
        scanf("%d",&choice);
        while(getchar() != '\n');

    } while (choice!=0);
    

    return head;
}

void display(Student *head)
{
    printf("The Student Data :\n ");
    for(Student *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("Name      : %s\n", temp->name);
        printf("Roll No   : %d\n", temp->rollno);
        printf("Standard  : %s\n", temp->standard);
        printf("Division  : %c\n", temp->division);
    }
}    