#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

#define int                 long long

#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"

#define lin(n)              int n;cin>>n;
#define pr                  pair<int, int>
#define vin                 vector<int>
#define pp                  pop_back()
#define pb(n)               push_back(n)
#define ppfr(v)             v.erase(v.begin());
#define all(x)              x.begin(),x.end()

#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
                            
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)
template <typename T>       using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void sukuna(){
    int n, k;
    cin >> n >> k;
    vin v(N), pf(N), sum(N), flg(N);
    Forn(i,n){
        cin >> v[i];
        sum[i] += v[i] + sum[i - 1];
    }
    Forn(i,n){
        cin >> flg[i];
        if(flg[i])pf[i] = v[i];
    }
    for(int i = n + 1; i < N; i++)sum[i] += sum[i - 1];
    for(int i = n - 1; i >= 0; i--)pf[i] += pf[i + 1];

    int ans = pf[0];
    int cur = 0;
    for(int i = 1; i <= n; i++){
        if(flg[i]){cur += v[i]; continue;}
        ans = max(ans, cur + (sum[i + k - 1] - sum[i - 1]) + pf[i + k]);
    }
    cout << ans << endl;
    
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;  
    // cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        sukuna();
    }
    return 0;
}