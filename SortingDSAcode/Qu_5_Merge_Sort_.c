#include<stdio.h>
#define max 100
void M_sort(int [],int[],int ,int );
void Merge(int [],int[],int ,int,int );
int main()
{
    int a[max],t[max],i,n;
    printf("Enter the size of array::\n");
    scanf("%d",&n);
    printf("Enter the elements of arrays::\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
     printf("\nBEFORE SORTING\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    M_sort(a,t,0,n-1);
    printf("\nAFTER SORTING\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void M_sort(int a[],int t[],int lb ,int ub )
{
    int mid=0;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        M_sort(a,t,lb,mid);
        M_sort(a,t,mid+1,ub);
        Merge(a,t,lb,mid+1,ub);
    }
}
void Merge(int a[],int t[],int lb,int mid,int ub)
{
    int le=mid-1,k=lb,i=lb;
    while(lb<=le&&mid<=ub)
    {
        if(a[lb]<a[mid])
        {
            t[k]=a[lb];
            k++;
            lb++;
        }
        else
        {
            t[k]=a[mid];
            k++;
            mid++;
        }
    }
    while(lb<=le)
    {
        t[k]=a[lb];
        k++;
       lb++;
    }
     while(mid<=ub)
    {
        t[k]=a[mid];
        k++;
        mid++;
    }
    for(i=0;i<=ub;i++)
    {
        a[i]=t[i];
    }
}





