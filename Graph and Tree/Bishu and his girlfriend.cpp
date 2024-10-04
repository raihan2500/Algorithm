#include<bits/stdc++.h>
using namespace std;

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
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

vector<int> graph[N], vis(N), height(N), depth(N);
int n,m;

void dfs(int vertex = 1, int par = -1){
    if(vis[vertex])return;
    vis[vertex] = true;

    for(auto child : graph[vertex]){
        if(vis[child])continue;
        
        depth[child] = depth[vertex] + 1;
        dfs(child);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

void reset(){
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        vis[i] = 0;
        height[i] = 0;
        depth[i] = 0;
    }
}
void sukuna(){
    cin >> n;
    reset();
    for(int i = 0; i < n - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);

    lin(m);
    vin q(m);
    forn(i,m)cin >> q[i];

    vector<pr> v;

    for(auto i : q){
        v.push_back({depth[i], i});
    }

    sort(all(v));
    cout << v.front().second << endl;


}

int32_t main(){
    fast_in_out;

    int test = 1;
    while(test--)sukuna();
    return 0;
}