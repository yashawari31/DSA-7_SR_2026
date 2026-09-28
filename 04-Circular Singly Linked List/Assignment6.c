#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}csll;

csll* create_list(csll *start);
void display(csll *start);
void insert_at_beginning(csll *last,int data);
csll *insert_at_last(csll *last,int data);
void delete_at_beginning(csll *last);
csll *delete_key(csll *last,int key);

int main()
{
    csll *last;

    last=create_list(last);

    printf("the data in csll is:\n");
    display(last->next);

    insert_at_beginning(last,10);
    insert_at_beginning(last,20);
    last=insert_at_last(last,90);
    printf("the data in csll is:\n");
    display(last->next);

    last=delete_key(last,90);
    printf("the data in csll is:\n");
    display(last->next);

    csll *temp=last->next;
    while(temp!=last)
    {
        csll *del=temp;
        temp=temp->next;
        free(del);
    }
   free(last);
   last=NULL;
    return 0;
}

csll* create_list(csll *start)
{
    int choice;
    csll *new;
    csll *lst=NULL;

    do{
        new=malloc(sizeof(csll));
        if(new == NULL)
        {
             printf("Memory allocation failed\n");
             return start;
        }
        printf("enter the data:\n");
        scanf("%d",&new->data);
        new->next=new;
        if(start==NULL)
        {
            start=new;
        }
        else{
            new->next=lst->next;
            lst->next=new;
        }

        lst=new;

        printf("enter 1 if you want to continue else type 0:\n");
        scanf("%d",&choice);
    }while(choice!=0);

    return lst;
}

void display(csll *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    csll *temp = start;

    printf("The data in CSLL:\n");

    do
    {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp!=start)
           printf("->");
    }
    while(temp != start);

    printf("\n");
}

void insert_at_beginning(csll *last,int data)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    csll *nw=malloc(sizeof(csll));
    if(nw==NULL)
    {
        printf("Memory allocation failed\n");
         return; 
    }
    nw->data=data;
    nw->next=last->next;
    last->next=nw;
    
    

}

csll *insert_at_last(csll *last,int data)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    csll *nw=malloc(sizeof(csll));
    if(nw==NULL)
    {
        printf("Memory allocation failed\n");
         return; 
    }
    nw->data=data;
    nw->next=last->next;
    last->next=nw;
    last=nw;

    return last;
}
void delete_at_beginning(csll *last)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    csll *temp=last->next;
    last->next=temp->next;
    free(temp);
}

csll *delete_key(csll *last,int key)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    csll *temp=last->next;
    while(temp->next!=last)
    {
        if(temp->next->data==key)
        {
            temp->next=temp->next->next;
            free(temp->next);
            return last;
        }
        temp=temp->next;
    }
    if(temp->next==last && last->data==key)
    {
        temp->next=last->next;
        free(last);
        return temp;
    }
    printf("Key Not Found\n");
    return last;
    
}