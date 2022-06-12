/* Developed by - Deepak kumar MCA_51_A.
 Problem Statement - Write a program to implement a double linked list
 and linked list should print the elements Ascending order form left to
 right then print the element in Descending  order form right to left.
 */
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
void displayBack(node*);
node*delete(node*,int key);
main()
{
    node *lft=NULL,*rt=NULL;
    int ch,key;
    do
    {
        printf("\n-----Enter your choice-----\n");
        printf("\n---\n1-Insert\n2-DisplayFor\n3-DisplayBack\n4-delete\n5-exit()--->\n");
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
            displayBack(rt);
            break;
        case 4:
            printf("Enter the value of key-->>\n");
            scanf("%d",&key);
            lft=delete(lft,key);
            displayFor(lft);
        break;
        case 5:
            printf("Exit");
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
void displayBack(node*rt)
{
    node *temp=NULL;
    temp =rt;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->prv;
    }
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


/*******************OUTPUT*************

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
1
Enter the value
10

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
1
Enter the value
50

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
1
Enter the value
9

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
1
Enter the value
40

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
1
Enter the value
45

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
1
Enter the value
35

-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
2
        9       10      35      40      45      50
-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
3
50      45      40      35      10      9
-----Enter your choice-----

---
1-Insert
2-DisplayFor
3-DisplayBack
4-exit()--->
4
Exit
Process returned 0 (0x0)   execution time : 20.941 s
Press any key to continue.*/
