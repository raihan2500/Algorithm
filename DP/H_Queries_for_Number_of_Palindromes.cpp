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
const int N = 5e3 + 100;

int n, q;
string str;
int x, y;
int dp[N][N];
int pal[N][N];

int recur(int l, int r){

    if(l < x or r > y)return 0; 
    // if(pal[l][r] != -1)return pal[l][r];

    int ans = 1;
    if(l == r){
        ans += recur(l + 1, l + 1);
        if(str[l] == str[l + 1] and l + 1 <= y){
            ans++;
            if(str[l - 1] == str[l + 2] and l - 1 >= l and l + 2 <= r){
                ans += recur(l - 1, l + 2);
            }
        }
    }

    if(str[l - 1] == str[r + 1]){
        ans += recur(l - 1, r + 1);
    }

    return dp[l][r] = ans;
}

int32_t main(){
    fast_in_out;
    cin >> str;
    n = str.size();
    str = "*" + str + "#";
    memset(dp, -1, sizeof(dp));
    memset(pal, -1, sizeof(pal));
    x = 1, y = n;
    // cout << recur(1, 1) << endl; return 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            x = i; y = j;
            pal[i][j] = recur(i, i);
        }
    }

    lin(q);
    while(q--){
        cin >> x >> y;
        cout << pal[x][y] << endl;
        // cout << recur(x, x) << endl;
    }

    
}