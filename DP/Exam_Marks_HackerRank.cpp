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
vin v;
vector<vin> temp(1005, vin (1200, -1)), dp;
bool isDone = false;

int recur(int ind, int rem){
    
    if(isDone)return true;
    if(rem == 0)return isDone = true;
    if(rem < 0)return 0;
    if(ind >= n)return 0;

    if(dp[ind][rem] != -1)return dp[ind][rem];

    int x = recur(ind + 1, rem);
    int y = recur(ind + 1, rem - v[ind]);

    return dp[ind][rem] = x or y;    
}

void sukuna(){
    dp = temp;
    v.clear();
    isDone = false;

    cin >> n >> m;
    m = 1000 - m;
    forn(i,n){
        lin(x);
        v.push_back(x);
    }

    if(recur(0, m))yes;
    else no;    
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    while(test--)sukuna();
    return 0;
}