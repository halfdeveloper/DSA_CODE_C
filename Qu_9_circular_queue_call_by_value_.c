//PROBLEM STATEMENT_9-: WRITE A C PROGRAM TO IMPLEMENT CIRCULAR QUEUE USING CALL BY VALUE WITH ARRAY (STATIC MEMORY ALLCATIONS).
//NAME__DEEPAK KUMAR COURSE__MCA_A_51.
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define max 5
int enqu(int[],int,int);
int deque(int[],int,int);
void display(int[],int,int);
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
            r=enqu(qu,r,f);
            if(f==-1)
            {
                f=0;
            }
            break;
        case 2:
            f=deque(qu,f,r);
            if(f==-1)
                r=-1;
            break;
        case 3:
            display(qu,f,r);
            break;
        case 4:
            printf("\nYou are out of the program");
            break;

        }
    }
    while(ch!=4);
}

int enqu(int qu[],int r,int f)
{
    int x;
    if((r+1)%max==f)
    {
        printf("The queue is full\n");
    }
    else
    {

        printf("Enter the element which want to be inserted in queue\n");
        scanf("%d",&x);
        r=(r+1)%max;
        qu[r]=x;
    }
    return r;
}
int deque(int qu[],int f,int r)
{
    int x;
    if(f==-1 && r==-1)
    {
        printf("\nThe Queue is empty\n");
    }
    else if(f==r)
    {
        x=qu[f];
        printf("The delete element is :-> %d",x);
        f=-1;
    }
    else if(f==max-1 && r>=0)
    {
        x=qu[f];
        printf("The poped element is :->  %d",x);
        f=0;
    }
    else
    {
        x=qu[f];
        f=(f+1)%max;
        printf("The delete element is :-> %d",x);
    }
    return f;
}
void display(int qu[],int f,int r)
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
