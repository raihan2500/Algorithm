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
vin c;

void dfs(int vertex = 1, int par = -1){
    if(vis[vertex])return;
    vis[vertex] = true;
    c.push_back(vertex);
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
    cin >> n >> m;
    reset();
    vector<pr>notEqual;
    for(int i = 0; i < m; i++){
        int x, y;string str;
        cin >> x >> str >> y;

        if(str == "="){
            graph[x].push_back(y);
            graph[y].push_back(x);
        }else{
            notEqual.push_back({x, y});
        }
    }

    vector<vin> cc;
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        c.clear();
        dfs(i);
        cc.push_back(c);
    }
    vin val(n + 1);

    int mark = 1;
    for(auto c : cc){
        for(auto i : c)val[i] = mark;
        mark++;
    }

    for(auto p : notEqual){
        if(val[p.first] == val[p.second]){no; return;}
    }
    yes;

}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    while(test--)sukuna();
    return 0;
}