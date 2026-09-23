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
void insert_after(dll *head,int key);
dll *insert_before(dll *head,int key);
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

   start=insert_before(start,19);
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
    printf("\n");
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

void insert_after(dll *head,int key)
{
     if(head==NULL)
    {
        printf("Empty List!");
        return;
    }
    dll *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            dll *nw=malloc(sizeof(dll));
            if(nw==NULL)
            {
                printf("Memory Allocation Failed\n");
                return;
            }
            printf("Enter the data for new node: ");
            scanf("%d",&nw->data);

            nw->next=temp->next;
            nw->prev=temp;
            temp->next=nw;
            if(temp->next!=NULL)
            {
                temp->next->prev=nw;
            }
            printf("Node added after %d\n",key);
            return;
        }
        temp=temp->next;
    }
    printf("Key not found!\n Data not inserted\n");
    return;
}

dll *insert_before(dll *head,int key)
{
    if(head==NULL)
    {
        printf("Empty List!");
        return;
    }
    if(head->data==key)
    {
        dll *nw=malloc(sizeof(dll));
        if(nw==NULL)
            {
                printf("Memory Allocation Failed\n");
                return;
            }
            printf("Enter the data for new node: ");
            scanf("%d",&nw->data);
            nw->next=head;
            head->prev=nw;
            head=nw;
            printf("Node added before %d\n",key);
            return head;
    }
    dll *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            dll *nw=malloc(sizeof(dll));
            if(nw==NULL)
            {
                printf("Memory Allocation Failed\n");
                return;
            }
            printf("Enter the data for new node: ");
            scanf("%d",&nw->data);
            temp->prev->next=nw;
            nw->prev=temp->prev;
            nw->next=temp;
            temp->prev=nw;
            printf("Node added before %d\n",key);
            return head;

        }
        temp=temp->next;
    }
    printf("Key not found!\n Data not inserted\n");
    return head;

}