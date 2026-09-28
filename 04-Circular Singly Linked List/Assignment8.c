#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} csll;

// Function declarations
csll *create_list(csll *last);
void insert_at_beginning(csll *last,int data);
void delete_at_beginning(csll *last);
void display(csll *last);

int main()
{
    csll *last = NULL;
    int choice;

    do
    {
        printf("\n===== CIRCULAR SINGLY LINKED LIST =====\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                last = create_list(last);
                break;

            case 2:
            {
                int data;
                printf("Enter data to enter: ");
                scanf("%d",&data);
                insert_at_beginning(last,data);
                break;
            }

            case 3:
                delete_at_beginning(last);
                break;

            case 4:
                display(last->next);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

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

csll *delete_at_last(csll *last)
{
    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    csll *temp=last->next;
    while(temp->next!=last)
    {
        temp=temp->next;
    }
    temp->next=last->next;
    free(last);

    return temp;
}