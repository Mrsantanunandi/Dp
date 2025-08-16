#include <bits/stdc++.h>

using namespace std;

int min_energy(int n, int k, vector<int> &arr, vector<int> &dp)
{
    dp[0]=0;
    for (int i = 1; i < n; i++)
    {
        int mn = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                mn = min(mn, dp[i - j] + abs(arr[i] - arr[i - j]));
            }
            dp[i] = mn;
        }
    }
    return dp[n-1];
}
int main()
{
    int n, k;
    cout << "Enter no of stairs: ";
    cin >> n;
    cout << "Enter energy array: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter how much step frog can jump at once: ";
    cin >> k;
    vector<int> dp(n, -1);
    int res = min_energy(n, k, arr, dp);
    cout << "\nMinimum Energy is : " << res;
    return 0;
}