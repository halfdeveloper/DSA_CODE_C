#include<stdio.h>
void display (int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    //printf("\n");
}
int insertion(int a[],int size, int element,int cap,int index)
{
    if(size>=cap)
    {
        return -1;
    }

    int i;
    for(i=size-1;i>=index;i--)
    {
        a[i+1]=a[i];
    }
    a[index]=element;
    return 1;
}

main()
{
    int a[100]= {2,4,12,44,55};
    int size=5, element =45,index=2;
    display(a,size);
    printf("After the insert the element into the array\n");
    insertion(a,size,element,100,index);
    size+=1;
    display(a,size);
}
