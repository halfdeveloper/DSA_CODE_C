#include<stdio.h>
int linerserch(int a[],int size,int ele)
{
    for(int i=0; i<size; i++)
    {
        if(a[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
int a[]={2,4,56,7,88,654,45,32,34,78,898,454,34,23,23};
int size=sizeof(a)/sizeof(int);
int ele;
printf("Enter the element which you want to be search\n:");
scanf("%d",&ele);
int serch=linerserch(a,size,ele);
printf("The element %d is found of index %d" ,ele,serch);
}

