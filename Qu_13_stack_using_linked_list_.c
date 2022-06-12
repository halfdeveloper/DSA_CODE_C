#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int info;
    struct stack *next;
} node;
node *push(node*);
node *pop(node*);
void display(node*);
void displayBT(node*);
main()
{
    int ch;
    node*top=NULL;
    do
    {
        printf("\nEnter your choice \n1.push\n2.pop\n3.display\n4.display bottom to top\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            top=push(top);
            break;
        case 2:
            if(top==NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                top=pop(top);
                break;
            }
        case 3:
            if(top==NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                display(top);
                break;
            }
        case 4:
            if(top==NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                displayBT(top);
                break;
            }

        case 5:
            printf("Exit");
            break;

        }

    }
    while(ch!=4);
}
node*push(node*top)
{
    int x;
    node*p=NULL;
    printf("Enter the value\n");
    scanf("%d",&x);
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("The stack is overflow\n");

    }
    else
    {
        p->info=x;
        p->next=top;
        top=p;
    }
    return(top);
}
node*pop(node*top)
{
    node*p=NULL;
    p=top;
    printf("The poped element is  :->   %d",top->info);
    top=top->next;
    free(p);
    return(top);
}
void display(node*top)
{
    while(top!=NULL)
    {
        printf(" %d \t",top->info);
        top=top->next;
    }
}
void displayBT(node*top)
{
    if(top->next!=NULL)
    {
        displayBT(top->next);
    }
    printf(" %d \t",top->info);
}
