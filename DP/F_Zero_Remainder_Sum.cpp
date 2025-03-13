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

#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

int n, m, k;
int v[100][100], dp[72][72][36][70];
#define dpr      dp[i][j][cnt][rem]

int recur(int i, int j, int cnt, int rem){
    if(i > n)return rem % k ? -INF : 0;
    if(j > m)return recur(i + 1, 1, m / 2, rem);
    if(cnt == 0)return recur(i + 1, 1, m / 2, rem);
    if(dpr != -1)return dpr;

    int a = recur(i, j + 1, cnt, rem);
    int b = v[i][j] + recur(i, j + 1, cnt - 1, (v[i][j] + rem) % k);

    return dpr = max(a, b);    
}

void sukuna(int test){
    cin >> n >> m >> k;
    Forn(i,n)Forn(j,m)cin >> v[i][j];
    memset(dp, -1, sizeof(dp));
    cout << recur(1, 1, m / 2, 0) << endl;
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    // cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}