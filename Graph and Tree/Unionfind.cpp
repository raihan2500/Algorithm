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

class Dsu{
    private:
        int n;
        vector<int> par, sz;
        void make(){
            for(int v = 1; v <= n; v++){
                par[v] = v; 
                sz[v] = 1;
            }
        }
    public:
        Dsu(int n){
            this->n = n;
            par = vector<int> (n + 1);
            sz = vector<int> (n + 1);
            make();
        }
        
        int Find(int v){
            if(par[v] == v)return v;
            return par[v] = Find(par[v]);
        }
        void Union(int a, int b){
            a = Find(a);
            b = Find(b);

            if(a != b){
                if(sz[a] < sz[b])swap(a, b);
                par[b] = a;
                sz[a] += sz[b];
            }
        }
};

void sukuna(){
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
        
    while(m--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t)cout << (dsu.Find(x) == dsu.Find(y)) << endl;
        else dsu.Union(x, y);
    }
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    // cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        sukuna();
    }
    return 0;
}