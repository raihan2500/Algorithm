#include<bits/stdc++.h>
using namespace std;

int sum(int n, int a[])
{
    if(n == -1)return 0;
    return sum(n-1,a) + a[n];

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i< n;i++)
    {
        cin>>arr[i];
    }

    cout<<sum(n-1,arr);

}