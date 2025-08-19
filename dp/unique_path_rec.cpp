#include<bits/stdc++.h>

using namespace std;

int max_path(int n,int m,vector<vector<int>> &arr)
{
    if(n==0 || m==0)
    {
        return 1;
    }
    if(n<0 || m<0)
    {
        return 0;
    }
    int up=0;
    up=max_path(n-1,m,arr);
    int left=0;
    left=max_path(n,m-1,arr);

    return up+left;
}
int main()
{
    int n,m;
    cout<<"Enter no of rows and no of col: "<<endl;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m,-1));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int res=max_path(n-1,m-1,arr);
    cout<<"Ans is: "<<res;
    return 0;
}
