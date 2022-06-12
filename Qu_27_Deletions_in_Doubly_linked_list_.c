#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prv;
    int info;
    struct node *next;
} node;
void insert(node**,node**);
void displayFor(node*);
node*deleteBeg(node*);
node* deleteLast(node*);
main()
{
    node *lft=NULL,*rt=NULL;
    int ch,key;
    do
    {
        printf("\n-----Enter your choice-----\n");
        printf("\n---\n1-Insert\n2-DisplayFor\n3-DeleteBeg\n4-DeleteLast\n5-exit()--->\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert(&lft,&rt);
            break;
        case 2:
            displayFor(lft);
            break;
        case 3:
            lft=deleteBeg(lft);
            break;
        case 4:
            rt=deleteLast(rt);
            break;
        }
    }
    while(ch!=5);
}
void insert(node**lft,node**rt)
{
    node *p=NULL;
    int num;
    p=(node*)malloc(sizeof(node));
    if(p == NULL)
        printf("\tCan't insert, bcoz We don't have enough memory\n");
    else
    {
        printf("Enter the value \n");
        scanf("%d",&num);
        p->info = num;
        if(*lft == NULL)
        {

            *lft=p;
            *rt=p;
        }
        else if(num > (*rt)->info)
        {
            (*rt)->next = p;
             p->prv = *rt;
             *rt = p;
        }
        else if(num < (*lft)->info)
        {
            p->prv = NULL;
            p->next=*lft;
            (*lft)->prv = p;
            *lft = p;
        }
        else
        {
            node*temp;
            temp=(*lft)->next;
            while(num>temp->info)
            {
                temp=temp->next;
            }
            p->next=temp;
            p->prv=temp->prv;
            (temp->prv)->next=p;
            temp->prv=p;

        }

        (*rt)->next = NULL;
    }
}

void displayFor(node*lft)
{
    node *t=lft;
    if(t == NULL)
        printf("\tLinked list is Empty\n");
    else
        while(t !=  NULL)
        {
            printf("\t%d", t->info);
            t = t->next;
        }
}



node* deleteBeg(node*lft)
{
    node*temp=NULL;
    if(lft==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        temp=lft;
        lft=lft->next;
        lft->prv=NULL;
        free(temp);
    }
    printf("After the deletions\n");
    displayFor(lft);
    return lft;

}
node* deleteLast(node*rt)
{
    node*t=NULL;
    if(rt==NULL)
    {
        printf("\nNothing to delete\n");
    }
    else
    {
        t=rt;
        rt->prv->next=NULL;
        rt=rt->prv;
        free(t);
    }
    printf("After the deletions\n");
    displayFor(rt);
}

