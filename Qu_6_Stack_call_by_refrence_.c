//PROBLEM STATEMENT_1-: WRITE A C PROGRAM TO IMPLEMENT SATCK USING CALL BY REFRENCE WITH ARRAY (STATIC MEMORY ALLCATIONS).
//NAME__DEEPAK KUMAR COURSE__MCA_A_51.
#include<stdio.h>
#include<stdlib.h>
#define max 5
void push(int[],int*);//Declaring Function for push with two arguments.
void pop(int[],int*);//Declaring Function for pop with two arguments and return type void.
void display(int[],int);//Declaring Function for pop with two arguments and return type void.
main()
{
        int stack[max],v;//stack is an array size of max which is define in macro header file.
        int top=-1,ch;//top is an variable which  initialize with -1 which means stack is empty.
            do
                {
                    printf("\nEnter your choice \n1.push\n2.pop\n3.display\n4.exit\n");
                    scanf("%d",&ch);
                    fflush(stdin);
                        switch(ch)
                                {
                                case 1:
                                    push(stack,&top);//calling of function push using call by refrence
                                    break;
                                case 2:
                                    pop(stack,&top);//calling of function pop using call by refrence
                                    break;
                                case 3:
                                    display(stack,top);//calling of function display
                                    break;
                                case 4:
                                    printf("\nYou are outside the program\n");
                                    break;
                                }
                }while(ch!=4);//End of while loop.
}
//Definition of push Function.
void push(int stack[],int *top)
{
        if(top==max-1)//check the condition of overflow.
            {
                printf("The stack is overflow\n");
            }
        else
            {
                printf("\n Enter the value in push:\n");
                (*top)++;//top incremented by one using pointer.
                scanf("%d",&stack[*top]);//store the element in stack .
            }
}
//Definition of pop Function.
void pop(int stack[],int *top)
{
        if(top==-1)//condition for checking for underflow in stack.
            {
                printf("The stack is empty\n");

            }
        else
            {
                printf("The delete element is %d",stack[*top]);//get the deleted element.
                (*top)--;//top decremented   by one using pointer.
            }
}
//Definition of display Function.
void display(int stack[],int top)
{
        int i=0;
            if(top==-1)//condition for checking for underflow in stack.
                {
                    printf("The stack is empty\n");
                }
            else
                {
                for(i=top; i>=0; i--)//for loop for print the elements of the stack which is store.
                    {
                        printf("%d\t",stack[i]);
                    }
                }
}
/***************OUTPUT*********

Enter your choice
1.push
2.pop
3.display
4.exit
1

 Enter the value in push:
45

Enter your choice
1.push
2.pop
3.display
4.exit
1

 Enter the value in push:
46

Enter your choice
1.push
2.pop
3.display
4.exit
3
46      45
Enter your choice
1.push
2.pop
3.display
4.exit
2
The poped element is 46
Enter your choice
1.push
2.pop
3.display
4.exit
4

You are outside the program
Process returned 0 (0x0)   execution time : 8.417 s
Press any key to continue.
*******************/
