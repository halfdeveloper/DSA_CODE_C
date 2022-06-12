#include<stdio.h>
void display(int a[],int n)
{
    for(int i =0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
Deletion(int a[],int size,int index)
{
    for(int i=index; i<size-1; i++)
    {
        a[i]=a[i+1];
    }
}
main()
{
    int a[100]= {2,5,7,8,9};
    int size=5,index=3;
    Printf("\nBefore Deletion \n");
    display(a,size);
    printf("\nAfter Deletions of Element\n");
    Deletion(a,size,index);
    size-=1;
    display(a,size);
}
