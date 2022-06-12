#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void B_sort(int[],int);
int main()
{
    int a[MAX],i,n;
    printf("Enter the Size of array=>\n");
    scanf("%d",&n);
    printf("Enter the elements of array=>\n ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    B_sort(a,n);
    printf("\nAfter the sorting\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
void B_sort(int a[],int n)
{
    int i,j,t=0;
    for(i=0; i<n; i++)

    {
        for(j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
