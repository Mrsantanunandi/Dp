#include<bits/stdc++.h>

using namespace std;

int fun(int n,vector<int> &arr)
{
    if(n==1 || n==2)
    {
        arr[n]=n;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    arr[n]=fun(n-1,arr)+fun(n-2,arr);
    return arr[n];
}
int main()
{
    int n;
    cout<<"Enter no of stairs: ";
    cin>>n;
    vector<int> arr(n+1,-1);
    int res=fun(n,arr);
    for(int n:arr)
    {
        cout<<n<<" ";
    }
    cout<<"\nTotal ways: "<<res<<endl;
    return 0;
}