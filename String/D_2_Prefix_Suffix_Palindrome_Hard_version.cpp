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

mt19937                     mt(chrono::steady_clock::now().time_since_epoch().count());
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

string preprocess(string &str){
    string res = "$";
    for(auto &i : str){
        res += "#" + string(1,i);
    }
    res += "#^";
    return res;
}

string LPS(string &inp){
    string str = preprocess(inp);
    int n = str.size(), c = 0, r = 0, mx = 0;
    vector<int> lps(n);

    for(int i = 1; i < n - 1; i++){
        int mirror = 2 * c - i;
        if(i < r){
            lps[i] = min(r - i, lps[mirror]);
        }

        while(str[i + lps[i] + 1] == str[i - lps[i] - 1])lps[i]++;

        if(i + lps[i] > r){
            c = i;
            r = i + lps[i];
        }

        if(lps[i] > lps[mx]){
            if(i + lps[i] == n - 2 or i - lps[i] == 1)mx = i;
        }
    }

    return inp.substr((mx - lps[mx]) / 2, lps[mx]);
}

void sukuna(){
    string str, ans;
    cin >> str;
    int n = str.size();
    int l = 0, r = n - 1;
    
    while(str[l] == str[r] and l < r)l, r--, ans.push_back(str[l++]);
    if(l >= r){cout << str << endl; return;}

    string mid = string(str.begin() + l, str.begin() + r + 1);
    
    ans += LPS(mid) + string(ans.rbegin(), ans.rend());

    cout << ans << endl;
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        sukuna();
    }
    return 0;
}