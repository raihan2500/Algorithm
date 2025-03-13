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

int n;
string str;
int dp[5005][5005];

int func(char a, char b){
    int num = (a - '0') * 10 + b - '0';
    return num <= 26;
}

int recur(int i, int len){

    if(i == n)return 1;
    if(dp[i][len] != -1)return dp[i][len];

    int a = recur(i + 1, len + 1);
    int b = 0;
    if( i < n - 1 and func(str[i], str[i + 1]))b = recur(i + 2, len + 1);

    return dp[i][len] = a + b;
}

void reset(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
}

int32_t main(){
    fast_in_out;
    cin >> str;
    while(str != "0"){
        n = str.size();
        reset();
        cout << recur(0, 0) << endl;
        cin >> str;
    }
}