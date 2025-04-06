#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fib1(int x,int* arr)
{
    if(x<=1)
    {
        return x;
    }
    if(arr[x]!=-1)
    {
        return arr[x];
    }
    arr[x]=fib1(x-1,arr)+fib1(x-2,arr);
    return arr[x];
}
int fib2(int x)
{
    if(x<=1)
    {
        return x;
    }
    int* dp=(int*)malloc((x+1)*sizeof(int));
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=x;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[x];
}
int main()
{
    int n,i,s,val;
    printf("\nEnter max range: ");
    scanf("%d",&n);
    int* arr=(int*)malloc((n+1)*sizeof(int));
    if(arr==NULL)
    {
        printf("\nError in creation");
        return 0;
    }
    //intialization with -1
    for(i=0;i<n+1;i++)
    {
        arr[i]=-1;
    }
    printf("\nHow many no of item: ");
    scanf("%d",&s);
    if(s>n)
    {
        printf("\nYour item count is more than max range");
        return 0;
    }
    for(i=0;i<s;i++)
    {
        printf("\nEnter term no: ");
        scanf("%d",&val);
        //Top down app..
        clock_t start=clock();
        int ans1=fib1(val-1,arr);
        clock_t end=clock();
        double t1=((double)(end-start))/CLOCKS_PER_SEC;
        //Bottom up app..
        start=clock();
        int ans2=fib2(val-1);
        end=clock();
        double t2=((double)(end-start))/CLOCKS_PER_SEC;
        printf("\nTerm no %d Fib value(Top Down): %d",val-1,ans1);
        printf("\nCPU TIME (Top Down): %lf",t1);
        printf("\nTerm no %d Fib value(Bottom Up): %d",val-1,ans2);
        printf("\nCPU TIME (Bottom Up): %lf",t2);
    }
    free(arr);
    return 0;
}