#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}dll;

dll *insert_at_head(dll *head);
void display(dll *head);
dll* middleNode(dll *head);

int main()
{
   dll *start=NULL;

   start=insert_at_head(start);
   start=insert_at_head(start);
   start=insert_at_head(start);
   

   display(start);
  printf("\nThe middle node data is:%d\n",middleNode(start)->data);
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

dll* middleNode(dll *head)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return head;
    }
    dll *slow=head;
    dll *fast=head;

    while(fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}