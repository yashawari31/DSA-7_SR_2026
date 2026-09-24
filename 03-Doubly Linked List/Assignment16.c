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
void reverseDisplay(dll *head);
void swap_pairs(dll *head);

int main()
{
   dll *start=NULL;

   start=create(start);
   display(start);
   swap_pairs(start);
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
    printf("Linked List Data:\n");
    for(dll *temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
        if(temp->next!=NULL)
        {
            printf("<->");
        }
    }
}

void reverseDisplay(dll *head)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }

    printf("Linked List Data in Reverse Order: \n");
    dll *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
       printf(" %d ",temp->data);
       if(temp->prev!=NULL)
        {
            printf("<->");
        }
        temp=temp->prev;
    }
}

void swap_pairs(dll *head)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    dll *temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if((temp->data)>(temp->next->data))
        {
            int swap=temp->data;
            temp->data=temp->next->data;
            temp->next->data=swap;
        }
        
            temp=temp->next->next;
        
    }
}