
//PROBLEM STATEMENT_2::WRITE A C PROGRAM TO IMPLEMENT SATCK USING ARRAY (CALL BY VLAUE).
//NAME__DEEPAK KUMAR COURSE__MCA_A_51.
#include<stdio.h>
#include<stdlib.h>
# define max 10
int push(int[],int,int);
int pop(int[],int);
void display(int[],int);
void peek(int[],int);
main()
{
    int stack[max],top=-1,ch,v;
    do
    {
        printf("\nThe choice are :: \n 1_push\n 2_pop\n 3_display\n 4_peek\n");
        printf("Please Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element which want to be push::\n");
            scanf("%d",&v);
            top=push(stack,top,v);
            break;
        case 2:
            top=pop(stack,top);
            break;
        case 3:
            display(stack,top);
            break;
        case 4:
            peek(stack,top);
            break;

        }

    }
    while(ch!=4);
}
//code for push a element into the stack
int push(int stack[],int top,int v)
{
    if(top==max-1)
    {
        printf("The stack is overflow or full\n");
    }
    else
    {
        top++;
        stack[top]=v;//here we push the value in stack.
    }
    return top;
}
//code for pop the element from the stack.
int pop(int stack[],int top)
{
    int x;
    if(top==-1)
    {
        printf("The stack is empty\n");

    }
    else
    {
        x=stack[top];
        printf("The poped element is %d",x);
        top--;
    }
    return top;
}
//code for display the elements.
void display(int stack[],int top)
{
    int i;
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}
// code for show the peek element from the stack.
void peek(int stack[],int top)
{
    int x;
    if(top==-1)
    {
        printf("The stack is empty\n");

    }
    else
    {
    x=stack[top];
    printf("The peek element is %d",x);
    }
}
/*************OUTPUT*************
The choice are ::
 1_push
 2_pop
 3_display
 4_peek
Please Enter your choice
1
Enter the element which want to be push::
45

The choice are ::
 1_push
 2_pop
 3_display
 4_peek
Please Enter your choice
1
Enter the element which want to be push::
25

The choice are ::
 1_push
 2_pop
 3_display
 4_peek
Please Enter your choice
1
Enter the element which want to be push::
56

The choice are ::
 1_push
 2_pop
 3_display
 4_peek
Please Enter your choice
3
56      25      45
The choice are ::
 1_push
 2_pop
 3_display
 4_peek
Please Enter your choice
2
The poped element is 56
The choice are ::
 1_push
 2_pop
 3_display
 4_peek
Please Enter your choice
4
The peek element is 25
Process returned 0 (0x0)   execution time : 33.942 s
Press any key to continue.
*************************/
