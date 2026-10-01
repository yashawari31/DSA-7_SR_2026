#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}cdll;

cdll *create_list(cdll *last);
void display(cdll *head);
void destroy_list(cdll *last);
cdll *insert_at_last(cdll *last,int data);
void delete_at_beginning(cdll *last);
cdll *insert_after_key(cdll *last,int key);
void insert_before_key(cdll *last,int key);

int main()
{
    cdll *last=NULL;

    last=create_list(last);
    display(last->next);

   last=insert_at_last(last,55);
   display(last->next);

   delete_at_beginning(last);
   display(last->next);

   last=insert_after_key(last,55);
   display(last->next);

   insert_before_key(last,55);
   display(last->next);

    destroy_list(last);
    last=NULL;

    return 0;
}

cdll *create_list(cdll *last)
{
    cdll *nw;
    int choice;

    do
    {
      nw=malloc(sizeof(cdll));
      printf("Enter data of node: ");
      scanf("%d",&nw->data);
      nw->next=nw;
      nw->prev=nw;
      
      if(last==NULL)
      {
        last=nw;
      }
      else
      {
        nw->next=last->next;
        last->next=nw;
        nw->prev=last;
        last->prev=nw;
      }
      last=nw;

      printf("Do you want to continue: ");
      scanf("%d",&choice);

    } while (choice!=0);
    return last;
}

void display(cdll *head)
{
    if(head==NULL)
    {
        printf("Empty List!\n");
        return;
    }
    cdll *temp=head;
    do
    {
        printf("%d",temp->data);
        if(temp->next!=head)
        {
           printf("->");
        }
        temp=temp->next;
    } while (temp!=head);
    
    printf("\n");
}

void destroy_list(cdll *last)
{
    cdll *head=last->next;
    cdll *temp=head;
    while (head!=last)
    {
        temp=head;
        head=head->next;
        free(temp);
    } 
    free(last);
    

}

cdll *insert_at_last(cdll *last,int data)
{
    if(last==NULL)
    {
        printf("Empty List!\n");
        return NULL;
    }
    
    cdll *nw=malloc(sizeof(cdll));
    if(nw==NULL)
    {
      printf("Memory Allocation Failed!\n");
      return NULL;
    }
    nw->data=data;
    nw->next=last->next;
    last->next->prev=nw;
    last->next=nw;
    nw->prev=last;

    last=nw;
    return nw;
}

void delete_at_beginning(cdll *last)
{
    if(last==NULL)
    {
        printf("Empty List!\n");
        return;
    }
    cdll *head=last->next;
    last->next=head->next;
    head->next->prev=last;
    free(head);
}

cdll *insert_after_key(cdll *last,int key)
{
    if(last==NULL)
    {
        printf("Empty List!\n");
        return;
    }
    if(last->data==key)
    {
        cdll *nw=malloc(sizeof(cdll));
           if(nw==NULL)
          {
            printf("Memory Allocation Failed!\n");
            return;
          }
          printf("Enter data to insert: ");
          scanf("%d",&nw->data);
          nw->next=last->next;
          last->next->prev=nw;
          last->next=nw;
          nw->prev=last;
          last=nw;
          return nw;
    }
    cdll *temp=last->next;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            cdll *nw=malloc(sizeof(cdll));
           if(nw==NULL)
          {
            printf("Memory Allocation Failed!\n");
            return;
          }
          printf("Enter data to insert: ");
          scanf("%d",&nw->data);
          nw->next=temp->next;
          temp->next->prev=nw;
          temp->next=nw;
          nw->prev=temp;
          return last;
        }
        temp=temp->next;
    }
    printf("Key node not found!\n");
    return last;
}

void insert_before_key(cdll *last,int key)
{
    if(last==NULL)
    {
        printf("Empty List!\n");
        return;
    }
    if(last->data==key)
    {
        cdll *nw=malloc(sizeof(cdll));
           if(nw==NULL)
          {
            printf("Memory Allocation Failed!\n");
            return;
          }
          printf("Enter data to insert: ");
          scanf("%d",&nw->data);
          nw->next=last;
          last->prev->next=nw;
          nw->prev=last->prev;
          last->prev=nw;
          return;
    }
    cdll *temp=last->next;
    while(temp!=last)
    {
        if(temp->data==key)
        {
            cdll *nw=malloc(sizeof(cdll));
           if(nw==NULL)
          {
            printf("Memory Allocation Failed!\n");
            return;
          }
          printf("Enter data to insert: ");
          scanf("%d",&nw->data);
          nw->next=temp;
          temp->prev->next=nw;
          nw->prev=temp->prev;
          temp->prev=nw;
          return;
        }
        temp=temp->next;
    }
    printf("Key not found!\n");
    return;
}