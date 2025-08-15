#include <bits/stdc++.h>
using namespace std;

bool subset_sum(vector<int> &wt, int n, int sum, bool dp[][101])
{
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
            if (wt[i - 1] <= sum)
            {
                dp[i][j] = ((dp[i - 1][j - wt[i - 1]]) || (dp[i - 1][j]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
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
    cout << "Enter target sum: ";
    cin >> sum;
    bool dp[101][101];
    cout<<subset_sum(wt, n, sum, dp);
    return 0;
}