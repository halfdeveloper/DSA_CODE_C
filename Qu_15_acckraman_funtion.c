#include<stdio.h>
ACK(int,int);
main()
{   int m,n;
    printf("Enter the value of m and n\n");
    scanf("%d%d",&m,&n);
    ACK(m,n);
}
ACK(int m ,int n)
{
    if(m==0)
    {
        printf("The value of n is =  %d",n+1);
        return 1;
    }
    else if(m>0&&n==0)
    {
        ACK(m-1,1);
    }
    else
    {
        ACK(m-1,ACK(m,n-1));
    }
}
