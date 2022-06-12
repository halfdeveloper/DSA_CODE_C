#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int info;
    struct list *next;
} node;
main()
{
    int x,ch;
    node *p=NULL,*r=NULL,*l=NULL;
    while(1)
    {
        printf("Enter the value which want to be insert:->\n");
        scanf("%d",&x);
        p=(node*)malloc(sizeof(node));
        p->info=x;
        if(l==NULL && r==NULL)
        {
            l=r=p;
            p->next=NULL;
        }
        else
        {
            r->next=p;
            r=p;
            p->next=NULL;
        }

        printf("Do you Want to be continue 0/1\n");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }
    while(l!=NULL)
    {
        printf("%d\t",l->info);
        l=l->next;
    }
}
