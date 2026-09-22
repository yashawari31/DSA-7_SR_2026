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
dll *delete_key(dll *head,int key);

int main()
{
   dll *start=NULL;

  int n;
  printf("Enter number of nodes to insert from head:\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    start=insert_at_head(start);
  }

   display(start);

   int key;
   printf("\nEnter the element to delete: ");
   scanf("%d",&key);
   start=delete_key(start,key);
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

dll *delete_key(dll *head,int key)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return head;
    }
    if(head->data==key)
    {
        printf("Key found and deleted!\n");
        dll *temp=head;
       head=head->next;
        free(temp);

       return head;
    }
    dll *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("Key found and deleted!\n");
            temp->prev->next=temp->next;
            if(temp->next!=NULL)
            {
                temp->next->prev=temp->prev;
            }
            free(temp);
            return head;
            
        }
        temp=temp->next;
    }
    printf("Element not found!");
    return head;
}