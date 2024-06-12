#include<bits/stdc++.h>
using namespace std;

const int Mod =  1e9+7;

int binExpREcur(int a, int b)
{
    if(b == 0)return 1;
    int res = binExpREcur(a,b/2);
     
    if(b&1)
        return (a * ((res * 1LL * res) % Mod)) % Mod;
    else 
        return (res * 1LL * res) % Mod;
}

int main()
{
     int a, b;
     cin>>a>>b;
     cout<<binExpREcur(a,b);
}