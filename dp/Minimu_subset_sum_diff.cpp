#include <bits/stdc++.h>
using namespace std;

int Equal_sum_partition(vector<int> &wt, int n, bool dp[][101])
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=wt[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = ((dp[i - 1][j - wt[i - 1]]) || (dp[i - 1][j]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int half_range=0;
    half_range=((sum+1)/2);
    cout<<"Half range: "<<half_range<<endl;
    vector<int> arr;
    for(int i=0;i<=half_range;i++)
    {
        if(dp[n][i])
        {
            arr.push_back(i);
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
        int x=(sum-(2*arr[i]));
        mn=min(mn,x);
    }
    return mn;
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
    bool dp[101][101];
    cout << "\n"<<Equal_sum_partition(wt, n, dp);
    return 0;
}