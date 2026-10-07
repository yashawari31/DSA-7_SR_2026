#include<stdio.h>
#include<stdbool.h>
#define MAX 5

void push(int data);
void pop();
void peek();
void displayStack();
bool isEmpty();
bool isFull();

int stk[MAX];
int top;

int main()
{
    top=-1;

    push(10);
    push(20);
    push(30);
    peek();
    push(40);
    push(50);
    push(11);
    displayStack();

    pop();
    pop();
    pop();
    pop();

    peek();
    pop();
    displayStack();

    return 0;
}

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if(top==MAX-1)
    {
        return true;
    }
    return false;
}

void push(int data)
{
    if(isFull())
    {
        printf("Stack is FULL\n");
    }
    else{
        top++;
        stk[top]=data;
        printf("Push Operation Successful\n");
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else{
        top--;
        printf("Pop Operation Successful\n");
    }
}
void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("The Top Element of Stack: %d\n",stk[top]);
    }
}
void displayStack()
{
     if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack Elements:\n");
        for(int i=top;i>=-0;i--)
        {
            printf("%d  |\n",stk[i]);
            printf("____\n");
        }
    }
}