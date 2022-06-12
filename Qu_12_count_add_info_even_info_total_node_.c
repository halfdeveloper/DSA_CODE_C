#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int info;
    struct list *next;
} node;
main()
{
    int ch,x;
    node*p=NULL,*r=NULL,*l=NULL;
    while(1)
    {
        printf("Enter the number\n");
        scanf("%d",&x);
        p=(node*)malloc(sizeof(node));
        p->info=x;
        if(l==NULL && r==NULL)
        {
            l=r=p;
        }
        else
        {
            r->next=p;
            r=p;
        }
        r->next=NULL;
        printf("Do you Want to be continue 0/1\n");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    //count the nodes in linked list.
    int count=0;
    while(l!=NULL)
    {
        if((p->info)%2==0)
        count++;
        l= l->next;
    }
    printf("The total number of even %d  \n",count);
}



