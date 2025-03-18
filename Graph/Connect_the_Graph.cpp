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
vin graph[N];
vin vis(N), c;
vector<pr> toRemove;


void dfs(int vertex, int par = -1){
    if(vis[vertex]){
        toRemove.push_back({par, vertex});
        return;
    }
    vis[vertex] = true;
    c.push_back(vertex);

    for(auto child : graph[vertex]){

        dfs(child, vertex);
    }
}


int32_t main(){
    fast_in_out;
    cin >> n >> m;
    set<pr> s;
    forn(i,m){
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
        graph[x].push_back(y);
    }

    int cnt = 0;
    vector<vin> cc;

    Forn(i,n){
        if(vis[i])continue;
        c.clear();
        dfs(i);
        cc.push_back(c);
        cnt++;
    }

    for(auto c : cc){print(c)};nl;nl;nl;

    if(cnt == 1){
        cout << 0 << endl;
        return 0;
    }
    if(m < n - 1){
        cout << - 1 << endl;
        return 0;
    }

    cout << cnt - 1 << endl;

    for(int i = 1, j = 0; i < cnt; i++, j++){
        pr p = toRemove[j];
        if(!s.count(p))swap(p.first, p.second);
        cout << p.first <<" " << p.second <<" ";

        cout << cc[i - 1].front() <<" " << cc[i].front() << endl;
    }  

    cout << toRemove.size() << endl;  
}