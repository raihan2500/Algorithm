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

#define sz(x)              ((int)(x).size())
#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9 + 7;
const int N = 1e5 + 10;
vin v(N), dp(N, -1);
int n, k;

int frog(int n){
    // cout<<n<<endl;

    if(n == 0)return 0;

    int cost = INT_MAX;

    for(int i = k; i >0; i--){
        
        if(i <= n){
            if(dp[n - i] == -1)dp[n - i] = frog(n - i);
            cost = min(cost, dp[n - i] + abs(v[n] - v[n - i]));
            
        }
    }
    return cost;
}



int32_t main()
{
    fast_in_out;
    cin>>n>>k;
    forn(i,n)cin>>v[i];
    cout<<frog(n - 1);

    
    
}