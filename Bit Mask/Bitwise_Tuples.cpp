#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             ll n;cin>>n;
#define in(n)              int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define srt(v)             sort(v.begin(),v.end());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second
#define mmp                make_pair

#define sz(x)              ((int)(x).size())
#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;

int power(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = (ans * a) % M;
        b >>= 1;
        a = (a * a) % M;
    }
    return ans;
}

int bin(int n){
    int ans = 0, b = 1;
    while(n --){
        b = (b * 2) % M;
    }
    return b;
}

void sukuna(){
    int n, m;
    cin >> n >> m;
    int ans = bin(m);
    ans = power(ans, n) - power(ans, n - 1);
    

    cout<<ans<<endl;

    
}

int32_t main(){
    fast_in_out;

    int test;	cin>>test;
    while(test--)sukuna();
    return 0;
}