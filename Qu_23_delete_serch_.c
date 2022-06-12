#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prv;
    int info;
    struct node *next;
} node;
void insert(node**,node**);
void serch_key(node**,node**);
//void delete_key(node**,node**);
main()
{
    int ch;
    node *lft=NULL, *rt=NULL;
    do
    {
        printf("\n-----Enter your choice-----");
        printf("\n---\n1-Insert\n2-DisplayFor\n3-DisplayBack\n4-exit()--->");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert(&lft,&rt);
            break;
        /*case 2:
            serch_key(&lft,&rt);
            break;*/
        case 3:
            delete_key(&lft,&rt);
            break;
        case 4:
            exit(0);
        }
    }
    while(ch!=4);
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
void delete_key(node** lft, node**rt)
{
    if (*lft == NULL || *rt == NULL)
        return;
    if (*lft == *rt)
        *lft = (*rt)->next;
    if ((*rt)->next != NULL)
        (*rt)->next->prv = (*rt)->prv;
    if ((*rt)->prv != NULL)
        (*rt)->prv->next = (*rt)->next;
    free(*rt);
}
