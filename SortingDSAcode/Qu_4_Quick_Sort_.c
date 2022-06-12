#include<stdio.h>
#define max 100
void qui_sort(int [],int,int );
int main()
{
    int a[max],i,n;
    printf("Enter size::\n");
    scanf("%d",&n);
    printf("Enter array element::\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("BEFORE SORTING\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    qui_sort(a,0,n-1);
    printf("AFTER SORTING\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}
void qui_sort(int b[],int lb,int ub)
{
    int key = b[lb] , i=lb ,j=ub ,t=0;
    if(lb>=ub)
        return 0;
    while(i<j)
    {
        while(key>=b[i]&&i<j)
            i++;
        while(key<b[j])
            j--;
        if(i<j)
        {
            t=b[i];
            b[i]=b[j];
            b[j]=t;
        }
        b[lb]=b[j];
        b[j]=key;
        qui_sort(b,lb,j-1);
        qui_sort(b,j+1,ub);
    }
}

