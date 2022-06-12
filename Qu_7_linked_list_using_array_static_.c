#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int info;
    struct list *next;
} node;
main()
{
    node *p=NULL,a,b,c;
    a.info=10;
    b.info=101;
    c.info=100;
    a.next=&b;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    p=&a;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
}
