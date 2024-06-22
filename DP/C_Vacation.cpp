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
vector<vector<int>> v, dp(N, vin (3)) ;



int func(int n, int j){
    int mx = 0;
    
    if(n < 0)return 0;
    if(n == 0)return v[n][j];

    for(int i = 0; i < 3; i++){
        if(i == j)continue;

        if(dp[n - 1][i] == -1){
            dp[n - 1][i] == func(n - 1, i);
        }
        mx = max(mx, v[n][j] + dp[n - 1][i]);
    }
    return dp[n][j] = mx;

}

int32_t main()
{
    fast_in_out;
    lin(n);

    for(auto &a : dp)
        for(auto &x : a)x = - 1;

    forn(i,n){
        vin vv(3);
        forn(j, 3)cin>>vv[j];
        v.push_back(vv);
    }

    for(int i = 0; i < 3; i++)
        dp[0][i] = v[0][i];


    int ans = 0;
    for(int i = 0; i < 3; i++){
        ans = max(ans, func(n - 1, i));
    }
    cout<<ans<<endl;    
    
}