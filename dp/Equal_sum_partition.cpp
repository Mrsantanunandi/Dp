#include <bits/stdc++.h>
using namespace std;

bool Equal_sum_partition(vector<int> &wt, int n, bool dp[][101])
{
    int sum = 0;
    for (int i = 0; i < wt.size(); i++)
    {
        sum += wt[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    sum = sum / 2;
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
    bool dp[101][101];
    cout << Equal_sum_partition(wt, n, dp);
    return 0;
}