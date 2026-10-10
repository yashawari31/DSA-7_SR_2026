#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}Stack;


Stack* push(int data,Stack *top);
Stack* pop(Stack *top);
void display(Stack *top);
bool isEmpty(Stack *top);
void peek(Stack *top);

int main()
{
    Stack *top=NULL;
   top=push(10,top);
   top=push(20,top);
   top=push(30,top);
   peek(top);
   top=push(40,top);
   top=push(50,top);
   display(top);

   top=pop(top);
   top=pop(top);
   top=pop(top);
   top=pop(top);
   peek(top);
   top=pop(top);
   display(top);
}

Stack* push(int data,Stack *top)
{
    Stack *new=malloc(sizeof(Stack));
    new->data=data;
    new->next=top;

    top=new;
    printf("Push Operation Successful\n");

    return top;
}

bool isEmpty(Stack *top)
{
    if(top==NULL)
    {
        return true;
    }
    
    return false;
}

Stack* pop(Stack *top)
{
   if(isEmpty(top))
   {
     printf("Stack Is Empty\n");
   }
   else
   {
     Stack *del=top;
     top=top->next;
     free(del);
     printf("Pop Operation Successful\n"); 
   }

   return top;
}

void peek(Stack *top)
{
    if(isEmpty(top))
   {
     printf("Stack Is Empty\n");
   }
   else
   {
     printf("Top Element: %d\n", top->data);
   }
}

void display(Stack *top)
{
    if(isEmpty(top))
   {
     printf("Stack Is Empty\n");
   }
   else{
    Stack *temp=top;
    printf("Stack Elements:\n");
    while(temp!=NULL)
    {
        printf("%d  |\n",temp->data);
        printf("____\n");
        temp=temp->next;
    }
   }
}

