/*
 Developed by - Deepak Kumar MCA_A_51.
 Problem Statement - A processor is working in multiprogramming envoiment
 for four process p1,p2,p3,p4 individually are 100ms, 70ms,50ms and 20ms
  respectivly Using c cricular linked list genretes a processor secdeuling
  table and compute total waiting time or compute the total time to complete
  these processes individually.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
typedef struct node
{
    int no;
    int timetaken;
    struct node *next;
} node;

typedef struct processInfo
{
    char process;
    int timetaken;
} processInfo;
int main()
{
    node *head = NULL, *tail = NULL;
    processInfo a[N];
    int NoOfProcessor, i = 1, TotalWaitingTime = 0, j = 0;
    printf("\n Enter no of processor\n");
    scanf("%d", &NoOfProcessor);
    while (i <= NoOfProcessor)
    {
        node *ptr = NULL;
        ptr = (node *)malloc(sizeof(node));
        printf("\n Enter time taken by processor %d\n And process number \n", i);
        scanf("%d%d", &ptr->timetaken,&ptr->no);
        if (head == NULL && tail == NULL)
            head = tail = ptr;
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
        tail->next = head;
        i++;
    }
    node *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        temp->timetaken = temp->timetaken - 10;
        TotalWaitingTime += 10;
        if (temp->timetaken == 0)
        {
            a[j].process = temp->no;
            a[j].timetaken = TotalWaitingTime;
            j++;
            if (head == tail)
            {
                head = tail = NULL;
                break;
            }

            else
            {
                node *extra = NULL, *more = NULL;
                extra = head;
                more = tail;
                while (extra->next != tail)
                {
                    extra = extra->next;
                }
                extra->next = head;
                tail = extra;
                free(more);
                temp = head;
            }
        }
        else
            temp = temp->next;
    }
    printf("\nTotal waiting time is : %d ms", TotalWaitingTime);
    printf("\nTotal time taken by individual process\n");
    printf("\n Process-NO.\tTime taken individually\n");
    for (int k = 0; k < j; k++)
    {
        printf("\nP%d\t\t%d ms\n", a[k].process, a[k].timetaken);
    }
}
/*************OUTPUT************

 Enter no of processor
4

 Enter time taken by processor 1
 And process number
100
1

 Enter time taken by processor 2
 And process number
70
2

 Enter time taken by processor 3
 And process number
50
3

 Enter time taken by processor 4
 And process number
20
4

Total waiting time is : 240 ms
Total time taken by individual process

 Process-NO.    Time taken individually

P4              80 ms

P3              170 ms

P2              210 ms

P1              240 ms

Process returned 0 (0x0)   execution time : 22.241 s
Press any key to continue.**************/
