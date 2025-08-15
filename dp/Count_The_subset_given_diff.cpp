#include <bits/stdc++.h>
using namespace std;

int Equal_sum_partition(vector<int> &wt, int n, int diff, int dp[][101])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }
    int sum_of_s1 = (sum + diff) / 2;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum_of_s1 + 1; j++)
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
        for (int j = 1; j < sum_of_s1 + 1; j++)
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
    return dp[n][sum_of_s1];
}
int main()
{
    int n, diff;
    cout << "Enter no element : ";
    cin >> n;
    vector<int> wt(n);
    cout << "Enter items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter diff: ";
    cin >> diff;
    int dp[101][101];
    cout << Equal_sum_partition(wt, n, diff, dp);
    return 0;
}