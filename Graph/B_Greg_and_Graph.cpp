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
const int N =500 + 10;

int n;
vector<vin> graph(N, vin (N, INF));

void reset(){

}

int32_t main(){
    fast_in_out;
    cin >> n ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)cin >> graph[i][j];
    }   
    vin del(n), ans;
    rforn(i,n)cin >> del[i];
    
    for(int k = 0; k < n; k++){
        int v = del[k];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int new_dist = graph[i][v] + graph[v][j];
                graph[i][j] = min(graph[i][j], new_dist);
            }
        }

        int sum = 0;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k; j++){
                sum += graph[del[i]][del[j]];
            }
        }
        ans.push_back(sum);        
    }
    reverse(all(ans));
    print(ans);  


}