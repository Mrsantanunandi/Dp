#include <bits/stdc++.h>
using namespace std;

int count_Equal_sum_partition(vector<int> &wt, int n,int sum ,int dp[][101])
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = ((dp[i - 1][j - wt[i - 1]]) + (dp[i - 1][j]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<"\n";
    }
    return dp[n][sum];
}
int main()
{
    int n, sum;
    cout << "Enter no element : ";
    cin >> n;
    vector<int> wt(n);
    cout << "Enter items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout<<"Enter the sum value: ";
    cin>>sum;
    int dp[101][101];
    cout << count_Equal_sum_partition(wt, n,sum, dp);
    return 0;
}