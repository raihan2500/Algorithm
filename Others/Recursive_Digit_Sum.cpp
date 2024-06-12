#include<bits/stdc++.h>
using namespace std;
#define int long long

int digitSum(int n)
{
    if(n == 0 )return 0;
    return digitSum(n/10) + n%10;
}

signed main()
{
    string str,s;
    int n, ans = 0 , digit = 0;
    cin>>str>>n;

    for(int i = 0;i< str.size();i++)digit+=(str[i]-48);
    digit *= n;

    again:
    digit = digitSum(digit);
    if(digit>9)goto again;

    cout<<digit<<"\n";
    
}