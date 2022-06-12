#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;

} node;
node* insert(node*,node*);
void display(node *, node *);
void main()
{
    int ch;
    node *lft=NULL,*rt=NULL;
    do
    {
        printf("\nEnter your choice\n1-insert\n2-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            rt=insert(lft,rt);
            if(lft==NULL)
            lft=rt;
            break;
        case 2:
            display(lft,rt);
            break;
        }
    }
    while(ch<=2);

}
node* insert(node *lft,node*rt)
{
    int x;
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("not enough memory\n");
    }
    else
    {
        printf("Enter the value \n");
        scanf("%d",&x);
        p->info=x;
        if(lft==NULL && rt==NULL)
        {
            lft=rt=p;
        }
        else
        {
            rt->next=p;
            rt=p;
        }
         rt->next=lft;
    }
    return rt;
}
void display(node *lft, node *rt)
{
    node *temp=rt;
    do
    {
        printf("%d\t",temp->info);
        temp = temp->next;
    }while(temp!=rt);
}
