
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;
node* insert(node*,node*);
node* last(node*,node*);
node* first(node*);
void display(node*);
void displayBT(node*);
void printAlternateNode(node*);
node*pos(node*);
node *delete(node*,int);
node*serch(node*,int);
void middle(node*);
void sort(node*);

main()
{
    int ch,key;
    node*lft=NULL,*rt=NULL;
    do
    {
        printf("\nEnter choice\n");
        printf("\n1-insert\n2-lastnode\n3-first\n4-display\n5-printAlternateNode\n6-postion\n7-delete\n8-serch\n9-middleelemnt\n10bottomtotop\n11-sort\n12-exit(0)\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            lft = insert(lft,rt);
            break;
        case 2:
            rt= last(lft,rt);
            break;
        case 3:
            lft=first(lft);
            break;
        case 4:
            display(lft);
            break;
        case 5:
            printAlternateNode(lft);
            break;
        case 6:
            lft=pos(lft);
            break;
        case 7:
            printf("Enter the key-->\n");
            scanf("%d",&key);
            lft=delete(lft,key);
            display(lft);
            break;
        case 8:
            printf("Enter the value of key-->\n");
            scanf("%d",&key);
            if(serch(lft,key)==1)
                printf("The key is found\n");
            else
                printf("Key is not  found\n");
            break;
        case 9:
            middle(lft);
            break;
        case 10:
            displayBT(lft);
            break;
        case 11:
            sort(lft);
            break;
        }
    }
    while(ch!=12);
}
node* insert(node*l,node*r)
{
    int x;
    node*p=NULL;
    printf("Enter the value which want to be insert:->\n");
    scanf("%d",&x);
    p=(node*)malloc(sizeof(node));
    p->info=x;
    p->next=l;
    l=p;
    return l;
}
node* last(node*head,node*tail)
{
    int x;
    node*p=(node*)malloc(sizeof(node));
    printf("Enter the value\n");
    scanf("%d",&x);
    p->info=x;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        node*t=NULL;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=p;
    }
}
node* first(node*head)
{
    int x;
    node*p=NULL;
    p=(node*)malloc(sizeof(node));
    printf("Enter the value\n");
    scanf("%d",&x);
    p->info=x;
    p->next=head;
    head=p;
    return head;
}
node*pos(node*head)
{
    int pos,x;
    node*t=NULL,*p=NULL;
    p=(node*)malloc(sizeof(node));
    printf("Enter the postion");
    scanf("%d",&pos);
    printf("Enter the Data");
    scanf("%d",&x);
    if(head == NULL)
    {
        head->info = x;
        head->next = NULL;
        return head;
    }
    else
    {
        if(pos == 0)
        {
            p->info = x;
            p->next = head;
            return p;
        }
        else
        {
            node* temp = head;
            p->info = x;
            for(int i = 0; i < pos-1; i++)
            {
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
        }
    }
    return head;
}

node*delete(node*head,int key)
{
      node *temp;
      if(head->info == key)
      {
          temp = head;
          head = head->next;
          free(temp);
      }
      else
      {
           node *current  = head;
          while(current->next != NULL)
          {
              if(current->next->info == key)
              {
                  temp = current->next;
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              else
                  current = current->next;
          }
      }
      return head;
}
void middle(node*head)
{
    node*p=NULL,*q=NULL;
    p=head;
    q=head;
    while(q && q->next)
    {
        p=p->next;
        q=q->next->next;
    }
    printf("The middle elements is -> %d",p->info);
}
node* serch(node*head,int key)
{
    node*t=NULL;
    t=head;
    while(t!=NULL)
    {
        if(t->info==key)
            return 1;
        t=t->next;
    }
    return -1;
}
void display(node*l)
{
    node*t=NULL;
    t=l;
    while(t!=NULL)
    {
        printf("%d\t",t->info);
        t=t->next;
    }

}
void displayBT(node*head)
{
    if(head->next!=NULL)
    {
        displayBT(head->next);
    }
    printf(" %d \t",head->info);
}
void printAlternateNode(node* head)
{
    int count = 0;

    while (head != NULL)
    {

        // when count is even print the nodes
        if (count % 2 != 0)
            printf(" %d ", head->info);

        // count the nodes
        count++;

        // move on the next node.
        head = head->next;
    }
}
void sort(node*head)
{
    node*srt=NULL;
    node*t=NULL;
    int temp;
    t=head;
    while(t!=NULL)
    {
        srt=t->next;
        while(srt!=NULL)
        {
            if(t->info>srt->info)
            {
                temp=t->info;
                t->info=srt->info;
                srt->info=temp;
            }
            srt=srt->next;
        }
        t=t->next;
    }
    t=head;
    while(t!=NULL)
    {
        printf("%d\t",t->info);
        t=t->next;
    }
}
