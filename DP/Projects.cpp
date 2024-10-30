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
struct grp{int x, y, z; void display(){cout << x <<" " << y <<" " << z << endl;}};
vector<grp> v;

vector<pr> dp(N, {-1, -1});

int recur(int ind, int prev){

    if(ind == n){
        return 0;
    }

    int x = recur(ind + 1, prev);
    int y = x;
    if(prev < v[ind].x){
        y = v[ind].z + recur(ind + 1, v[ind].y);
    }

    return max(x, y);
}

int32_t main(){
    fast_in_out;
    cin >> n;
    forn(i,n){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }
    sort(all(v), [](grp a, grp b){return a.x < b.x;});

    cout << recur(0, 0) << endl;
    
    
}