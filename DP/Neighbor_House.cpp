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
const int N = 20 + 100;

int n;
vector<vin> v(N, vin(5)), dp(N, vin(5, -1));
int trace[N][5];

pr nxtColor(int x){
    if(x == 1)return {2, 3};
    if(x == 2)return {1, 3};
    if(x == 3)return {1, 2};
    return {0, 0};
}

int recur(int ind, int color){
    if(ind >= n)return 0;
    if(dp[ind][color] != -1)return dp[ind][color];

    pr nxt = nxtColor(color);
    int a = recur(ind + 1, nxt.first);
    int b = recur(ind + 1, nxt.second);

    if (a < b) {
        trace[ind][color] = nxt.first;
    } else {
        trace[ind][color] = nxt.second;
    }

    return dp[ind][color] = v[ind][color] + min(a, b);
}

void printTrace(int startColor) {
    int color = startColor;
    for (int i = 0; i < n; i++) {
        cout << "House " << i + 1 << " painted with color " << color << endl;
        color = trace[i][color];
    }
    nl;
}

void reset(){
    forn(i, N)forn(j, 5)dp[i][j] = -1, trace[i][j] = 0;
}

void sukuna(int test){
    cout << "Case " << test <<": ";
    
    cin >> n;
    reset();

    forn(i,n)Forn(j,3)cin >> v[i][j];

    int ans = INF;
    int startColor = 1;
    
    for(int i = 1; i <= 3; i++) {
        int res = recur(0, i);
        if (res < ans) {
            ans = res;
            startColor = i;
        }
    }
    cout << ans << endl;

    // printTrace(startColor); //For printing the trace
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}