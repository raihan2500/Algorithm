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
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N=1e3;

int solve()
{
    ll n,x,sum=0;
    int arr[N]={0};
    cin>>n;
    forn(i,n)
    {
        cin>>x;
        arr[x]++;
    }
    
    forn(i,N)if(arr[i]>=3)sum+=arr[i]/3;
    cout<<sum;
    nl;
    
    
    return 0;
}

int main()
{
    fast_in_out;

    int test;	cin>>test;
    while(test--)solve();
    return 0;
}