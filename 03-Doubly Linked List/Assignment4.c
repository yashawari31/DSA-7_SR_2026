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
dll *insert_at_pos(dll *head,int pos);
void *insert_at_end(dll *head);
void display(dll *head);

int main()
{
   dll *start=NULL;

   start=insert_at_head(start);
   start=insert_at_head(start);
   start=insert_at_head(start);
   
   start=insert_at_pos(start,5);
   display(start);

   printf("\ndata after deleting a head node:\n");
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

void *insert_at_end(dll *head)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    dll *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    dll *nw=malloc(sizeof(dll));
    if(nw==NULL)
    {
        printf("Memory Allocation Failed");
        return head;
    }
    nw->next=NULL;
    nw->prev=NULL;
    printf("\nEnter data for last node: ");
    scanf("%d",&nw->data);
    
    temp->next=nw;
    nw->prev=temp;
    nw->next=NULL;

    
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

dll *insert_at_pos(dll *head,int pos)
{
    if(pos<1)
    {
        printf("Invalid Position\n");
        return head;
    }
    if(pos!=1 && head==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    if(pos==1)
    {
        head=insert_at_head(head);
        return head;
    }
    dll *temp=head;
    int i=1;
    while(temp!=NULL)
    {
        if(i==pos)
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

            nw->next=temp;
            nw->prev=temp->prev;
            temp->prev->next=nw;
            temp->prev=nw;

            return head;

        }
        i++;
        temp=temp->next;
    }
    if(i==pos)
    {
       insert_at_end(head);
       return head;
        
    }
    printf("Position not found\n");
    return head;

}