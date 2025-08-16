#include <bits/stdc++.h>

using namespace std;

int min_energy(vector<int> &arr)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        prev1=arr[i-1];
        int left = prev1 + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            prev2=arr[i-2];
            right = prev2 + abs(arr[i] - arr[i - 2]);
        }
        arr[i]=min(left,right);
        prev1=arr[i];
        prev2=prev1;
    }
    return arr[arr.size()-1];
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
    int res = min_energy(arr);
    cout << "\nMinimum Energy is : " << res;
    return 0;
}