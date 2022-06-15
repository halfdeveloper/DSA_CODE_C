#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
    struct BST *lft;
    int info;
    struct BST *rt;
} node;
void insert(node**,int);
node* Delete(node*,int);
void inorder(node*);
main()
{
    int ch,num,c=0,item;
    node*root=NULL;
    do
    {
        printf("\n1-Insert\n2-Inorder\n3-Delete\n4-exit(0)\n");
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
            if((root==NULL))
                printf("List is empty\n");
            else
            {
                printf("Enter node to be deleted:\n");
                scanf("%d",&item);
                root=Delete(root,item);
            }
            break;
        }
    }
    while(ch!=4);
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

node* FindMin(node* curr)
{
    while (curr->lft != NULL)
    {
        curr = curr->lft;
    }
    return curr;
}
node *Delete(node *root,int num)
{
    if(root==NULL)
        return root;
    else if(num<root->info)
        root->lft=Delete(root->lft,num);
    else if(num>root->info)
        root->rt=Delete(root->rt,num);
    else
    {
//Case 1:No Child
        if(root->lft==NULL && root->rt==NULL)
        {
            free(root);
            root=NULL;
        }
//Case 2:One Child
        else if(root->lft==NULL)
        {
            node *temp=root;
            root=root->rt;
            free(temp);
        }
        else if(root->rt==NULL)
        {
            node *temp=root;
            root=root->lft;
            free(temp);
        }
        else
        {
            //Case 3: 2 Children
            node *temp=FindMin(root->rt);
            root->info=temp->info;
            root->rt=Delete(root->rt,temp->info);
        }
    }
    return root;
}
