#include <bits/stdc++.h>

using namespace std;

int house_rob(int idx, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
    {
        return dp[0] = arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int take = arr[idx] + house_rob(idx - 2, arr, dp);
    int nottake = 0 + house_rob(idx - 1, arr, dp);
    return dp[idx] = max(take, nottake);
}
int main()
{
    int n;
    cout << "Enter no of House: ";
    cin >> n;
    cout << "Enter Amt. of Money in each House: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n, -1);
    int res = house_rob(n-1, arr, dp);
    cout << "\nMaximum Robbed Money is : " << res;
    return 0;
}