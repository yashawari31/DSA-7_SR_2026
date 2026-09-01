#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct singlylinkedlist
{
    int rollno;
    char name[20];
    struct singlylinkedlist *next;
}sll;

sll* create(sll * head);
void display(sll *temp);
void add_consecutive_nodes(sll *temp);


int main()
{
    sll * start=NULL;
    start=create(start);
    display(start);
    add_consecutive_nodes(start);
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

 
void add_consecutive_nodes(sll *head)
{
    sll *p = head;
    sll *new=NULL;

    if(head==NULL)
    {
        printf("empty list");
        return;
    }

    for(;p != NULL && p->next != NULL;p=new->next)
    {
        sll *q = p->next;

        new = (sll *)malloc(sizeof(sll));
        if (new == NULL)
            return;

        new->rollno = p->rollno + q->rollno;

        strcpy(new->name, p->name);
        strcat(new->name, q->name);

        new->next = q->next;
        q->next = new;

    }
}