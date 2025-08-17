#include <bits/stdc++.h>

using namespace std;

int ninja(int days,int last, vector<vector<int>> &arr)
{
    if(days==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(last!=i)
            {
                maxi=max(maxi,arr[days][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(last!=i)
        {
            maxi=max(maxi,arr[days][i]+ ninja(days-1,i,arr));
        }
    }
    return maxi;
}

int main()
{
    int n;
    cout << "Enter no of days: ";
    cin >> n;
    cout << "Enter points martix: " << endl;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int res = ninja(n-1,3, arr);
    cout << "\nMaximum Robbed Money is : " << res;
    return 0;
}