/*
 Developed by - Deepak Kumar MCA_A_51.
 Problem Statement - Assume that you have already have single linked list
 with pointer *.write a function to search for a key and if key is found then
 linked list should by deleting the node having key..
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int main()
{
    node *lft = NULL, *rt = NULL;
    int ch = 1, n;
    while (ch)
    {

        node *p = NULL;
        p = (node *)malloc(sizeof(node));
        printf("\n Enter the data in the linked list :\n");
        scanf("%d", &p->data);
        if (lft == NULL && rt == NULL)
            lft = rt = p;
        else
        {
            rt->next = p;
            rt = p;
        }
        rt->next = NULL;
        printf("\n Press 1 for continue\n Press 0 for exit\n");
        scanf("%d", &ch);
    }
     node *t1 = NULL;
     t1 = lft;
     printf("\n Original nodes are:\n");
     while (t1 != NULL)
     {
         printf("%d ", t1->data);
         t1 = t1->next;
     }
    printf("\nEnter the no you want to search\n");
    scanf("%d", &n);
    int flag = 0;
    node *tmp = NULL;
    tmp = lft;
    while (tmp != NULL)
    {
        if (tmp->data == n)
        {
            flag = 1;
            if (tmp == lft)
            {
                lft = lft->next;
                tmp = lft;
                // free(temp);
                // printf("\nNo.found\n");
            }
            else if (tmp == rt)
            {
                node *move = NULL;
                move = lft;
                while (move->next != rt)
                {
                    move = move->next;
                }
                move->next = NULL;
                rt = move;
                tmp = lft;
                // free(temp);
                // printf("\nNo.found\n");
            }
            else
            {
                node *move = NULL;
                move = lft;
                while (move->next->data != n)
                {
                    move = move->next;
                }
                (move->next) = (tmp->next);
                tmp = lft;
                // free(temp);
                // printf("\nNumber isfound\n");
            }
        }
        else
            tmp = tmp->next;
    }
    if (flag == 0)
        printf("\nNumber is Not found \n no Updations in list\n");
    else
    {   printf("\nNumber is found\n");
        printf("\n Updated list is \n");
        node *print = NULL;
        print = lft;
        if (lft == NULL)
            printf("\n Empty list\n");
        else
        {
            while (print != NULL)
            {
                printf("%d ", print->data);
                print = print->next;
            }
        }
    }
}
/************OUTPUT************

 Enter the data in the linked list :
1

 Press 1 for continue
 Press 0 for exit
1

 Enter the data in the linked list :
20

 Press 1 for continue
 Press 0 for exit
1

 Enter the data in the linked list :
30

 Press 1 for continue
 Press 0 for exit
1

 Enter the data in the linked list :
40

 Press 1 for continue
 Press 0 for exit
1

 Enter the data in the linked list :
5

 Press 1 for continue
 Press 0 for exit
0

 Original nodes are:
1 20 30 40 5
Enter the no you want to search
5

Number is found

 Updated list is
1 20 30 40
Process returned 0 (0x0)   execution time : 20.152 s
Press any key to continue
*/
