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
#include<sys/Zresource.h>
#endif

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e3 + 10;

int n, oxygen, nitrogen;
int v[N][4];
int dp[N][22][80];

int recur(int i, int ox, int ni){
    if(ox >= oxygen and ni >= nitrogen)return 0;
    if(i > n)return INF;
    if(dp[i][ox][ni] != -1)return dp[i][ox][ni];

    int a = v[i][3] + recur(i + 1, min(oxygen, ox + v[i][1]), min(nitrogen, ni + v[i][2]));
    int b = recur(i + 1, ox, ni);

    return dp[i][ox][ni] = min(a, b);
}

void reset(){
    for(int j = 0; j < 22; j++){
        for(int k = 0; k < 80; k++){
            dp[n + 1][j][k] = INF;
        }
    } return;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 22; j++){
            for(int k = 0; k < 80; k++){
                dp[i][j][k] = -1;
            }
        }
    }
}

void sukuna(int test){
    cin >> oxygen >> nitrogen;
    cin >> n;
    reset();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin >> v[i][j];
        }
    }
    // cout << recur(1, 0, 0) << endl;

    for (int i = n; i >= 0; i--) {
        for (int ox = 0; ox <= oxygen; ox++) {
            for (int ni = 0; ni <= nitrogen; ni++){
                if (ox >= oxygen && ni >= nitrogen) {
                    dp[i][ox][ni] = 0;
                } else if (i == n) {
                    dp[i][ox][ni] = INF;
                } else {
                    int a = v[i + 1][3] + dp[i + 1][min(oxygen, ox + v[i + 1][1])][min(nitrogen, ni + v[i + 1][2])];
                    int b = dp[i + 1][ox][ni];
                    dp[i][ox][ni] = min(a, b);
                }
            }
        }
    }

    

    // for(int i = n; i > 0; i--){
    //     for(int j = 0; j < 22; j++){
    //         for(int k = 0; k < 80; k++){
    //             int a = v[i][3] + dp[i + 1][j + v[i][1]][k + v[i][2]];
    //             int b = dp[i + 1][j][k];
    //             dp[i][j][k] = min(a, b);
    //         }
    //     }
    // }
    cout << dp[1][0][0] << endl;
    
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}