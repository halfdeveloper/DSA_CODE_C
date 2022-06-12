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
    node*p=NULL,*l=NULL;
    while(1)
    {
        printf("Enter the element inserted :->\n");
        scanf("%d",&x);
        p=(node*)malloc(sizeof(node));
        p->info=x;
        p->next=l;
        l=p;
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

