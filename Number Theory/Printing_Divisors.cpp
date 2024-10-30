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
#define print(arr)         for(auto x: arr)cout<<x<<" ";
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

set<int> func(int n){
    set<int> s;
    for(int i = 1; i * i <= n; i++){
        if(n % i != 0)continue;
        s.insert(i);
        s.insert(n / i);
    }
    return s;
}

vin op(set<int>&s){
    vin toRemove;
    int div = *s.begin();
    for(auto i : s){
        if(i % div == 0){
            toRemove.push_back(i);
            div = i;
        }
    }
    for(auto i : toRemove)s.erase(i);

    return toRemove;
}

void sukuna(int test){
    cout << "Case " << test <<":\n";
    lin(n);
    vin v;
    set<int> s = func(n);
    s.erase(s.begin());

    bool flg = 1;
    cout << 1 <<" ";
    while(!s.empty()){
        vin temp = op(s);
        if(flg){
            print(temp);
        }else{
            reverse(all(temp));
            print(temp);
        }
        flg = !flg;
    }

       
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    Forn(i,test)sukuna(i);
    return 0;
}