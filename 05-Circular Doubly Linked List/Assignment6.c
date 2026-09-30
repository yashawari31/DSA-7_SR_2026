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
void insert_at_beginning(cdll *last,int data);
cdll *delete_key(cdll *last,int key);

int main()
{
    cdll *last=NULL;

    last=create_list(last);
    display(last->next);

    insert_at_beginning(last,25);
    display(last->next);

    last=delete_key(last,38);
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

void insert_at_beginning(cdll *last,int data)
{
    if(last==NULL)
    {
        printf("Empty List!\n");
        return;
    }
    
    cdll *nw=malloc(sizeof(cdll));
    if(nw==NULL)
    {
      printf("Memory Allocation Failed!\n");
      return;
    }
    nw->data=data;
    nw->next=last->next;
    last->next->prev=nw;
    last->next=nw;
    nw->prev=last;

}

cdll *delete_key(cdll *last,int key)
{
    if(last==NULL)
    {
        printf("Empty List!\n");
        return;
    }
    if(last->data==key)
    {
        cdll *del=last;
        last=last->prev;
        last->next=del->next;
        del->next->prev=last;
        free(del);
        return last;

    }
    cdll *temp=last->next;
    while(temp!=last)
    {
        if(temp->data==key)
        {
            cdll *del=temp;
            temp=temp->prev;
            temp->next=del->next;
            del->next->prev=temp;
            free(del);
            return last;
        }
        temp=temp->prev;
    }

    printf("Key not found!\n");
    return last;
}