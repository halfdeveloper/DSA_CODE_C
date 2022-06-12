
/* Developed by - Deepak kumar MCA_51_A.
 Problem Statement - Write a program to implement a single linked list
and linked list should print bottom to top.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int info;
    struct stack *next;
} node;
node *push(node*);
void display(node*);
void displayBT(node*);
node * insertBF(node*);
main()
{
    int ch;
    node*top=NULL;
    do
    {
        printf("\nEnter your choice \n1.push\n2.display\n3.display bottom to top\n4-lft\n5.exit\n");
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
                printf("\nThe original order\n");
                display(top);
                break;
            }
        case 3:
            if(top==NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("\nThe reverse order\n");
                displayBT(top);
                break;
            }
        case 4:
            top=insertBF(top);
            break;

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

void display(node*top)
{
    while(top!=NULL)
    {
        printf(" %d \t",top->info);
        top=top->next;
    }

}
node * insertBF(node*top)
{
    int x;
    node *t=NULL,*p=NULL;
        t=top;
        p= (node*)malloc(sizeof(node));
        if(p==NULL)
        {
            printf("Not enough memory");
        }
        else
        {
            t->next=p;
            t=p;

        }
        return(top);

}
void displayBT(node*top)
{
    if(top->next!=NULL)
    {
        displayBT(top->next);
    }
    printf(" %d \t",top->info);
}
/*****************OUTPUT***********

Enter your choice
1.push
2.display
3.display bottom to top
4.exit
1
Enter the value
12

Enter your choice
1.push
2.display
3.display bottom to top
4.exit
1
Enter the value
13

Enter your choice
1.push
2.display
3.display bottom to top
4.exit
1
Enter the value
14

Enter your choice
1.push
2.display
3.display bottom to top
4.exit
1
Enter the value
15

Enter your choice
1.push
2.display
3.display bottom to top
4.exit
2

The original order
 15      14      13      12
Enter your choice
1.push
2.display
3.display bottom to top
4.exit
3

The reverse order
 12      13      14      15
Enter your choice
1.push
2.display
3.display bottom to top
4.exit
4
Exit
Process returned 0 (0x0)   execution time : 17.699 s
Press any key to continue.
*****************************/
