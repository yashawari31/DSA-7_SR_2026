#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct singlylinkedlist
{
    int rollno;
    char name[10];
    struct singlylinkedlist *next;
}sll;

sll* create(sll * head);
void display(sll *temp);
void swap(sll *temp);


int main()
{
    sll * start=NULL;
    start=create(start);
   swap(start);
    display(start);
  sll* temp;
  while(start!=NULL)
  {
    temp=start;
    start=start->next;
    free(temp);
  }
    return 0;
}

sll* create(sll * head)
{
    sll* new=NULL;
    sll * lst=NULL;

    int choice;

    do{
        new=(sll*)malloc(sizeof(sll));
        printf("enter the data");
        scanf("%d %s", &new->rollno, new->name);
        new->next=NULL;

        if(head==NULL)
            head=new;
        else
            lst->next=new;

       lst=new;
       printf("do you want to enter new data(1=yes 0=no)");
       scanf("%d",&choice);     
    }while(choice!=0);
    return head;
}

void display(sll *temp)
{
    printf("student data:\n");
    for(;temp!=NULL;temp=temp->next)
    {
        printf("%d \t %s\n",temp->rollno,temp->name);

    }

}

 void swap(sll*temp)
{
  sll*p;
  if(temp==NULL)
  {
    printf("list is empty");
    return;
  }
  p=temp;
  int temp_roll;
  char temp_name[10];

  for(;p!=NULL;p=p->next->next)
  {
    
    if(p->next!=NULL)
    {
        temp_roll = p->rollno;
        p->rollno = p->next->rollno;
        p->next->rollno = temp_roll;

        strcpy(temp_name, p->name);
        strcpy(p->name, p->next->name);
        strcpy(p->next->name, temp_name);
        }
        else
        {
        break;
    }
  }

}