#include <bits/stdc++.h>

using namespace std;

int min_energy(int i, vector<int> &arr, vector<int> &dp)
{
    if (i == 0)
    {
        return dp[i] = 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int left = min_energy(i - 1, arr, dp) + abs(arr[i] - arr[i - 1]);
    int right = INT_MAX;
    if (i > 1)
    {
        right = min_energy(i - 2, arr, dp) + abs(arr[i] - arr[i - 2]);
    }
    return dp[i] = min(left, right);
}
int main()
{
    int n;
    cout << "Enter no of stairs: ";
    cin >> n;
    cout << "Enter energy array: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n, -1);
    int res = min_energy(n-1, arr, dp);
    cout << "\nMinimum Energy is : " << res;
    return 0;
}