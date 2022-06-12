#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int info;
    struct stack *next;
}node;
void push(node**);
void pop(node**);
void display(node**);
main()
{
    int ch;
    node*top=NULL;
    do
    {
        printf("\nEnter your choice \n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push(&top);
            break;
        case 2:
            if(top==NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                pop(&top);
                break;
            }
        case 3:
            if(top==NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                display(&top);
                break;
            }
        case 4:
            printf("Exit");
            break;

        }

    }
    while(ch!=4);
}
void push(node**top)
{
    int x;
    node*p=NULL;
    printf("Enter the value\n");
    scanf("%d",&x);
    p=(node**)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Not enough Memory\n");
    }
    else
    {
        p->info=x;
        p->next=(*top);
        (*top)=p;
    }
}
void pop(node**top)
{
    node*p=NULL;
    p=(*top);
    printf("The poped element is  :->   %d",(*top)->info);
    (*top)=(*top)->next;
    free(p);
}
void display(node**top)
{
    while(top!=NULL)
    {
        printf("%d\t",(*top)->info);
        (*top)=(*top)->next;
    }
}
