#include <bits/stdc++.h>

using namespace std;

int house_rob(int n, vector<int> &arr)
{
    int prev1= arr[0];
    int prev2=0;
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += prev2;
        }
        int nottake = 0 + prev1;
        int curi = max(take, nottake);
        prev2=prev1;
        prev1=curi;
    }
    return prev1;
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
    int res = house_rob(n, arr);
    cout << "\nMaximum Robbed Money is : " << res;
    return 0;
}