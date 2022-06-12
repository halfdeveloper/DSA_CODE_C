//PROBLEM STATEMENT_9-: WRITE A C PROGRAM TO IMPLEMENT CIRCULAR QUEUE USING CALL BY REFRENCE WITH ARRAY (STATIC MEMORY ALLCATIONS).
//NAME__DEEPAK KUMAR COURSE__MCA_A_51.
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqu(int[],int*,int*);//Declaring Function for Enqu with three arguments.
void deque(int[],int*,int*);//Declaring Function for Dequ with three arguments.
void display(int[],int,int);//Declaring Function for Display.
main()
{
    int qu[max],ch,f=-1,r=-1;
    do
    {
        printf("\nEnter your choice:\n");
        printf("\n1.Enqueue\n2.dequeue\n3.display\n4.exit:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            enqu(qu,&r,&f);//function call for insert the elements in the queue.
            if(f==-1)
            {
                f=0;
            }
            break;
        case 2:
            deque(qu,&f,&r);//function call for delete the elements.
            if(f==-1)
                r=-1;
            break;
        case 3:
            display(qu,f,r);//for display call
            break;
        case 4:
            printf("\nYou are out of the program");
            break;

        }
    }
    while(ch!=4);//End of do while loop.
}

void enqu(int qu[],int *r,int *f)//function definition .
{
    int x;
    if((*r+1)%max==*f)//condition check for queue is full.
    {
        printf("The queue is full\n");
    }
    else//insert the element in the queue.
    {

        printf("Enter the element which want to be inserted in queue\n");
        scanf("%d",&x);
        *r=(*r+1)%max;
        qu[*r]=x;
    }
}
void deque(int qu[],int *f,int *r)//function definition for dequeu.
{
    int x;
    if(*f==-1 && *r==-1)//condition check for queue is empty .
    {
        printf("\nThe Queue is empty\n");
    }
    else if(*f==*r)//check for front and rear are equal.
    {
        x=qu[*f];
        printf("The delete element is :-> %d",x);
        *f=-1;
    }
    else if(*f==max-1 && *r>=0)
    {
        x=qu[*f];//serve the element.
        printf("The poped element is :->  %d",x);
        *f=0;
    }
    else
    {
        x=qu[*f];
        *f=(*f+1)%max;
        printf("The delete element is :-> %d",x);
    }
}
void display(int qu[],int f,int r)//function definition for display the elements.
{
    if(f==-1 && r==-1)
    {
        printf("\nThe Queue is empty\n");
    }
    else
    {
        int i=f;
        printf("the elements are\n");
        while(i!=r)
        {
            printf("%d\t",qu[i]);
            i=(i+1)%max;
        }
        printf("%d\t",qu[i]);
    }

}
/***************OUTPUT************

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
1
Enter the element which want to be inserted in queue
41

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
1
Enter the element which want to be inserted in queue
42

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
1
Enter the element which want to be inserted in queue
43

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
1
Enter the element which want to be inserted in queue
45

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
1
Enter the element which want to be inserted in queue
46

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
1
The queue is full

Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
3
the elements are
41      42      43      45      46
Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
2
The delete element is :-> 41
Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
3
the elements are
42      43      45      46
Enter your choice:

1.Enqueue
2.dequeue
3.display
4.exit:
4

You are out of the program
Process returned 0 (0x0)   execution time : 23.356 s
Press any key to continue.
*************************/
