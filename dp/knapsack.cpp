#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int n, int w,int dp[][101])
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    int n, k;
    cout << "Enter no element : ";
    cin >> n;
    vector<int> wt(n);
    vector<int> val(n);
    cout << "Enter weight: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter profit: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << "Enter knapsack weight: ";
    cin >> k;
    int dp[101][101];
    int profit = knapsack(wt, val, n, k,dp);
    cout<<"Profit is: "<<profit;
    return 0;
}