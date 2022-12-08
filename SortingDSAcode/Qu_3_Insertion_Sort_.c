#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void I_sort(int[],int);
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
     I_sort(a,n);
    printf("\nAfter the sorting\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
void I_sort(int a[],int n)
{
    int i=0,j=0,temp=0;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
