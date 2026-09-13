#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}dll;

dll *create(dll *head);
void display(dll *head);

int main()
{
   dll *start=NULL;

   start=create(start);
   display(start);

   dll *temp;
   while(start!=NULL)
   {
     temp=start;
     start=start->next;
     free(temp);
   }

   return 0;
}

dll *create(dll *head)
{
    dll *nw;
    dll *lst;
    int choice;

    do{
        nw=malloc(sizeof(dll));
        if(nw==NULL)
        {
            printf("Memory Allocation Failed");
            return NULL;
        }
        printf("Enter Data for new node: ");
        scanf("%d",&nw->data);
        nw->next=NULL;
        nw->prev=NULL;
        
        if(head==NULL)
        {
            head=nw;
        }
        else
        {
            lst->next=nw;
            nw->prev=lst;

        }
        lst=nw;

        printf("Node Successfully Inserted\n");
        printf("Do you stil want to continue(0 or 1): ");
        scanf("%d",&choice);
    }while(choice!=0);

    return head;
}

void display(dll *head)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    
    for(dll *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
        if(temp->next!=NULL)
        {
            printf("<->");
        }
    }
}