#include<stdio.h>
int BinarySearch(int a[],int size,int ele)
{
    int low,high,mid;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==ele)
        {
            return mid;
        }
        if(a[mid]<ele)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    //Array must be sorted in bainarySearch
int a[]={2,4,10,12,45,56,78,89};
int size=sizeof(a)/sizeof(int);
int ele;
printf("Enter the element which you want to be search\n:");
scanf("%d",&ele);
int serch=BinarySearch(a,size,ele);
printf("The element %d is found of index %d" ,ele,serch);
}


