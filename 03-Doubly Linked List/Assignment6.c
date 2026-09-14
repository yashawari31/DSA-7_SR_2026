#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}dll;

dll *insert_at_head(dll *head);
dll  *delete_at_head(dll *head);
void display(dll *head);

int main()
{
   dll *start=NULL;

   start=insert_at_head(start);
   start=insert_at_head(start);
   start=insert_at_head(start);
   

   display(start);

   printf("data after deleting a head node:\n");
   start=delete_at_head(start);
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

dll *insert_at_head(dll *head)
{
    dll *nw=malloc(sizeof(dll));
    if(nw==NULL)
    {
        printf("Memory Allocation Failed");
        return head;
    }
    nw->next=NULL;
    nw->prev=NULL;
    printf("Enter node data: ");
    scanf("%d",&nw->data);

    if(head==NULL)
    {
        head=nw;
    }
    else{
        nw->next=head;
        head->prev=nw;
        head=nw;
    }
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

dll  *delete_at_head(dll *head)
{
    if(head==NULL)
    {
        printf("Empty List!");
        return head;
    }

    dll *temp=head;
    head=head->next;
    free(temp);

    return head;
}