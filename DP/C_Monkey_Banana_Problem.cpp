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

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template <typename T>      using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e3 + 100;

int n;
int v[N][N];
int dp[N][N];

int recur(int i, int j){

    if(i >= 2 * n)return 0;
    if(dp[i][j] != -1)return dp[i][j];

    int a = 0, b = 0;
    int x = 0, y = 0;
    if(i < n){
        x = j, y = j + 1;
    }else{
        x = j - 1, y = j;
    }

    a = v[i][j] + recur(i + 1, x);
    b = v[i][j] + recur(i + 1, y);

    return dp[i][j] = max(a, b);
}


void reset(){
    for(int i = 0; i <= 2 * n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
            v[i][j] = 0;
        }
    }
}

void sukuna(int test){
    cout << "Case " << test <<": ";
    cin >> n;
    reset();
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> v[i][j];
        }
    }

    for(int i = n + 1, k = n - 1; i < 2 * n; i++, k--){
        for(int j = 1; j <= k; j++){
            cin >> v[i][j];
        }
    }

    cout << recur(1, 1) <<endl;
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}