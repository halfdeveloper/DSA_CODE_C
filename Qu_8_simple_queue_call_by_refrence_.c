#include<stdio.h>
#include<stdlib.h>
# define max 5
void inqu(int[],int*);//Function Declare for inqueue
void deque(int[],int*,int*);//Function Declare for dequeue
void display(int[],int,int);//Function Declare for display
main()
{
    int ch,f=-1,r=-1,qu[max];//We have array of size max which is define in macro files.
    do//Do while loop for menu driven program
    {
        printf("\nPlease Enter Your choice:\n");
        printf("\n1-Insert\n2-Serve\n3-Display\n4-exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1://Case 1 for insert an element in queue.
            inqu(qu,&r);
            if(f==-1)   /*If queue is initially empty */
                f=0;
            break;
        case 2:
            deque(qu,&f,&r);//function call for dequeue the elements in the queue.
            if(f==-1)
                r=-1;
            break;
        case 3:
            display(qu,f,r);
            break;
        case 4:
            printf("You are out in program\n");
            break;
        }
    }
    while(ch!=4);
}
//Function Defnition for inqeue
void inqu(int qu[],int *r)
{
    int v;
    if((*r)==max-1)
    {
        printf("The Queue Is Full\n");
    }
    else
    {
        printf("Enter the elemnet:\n");
        scanf("%d",&v);
        (*r)++;
        qu[*r]=v;

    }
}
//Function Declare for Dequeue
void deque(int qu[],int *f,int *r)
{
    int x;
    if(*f==-1 && *r==-1)//Condition check for queue is empty.
    {
        printf("The Queue Is Empty:\n");
    }
    else if (*f==*r)//If front or rear is equal so we have to initialize front is =-1.
    {
        x=qu[*f];
        (*f)=-1;
    }
    else
    {
        x=qu[*f];//Deleting the element in queue.
        (*f)++;
    }
    printf("The Deleted Element is:: %d",x);
}
//Function Declare for display the elements of queue
void display(int qu[],int f,int r)
{
    int i;
    if(f==-1 && r==-1)//Condition check for queue is empty.
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The Elements In Queue--:\n");
        for(i=f; i<=r; i++) //printing the elements of queue using for loop.
        {
            printf("%d\t",qu[i]);
        }
    }
}

