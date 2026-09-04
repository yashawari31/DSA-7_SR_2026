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
sll*  appendList(sll*head1,sll*head2);


int main()
{
    sll * start1=NULL;
    start1=create(start1);
    printf("The First Linked List:\n");
    display(start1);

    sll * start2=NULL;
    start2=create(start2);
    printf("The Second Linked List:\n");
    display(start2);

    appendList(start1,start2);
    printf("The first List after concat:\n");
    display(start1);

  sll* temp;
  while(start1!=NULL)
  {
    temp=start1;
    start1=start1->next;
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

 sll*  appendList(sll*head1,sll*head2)
 {
    if(head1==NULL)
    {
        printf("First list is empty\n");
        return head1;
    }
    if(head2==NULL)
    {
        printf("Second list is empty\n");
        return head1;
    }
    sll *temp=head1;
    sll *last;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
           last=temp;
        }
        temp=temp->next;
    }

    last->next=head2;

    return head1;
 }