#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define ppfr(v)            v.erase(v.begin());
#define all(x)             x.begin(),x.end()

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;


#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template <typename T>      using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

int n, m;
int grid[105][105];
int dp[105][105];

int recur(int i, int j){
    
    if(i == n)return 0;
    if(dp[i][j] != -1)return dp[i][j];

    int a = 0, b = 0, c = recur(i + 1, j);
    if(j - 1 >= 0)a = recur(i + 1, j - 1);
    if(j + 1 < m)b = recur(i + 1, j + 1);

    return dp[i][j] = grid[i][j] + max({a, b, c});
}

void reset(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }
}

void sukuna(int test){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    reset();

    int ans = 0;
    for(int i = 0; i < m; i++){
        ans = max(ans, recur(0, i));
    }

    cout << ans << endl;
    
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}