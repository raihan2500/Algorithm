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
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define srt(v)             sort(v.begin(),v.end());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second
#define mmp                make_pair

#define sz(x)              ((ll)(x).size())
#define forn(i,e)          for(ll i=0;i<e;i++)
#define Forn(i,e)          for(ll i=1;i<=e;i++)
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void strPB(string &str, int n, char c){
    for(int i = 0; i < n; i++){
        str.push_back(c);
    }
}


string intToRoman(int num) {
    string str;
    if(num >= 1000){
        int n = num / 1000;
        num %= 1000;
        strPB(str, n, 'M');
    }
    if(num >= 500){
        int n = num / 500;
        num %= 500;
        strPB(str, n, 'D');
    }
    if(num >= 100){
        int n = num / 100;
        num %= 100;
        strPB(str, n, 'C');
    }
    if(num >= 50){
        int n = num / 50;
        num %= 50;
        strPB(str, n, 'L');
    }
    if(num >= 10){
        int n = num / 10;
        num %= 10;
        strPB(str, n, 'X');
    }
    if(num >= 5){
        int n = num / 5;
        num %= 5;
        strPB(str, n, 'V');
    }
    if(num >= 1){
        int n = num / 1;
        num %= 1;
        strPB(str, n, 'I');
    }

    return str;
    
        
}


int32_t main()
{
    fast_in_out;
    int n;
    cin>>n;
    cout<<intToRoman(n);
    
    
}