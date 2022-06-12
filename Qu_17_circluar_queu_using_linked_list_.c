//Problem Statement : Write a program simple queue using double pointer using linked list .
//Developed by Deepak_Kumar_MCA_A_51
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;
void insert(node**,node**);
void serve(node**,node**);
void display(node*,node*);
main()
{
    int ch;
    node *f=NULL,*r=NULL;
    do
    {
        printf("\nEnter your choice:\n");
        printf("\n1.Insert\n2.Serve\n3.display\n4.exit:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert(&r,&f);
            if(f==NULL)
                f=r;
            break;
        case 2:
            serve(&f,&r);
            break;
        case 3:
            display(f,r);
            break;
        case 4:
            printf("Exit");
            break;
        }

    }while(ch!=4);
}
void insert(node**r,node**f)
{
    int x;
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Not Eno*ugh Memory\n");
    }
    else
    {
        printf("Enter the value of queue\n");
        scanf("%d",&x);
        p->info=x;
        p->next=NULL;
    }
    if(*r==NULL)
    {
        *r=p;
    }
    else
    {
        (*r)->next=p;
        (*r)=p;
    }
}
void serve(node**f,node**r)
{
    node *temp=*f;
    if(*f==NULL)
    {
        printf("Queue is empty");
    }
    else if(*f==*r)
    {
        printf("The last element is -->> %d",(*f)->info);
        *f=NULL;
        *r=NULL;
    }
    else
    {
       printf("The serve element is -->> %d",temp->info);
        (*f)=(*f)->next;
        (*r)->next=(*f);
    }
    free(temp);
}
void display(node*f,node*r)
{
    node*temp=f;
    if(f==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        do
        {
            printf("%d\t",temp->info);
            temp=temp->next;

        }while(temp!=f);
    }
}
/*************OUTPUT****

Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
1
Enter the value of queue
1

Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
1
Enter the value of queue
2

Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
1
Enter the value of queue
3

Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
1
Enter the value of queue
4

Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
1
Enter the value of queue
5

Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
2
The serve element is -->> 1
Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
2
The serve element is -->> 2
Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
3
3       4       5
Enter your choice:

1.Insert
2.Serve
3.display
4.exit:
4
Exit
Process returned 0 (0x0)   execution time : 12.871 s
Press any key to continue.
****************/
