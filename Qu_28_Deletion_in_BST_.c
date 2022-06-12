
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
