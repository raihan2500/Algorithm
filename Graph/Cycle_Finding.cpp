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

int n, m, leaf, node;
vector<pr> graph[N];
bool vis[N], isExists = false;
int parent[N];

void dfs(int vertex, int par = 0, int val = 0){
    if(isExists)return;
    if(vis[vertex])return ;
    vis[vertex] = true;
    parent[vertex] = par;

    for(auto prr : graph[vertex]){
        int child = prr.first;
        int wt = prr.second;
        if(child == par)continue;
        
        if(vis[child]){
            if(val + wt < 0){
                isExists = true;
                leaf = vertex;
                node = child;
                return;
            }

        }else{
            dfs(child, vertex, val + wt);
        }
    }
}

void sukuna(){

    cin >> n >> m;
    forn(i,m){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }    

    dfs(1);
    if(!isExists){
        no;
        return;
    }
    yes;
    cout << leaf <<" " << node << endl;
    return;

    int sum = 0;
    vin ans;

    while(leaf != node){
        ans.push_back(leaf);
        leaf = parent[leaf];
    }
    ans.push_back(1);

    reverse(all(ans));
    ans.push_back(node);
    print(ans);
        
}

int32_t main(){
    fast_in_out;

    int test = 1;
    while(test--)sukuna();
    return 0;
}