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

int32_t main(){
    fast_in_out;
    lin(n);
    vin dfs(n), bfs(n);

    forn(i,n)cin >> bfs[i];
    forn(i,n)cin >> dfs[i];

    if(dfs[1] != bfs[1]){
        cout << -1 << endl;
        return 0;
    }

    cout << 2 * (n - 1) - 1 << endl;
    
    for(int i = 1; i < n; i++){
        cout << dfs[i - 1] <<" " << dfs[i] << endl;
    }
    for(int i = 2; i < n; i++){
        cout << 1 <<" " <<bfs[i] << endl;
    }
}