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
int n, W;
vector<pair<int, int>> v;
vector<vin> dp(105, vin (100060, -1));

int recur(int n, int w){
    if(n == 0)return  0;

    int x = 0, y = 0;
    if(dp[n - 1][w] == -1){
        dp[n - 1][w] = recur(n - 1, w);
    }
    x = dp[n - 1][w];

    if(w + v[n].first <= W){
        if(dp[n - 1][w + v[n].first] == -1){
            dp[n - 1][w + v[n].first] = recur(n - 1, w + v[n].first);
        }
        y = dp[n - 1][w + v[n].first] + v[n].second;
    }

    return max(x, y);

}

int32_t main()
{
    fast_in_out;

    v.push_back({0, 0});
    
    cin >>  n >> W;
    forn(i,n){
        lin(x) lin(y);
        v.push_back({x, y});
    }

    cout<<recur(n, 0);

    
}