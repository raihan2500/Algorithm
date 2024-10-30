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
const int N = 1e3 + 100;

vector<pr> movement = {{0, 1}, {1, 0}};

int n, m, k;
vector<string> v;
vector<vin> dp(N, vin (N, -1));

bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int recur(int i, int j){

    if(i == n - 1 && j == m - 1)return 1;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = 0;
    for(auto mv : movement){
        int x = i + mv.first;
        int y = j + mv.second;
        if(!isValid(x, y))continue;
        if(v[x][y] == '#')continue;
        ans += recur(x, y);
        ans %= M;
    }
    return dp[i][j] = ans;
}

void sukuna(int test){
    cin >> n >> m >> k;
    string str;
    forn(i,m)str.push_back('.');
    forn(i,n)v.push_back(str);
    forn(i, k){
        int x, y;
        cin >> x >> y;
        v[--x][--y] = '#';
    }
    
    cout << recur(0, 0) << endl;

}

int32_t main(){
    fast_in_out;

    int test = 1;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}