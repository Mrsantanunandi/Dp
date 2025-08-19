#include <bits/stdc++.h>

using namespace std;

int max_path(int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return dp[n][m] = 1;
    }
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int up = 0;
    up = max_path(n - 1, m, dp);
    int left = 0;
    left = max_path(n, m - 1, dp);

    return dp[n][m] = up + left;
}
int main()
{
    int n, m;
    cout << "Enter no of rows and no of col: " << endl;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int res = max_path(n - 1, m - 1, dp);
    cout << "Ans is: " << res;
    return 0;
}