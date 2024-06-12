#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

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

int arr[50];

int dp(int n){
    if(n < 0)return 0;
    if(n == 0)return 1;

    if(arr[n - 1] == 0)arr[n - 1 + 2] = dp(n - 1);
    if(arr[n - 2] == 0)arr [n - 2 + 2] = dp(n - 2);

    

    return arr[n - 1 + 2] + arr[n - 2 + 2];   
}

int climbStairs(int n) {
    fast_in_out;
    return dp(n);        
}


int32_t main()
{
    fast_in_out;
    lin(n);
    cout<<climbStairs(n);   
}