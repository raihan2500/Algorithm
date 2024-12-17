#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

#define int                long long

#define yes                cout<<"yes\n"
#define no                 cout<<"no\n"
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
const int N = 2e3 + 100;



int b, c, a, n, vis[N];
int d_cnt, s_cnt, tot;


vin cc;
vector<pr> s;
vector<vin> graph(N);
void dfs(int vertex){
    if(vis[vertex])return;
    vis[vertex] = 1;
    cc.push_back(vertex);

    for(auto child : graph[vertex]){
        dfs(child);
    }
}

void reset(){
    s.clear();
    d_cnt = 0, s_cnt = 0, tot = 0;
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        vis[i] = 0;
    }
}

void sukuna(int test){
    cin >> b >> c >> a;
    n = b + c;
    reset();



    set<pr> inp;
    while(a--){
        int l, r;
        cin >> l >> r;
        if(l > r)swap(l, r);
        inp.insert({l, r});
        // s.erase({l, r});
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(inp.count({i, j}))continue;
            s.push_back({i, j});
        }
    }

    // mprint(s);nl;
    for(auto i : s){
        graph[i.first].push_back(i.second);
        graph[i.second].push_back(i.first);
    }

    vector<vin> cnc;
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        cc.clear();
        dfs(i);
        cnc.push_back(cc);
    }

    for(auto v : cnc){
        int sz = v.size();
        if(sz > 2){
            no; return;
        }
        if(sz == 2)d_cnt++;
        else s_cnt++;
    }
    tot = d_cnt + s_cnt;

    if(d_cnt > b or d_cnt > c){
        no;
        return;
    }
    yes;    
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}