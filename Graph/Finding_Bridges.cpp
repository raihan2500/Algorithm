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
#define ppfr(v)             v.erase(v.begin());
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

vector<int> graph[N], in(N), low(N), vis(N);
int n,m, timer = 0;

void dfs(int vertex = 1, int par = 0){
    if(vis[vertex])return;
    vis[vertex] = true;

    in[vertex] = low[vertex] = timer++;

    for(auto child : graph[vertex]){
        if(child == par)continue;

        if(vis[child]){
            //This is a back edge
            low[vertex] = min(low[vertex], in[child]);
        
        }else{
            //This is a forward Edge
            dfs(child, vertex);

            if(low[child] > in[vertex]){
                cout << vertex <<" --- " << child << " is a bridge" << endl;
            }

            low[vertex] = min(low[vertex], low[child]);
        }
    }
}

void reset(){
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        vis[i] = 0;

    }
}

void sukuna(){
    cin >> n >> m;
    reset();
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);
    Forn(i,n)cout << in[i] <<" ";nl;
    Forn(i,n)cout << low[i] <<" ";nl;

    int bridge_cnt = 0;

}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    while(test--)sukuna();
    return 0;
}