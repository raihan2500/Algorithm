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
int n, m;
vector<pr> graph[N];
vector<int> dist(N, INF), vis(N), par(N);

void dijsktra(int src = 1){
    set<pair<int, int>> s;
    s.insert({0, src});
    dist[src] = 1;

    while(!s.empty()){
        src = (*s.begin()).second;
        s.erase(s.begin());

        if(vis[src])continue;
        vis[src] = true;

        for(auto child : graph[src]){
            int cv = child.first;
            int wt = child.second;

            if(dist[src] + wt < dist[cv]){
                dist[cv] = dist[src] + wt;
                s.insert({dist[cv], cv});
                par[cv] = src;
            }
        }
    }
}

int32_t main(){
    fast_in_out;
    cin >> n >> m;

    forn(i,m){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    dijsktra();

    if(dist[n] == INF){
        cout << - 1 << endl;
        return 0;
    }

    vector<int> ans;
    int src = n;
    while(src != 1){
        ans.push_back(src);
        src = par[src];
    }
    ans.push_back(1);
    reverse(all(ans));
    print(ans);

    
}