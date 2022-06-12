#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
    int ex;
    int coff;
    struct poly *next;
} poly;
poly* createpoly(void);
poly* addpoly(poly*,poly*);
void disp(poly*);
void main()
{
    int ch;
    poly *p1=NULL,*p2=NULL,*p3=NULL;
    do
    {
        printf("\nEnter your choice");
        printf("\n1-create the polynomial regressions\n2-display\n3-add\n4-DisplaySum\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n For polynomial :->1\n");
            p1=createpoly();
            printf("\n For polynomial :->2\n");
            p2=createpoly();
            break;
        case 2:
            disp(p1);
            disp(p2);
            break;
        case 3:
            p3=addpoly(p1,p2);
            break;
        case 4:
            disp(p3);
            break;
        case 5:
            exit(0);
            break;


        }
    }
    while(ch!=5);
}
poly* createpoly(void)
{
    poly*p=NULL,*lft=NULL,*rt=NULL;
    int exp,cof;
    int ch;
    do
    {
        printf("\nEnter the exponent:");
        scanf("%d",&exp);
        printf("\nEnter the cofficient:");
        scanf("%d",&cof);
        p=(poly*)malloc(sizeof(poly));
        p->ex=exp;
        p->coff=cof;
        if(rt==NULL)
        {
            lft=rt=p;
        }
        else
        {
            rt->next=p;
            rt=p;
        }
        rt->next=NULL;
        printf("\nDo you want to continue press-1\n");
        printf( "\n for exit press 0\n");
        scanf("%d",&ch);
    }
    while(ch==1);
    return lft;
}
void disp(poly*lft)
{

    if(lft==NULL)
    {
        printf("Nothing to display");
    }
    else
    {
        poly*t=NULL;
        t=lft;
        printf("\nThe polynomial is :");
        while(t!=NULL)
        {
            printf("\t%dx^%d  ",t->coff,t->ex);
            t=t->next;
            if(t!=NULL)
            {
                printf("+");
            }
        }
    }
}
poly*addpoly(poly *p1, poly*p2)
{
    poly*p=NULL,*lft=NULL,*rt=NULL;
    p=(poly*)malloc(sizeof(poly));
    while(p1!=NULL && p2!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        if(p1->ex==p2->ex)
        {
            p->ex=p1->ex;
            p->coff=p1->coff+p2->coff;
            if(lft==NULL && rt==NULL)
            {
                lft=rt=p;
            }
            else
            {
                rt->next=p;
                rt=p;
                rt->next=NULL;
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->ex>p2->ex)
        {
            if(lft==NULL && rt==NULL)
            {
                p->ex=p1->ex;
                p->coff=p1->coff;
                lft=rt=p;
                rt->next=NULL;
                p1=p1->next;
            }
            else
            {
                p->ex=p1->ex;
                p->coff=p1->coff;
                rt->next=p;
                rt=p;
                rt->next=NULL;
                p1=p1->next;
            }
        }
        else
        {

            if(lft==NULL && rt==NULL)
            {
                p->ex=p2->ex;
                p->coff=p2->coff;
                lft=rt=p;
                rt->next=NULL;
                p2=p2->next;
            }
            else
            {
                p->ex=p2->ex;
                p->coff=p2->coff;
                rt->next=p;
                rt=p;
                rt->next=NULL;
                p2=p2->next;
            }
        }
    }
    while(p1!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        p->ex=p1->ex;
        p->coff=p1->coff;
        rt->next=p;
        rt=p;
        rt->next=NULL;
    }
    while(p2!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        p->ex=p2->ex;
        p->coff=p2->coff;
        rt->next=p;
        rt=p;
        rt->next=NULL;

    }
    return lft;
}

