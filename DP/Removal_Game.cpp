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
int n;
vin v;

int recur(int i, int j, bool flg = true){
    if(i >= j){
        return 0;
    }

    int x = v[i] + recur(i + 1, j, !flg);
    int y = v[j] + recur(i, j - 1, !flg);
    
    if(flg)return max(x, y);
    else return 0;
}

int32_t main(){
    fast_in_out;
    cin >> n;
    forn(i,n){
        lin(x);
        v.push_back(x);
    }

    cout << recur(0, n - 1) << endl;


    
}