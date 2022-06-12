#include<stdio.h>
#define max 10
void sel_sort(int [],int );
main()
{
    int a[max],i,n;
    printf("Enter the size of array::\n");
    scanf("%d",&n);
    printf("Enter the elements of array::==>\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("BEFORE SORTING\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    sel_sort(a,n);
    printf("\nAFTER SORTING\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
void sel_sort(int b[],int n)
{
    int i,j,pos=0,min=0;
    for(i=0; i<n-1; i++)
    {
        min=b[i];
        pos=i;
        for(j=i+1; j<n; j++)
        {
            if(min>b[j])
            {
                min=b[j];
                pos=j;
            }
        }
        if(pos!=i)
        {
            b[pos]=b[i];
            b[i]=min;
        }
    }
}


