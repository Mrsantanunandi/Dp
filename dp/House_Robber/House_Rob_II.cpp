#include <bits/stdc++.h>

using namespace std;

int house_rob(int n, vector<int> &arr)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int prev1 = arr[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += prev2;
        }
        int nottake = 0 + prev1;
        int curi = max(take, nottake);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

int house_rob_II(int n, vector<int> &arr)
{
    if (n == 1)
    {
        return arr[0];
    }
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(arr[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(arr[i]);
        }
    }
    cout << endl;
    int ans1 = house_rob(temp1.size(), temp1);
    int ans2 = house_rob(temp2.size(), temp2);
    return max(ans1, ans2);
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
    int res = house_rob_II(n, arr);
    cout << "\nMaximum Robbed Money is : " << res;
    return 0;
}