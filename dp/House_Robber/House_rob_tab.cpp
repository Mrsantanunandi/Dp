#include <bits/stdc++.h>
using namespace std;

int house_rob_tab(int n, vector<int> &arr)
{
    vector<int> dp(n, 0);

    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += dp[i - 2];
        int nottake = dp[i - 1];
        dp[i] = max(take, nottake);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cout << "Enter no of House: ";
    cin >> n;

    cout << "Enter Amt. of Money in each House: " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = house_rob_tab(n, arr);
    cout << "\n(Tabulation) Maximum Robbed Money is : " << res << endl;
    return 0;
}
