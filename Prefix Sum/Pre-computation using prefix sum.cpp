#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

const int N=1e5+10;
int a[N];

int main()
{
    ll n,x,q,l,r;
    cin>>n;
    ll pf[N]; pf[0]=0;
    
    for(ll i=1;i<=n;i++)
    {
        cin>>x;
        pf[i]=pf[i-1]+x;
    }

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        
        cout<<pf[r]-pf[l-1];nl;
    }
}
//Time complexity
//O(N)+O(Q)