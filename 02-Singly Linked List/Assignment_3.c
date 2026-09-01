#include<stdio.h>
#include<stdlib.h>

typedef struct singlylinkedlist
{
    int rollno;
    char name[10];
    struct singlylinkedlist *next;
}sll;

sll* create(sll * head);
void alternate_display(sll *temp);


int main()
{
    sll * start=NULL;
    start=create(start);

    alternate_display(start);
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

void alternate_display(sll *temp)
{
    printf("student data:\n");
    for(;temp!=NULL;temp=temp->next->next)
    {
        printf("%d \t %s\n",temp->rollno,temp->name);
        if(temp->next==NULL)
        {
            break;
        }
    }

}