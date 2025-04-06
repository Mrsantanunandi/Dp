#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* dp;
int n=-1;
int fact(int val)
{
    int p=n;
    if(n==-1)
    {
        dp=(int*)malloc((val +1)*sizeof(int));
        n=val;
    }
    if(val>n)
    {
        dp=(int*)realloc(dp,(val+1)*sizeof(int));
        n=val;
    }
    for(int i=p+1;i<=n;i++)
    {
        if(i==0)
        {
            dp[0]=1;
        }
        else
        {
            dp[i]=i*dp[i-1];
        }
    }
    return dp[val];
}
int main()
{
    int i,n;
    printf("\nEnter no of value: ");
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("\nError in creation");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        printf("\nEnter number: ");
        scanf("%d",&arr[i]);
        clock_t start=clock();
        int ans=fact(arr[i]);
        clock_t end=clock();
        double time=((double)(start-end))/CLOCKS_PER_SEC;
        printf("\nFactorial of %d is: %d\n",arr[i],ans);
        printf("CPU Time: %lf Sec",time);
    }
    free(arr);
    return 0;
}