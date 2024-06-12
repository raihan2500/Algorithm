#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
const int N=10e5;
const int M=10e7;
int main()
{
    ll arr[N];
    ll n,x,q; cin>>n;
    forn(i,n)
    {
        cin>>x;
        arr[x]++;
    }
    cin>>q;

    while(q--)
    {
        cin>>x;
        cout<<arr[x];nl;
    }

    
}