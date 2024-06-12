#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"

#define lin(n)             ll n;cin>>n;
#define in(n)              int n;cin>>n;
#define vin                vector<int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define srt(v)             sort(v.begin(),v.end());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second
#define mmp                make_pair

#define sz(x)              ((ll)(x).size())
#define forn(i,e)          for(ll i=1;i<=e;i++)
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N=1e6+10;
int pf[N];

int main()
{
    fast_in_out;

    ll n,m,x;
    cin>>n>>m;
    vector<ll>v(n+10);

    forn(i,n)cin>>v[i];

    forn(i,n)
    {
        if(pf[m-v[i]]){yes; return 0;}
        pf[v[i]]=1;
    }
    no;
    return 0;
}