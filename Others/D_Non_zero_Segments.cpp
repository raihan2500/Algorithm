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
#define forn(i,e)          for(ll i=0;i<e;i++)
#define Forn(i,e)          for(ll i=1;i<=e;i++)
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast_in_out;
    ll n,x,cnt=0;
    cin>>n;
    vector<int>v(n+1),arr(n+1);
    Forn(i,n)
    {
        cin>>v[i];
        arr[i]=v[i];
        v[i]+=v[i-1];
    }
    Forn(i,n)cout<<v[i]<<" ";nl;
    Forn(i,n)
    {
        if((v[i]+v[i-1])==0)cnt++;
        if(v[i]==0)
        {
            cnt++;
            if(arr[i]-v[i+1]==0 && i<n)cnt++;
        }

    }
    cout<<cnt;nl;

    return 0;
}