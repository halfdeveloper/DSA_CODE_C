#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{

    struct BST *lft;
    int info;
    struct BST *rt;
} node;
void insert(node**,int);
void inorder(node*);
void preoder(node*);
void postorder(node*);
void countNode(node*,int*);
void countLeafNode(node*,int*);
main()
{
    int ch,num,c=0;
    node*root=NULL;
    do
    {
        printf("\n1-Insert\n2-Inorder\n3-PreOrder\n4-PostOrder\n5-CountNode\n6-CountLeafNode\n7-exit(0)\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the informations\n");
            scanf("%d",&num);
            insert(&root,num);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preoder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            countNode(root,&c);
            printf("The Total Nodes is %d  ",c);
            break;
        case 6:
            countLeafNode(root,&c);
             printf("The Total Nodes is %d  ",c);
            break;

        }
    }
    while(ch!=7);
}
void  insert(node **root,int num)
{
    node *ptr;
     ptr=(node*)malloc(sizeof(node));
    if((*root)==NULL)
    {
        ptr->info=num;
        ptr->lft=NULL;
        ptr->rt=NULL;
        (*root)=ptr;
        return;
      }
    else if((*root)->info>num)
    insert(&(*root)->lft,num);
    else if((*root)->info<num)
    insert(&(*root)->rt,num);
    else
        printf("End");
}
void inorder(node*root)
{
    if(root!=NULL)
    {
        inorder(root->lft);
        printf("%d\t",root->info);
        inorder(root->rt);
    }
}
void preoder(node*root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preoder(root->lft);
        preoder(root->rt);
    }
}
void postorder(node*root)
{
    if(root!=NULL)
    {
        postorder(root->lft);
        postorder(root->rt);
        printf("%d\t",root->info);

    }
}
void countNode(node*root,int *c)
{
    if(root!=NULL)
    {
        (*c)++;
        countNode(root->lft,c);
        countNode(root->rt,c);

    }

}
void countLeafNode(node*root,int *c)
{
    if(root!=NULL)
    {
        countLeafNode(root->lft,c);
        if(root->lft==NULL && root->rt==NULL)
        {
            (*c)++;
        }
        countLeafNode(root->rt,c);
    }
}

