//Problem Statement : Write a program simple queue using double pointer using linked list .
//Developed by Deepak_Kumar_MCA_A_51.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;
void  insert(node**);
void serve (node**);
void display(node**,node**);
main()
{
    int ch;
    node *f=NULL,*r=NULL;
    do
    {
        printf("\nEnter your choice --->\n");
        printf("1-insert\n2-serve\n3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert(&r);
            if(f==NULL)
                f=r;
            break;
        case 2:
            serve(&f);
            if(f==NULL)
                r==NULL;
            break;
        case 3:
            display(f,r);
            break;

        }

    }
    while(ch!=3);
}
void insert(node **r)
{
    int x;
    node*p=NULL;
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Not Enough memory");
    }
    else
    {
        printf("Enter the value in Queue-->\n");
        scanf("%d",&x);
        p->info=x;
        p->next=NULL;
    }
    if((*r)==NULL)
    {
        (*r)=p;
    }
    else
    {
        (*r)->next=p;
        (*r)=p;
    }
}

void serve(node **f)
{
    if((*f)==NULL)
    {
        printf("------The Queue is Empty------\n");
    }
    else
    {
        printf("The serve element is -->> %d",(*f)->info);
        *f=(*f)->next;
    }
    free(f);
}
void display(node**f,node**r)
{
    node*temp=f;
    if(*f==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->next;
        }
        printf("%d\t",temp->info);
    }
}
/*************OUTPUT***********

Enter your choice --->
1-insert
2-serve
3-display
1
Enter the value in Queue-->
5

Enter your choice --->
1-insert
2-serve
3-display
1
Enter the value in Queue-->
6

Enter your choice --->
1-insert
2-serve
3-display
1
Enter the value in Queue-->
7

Enter your choice --->
1-insert
2-serve
3-display
1
Enter the value in Queue-->
8

Enter your choice --->
1-insert
2-serve
3-display
2
The serve element is -->> 5
Enter your choice --->
1-insert
2-serve
3-display
3
6       7       8
Process returned 0 (0x0)   execution time : 14.638 s
Press any key to continue.*************/
