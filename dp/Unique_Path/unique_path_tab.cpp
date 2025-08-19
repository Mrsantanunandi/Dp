#include <bits/stdc++.h>

using namespace std;

int max_path(int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n-1][m-1];
}
int main()
{
    int n, m;
    cout << "Enter no of rows and no of col: " << endl;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int res = max_path(n, m, dp);
    cout << "Ans is: " << res;
    return 0;
}