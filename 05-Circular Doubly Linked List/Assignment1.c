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

int main()
{
    cdll *last=NULL;

    last=create_list(last);
    display(last->next);

    destroy_list(last);
    last=NULL;
    display(last);

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
    
}

void destroy_list(cdll *last)
{
    cdll *head=last->next;
    cdll *temp=head;
    while (temp!=last)
    {
        temp=head;
        head=head->next;
        free(temp);
    } 
    free(last);
    

}