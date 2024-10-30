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

bool primeChk(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return false;
    }
    return true;
}

void sukuna(int n){
    int m = n;
    map<int, int> mp;
    for(int i = 2; i * i <= n; i++){
        if(m % i != 0)continue;
        while(m % i == 0){
            if(i == m){
                m = 1;
                continue;
            }
            if(primeChk(i))mp[i]++;
            if(primeChk(m / i)){
                if(m / i != i)mp[m / i]++;
            }
            // cout << i <<" " << m/ i << endl;
            m /= i;
        }
    }
    for(auto i : mp){
        if(i.first == 1)continue;
        cout << i.first<<"^"<<i.second <<" ";
    }
    nl;
    
    
}

int32_t main(){
    fast_in_out;
    int n;
    cin >> n;
    while(n != 0){
        sukuna(n);
        cin >> n;
    }
}