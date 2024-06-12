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


bool isPalin(string &str, int i, int j){
    while(i < j){
        if(str[i]!=str[j])return false;
        i++;
        j--;
    }
    return true;
}


string longestPalindrome(string s) {
    int n = s.length();
    int mx = 0;
    int f = 0, l = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(isPalin(s, i, j)){
                if((j - i + 1) > mx){
                    mx = j - i + 1;
                    f = i, l = j;
                }
            }

        }
    }

    string ans;
    for(int i = f; i <= l; i++)ans.push_back(s[i]);
    return ans;
        
}



int32_t main()
{
    fast_in_out;
    string str;
    cin>>str;
    cout<<longestPalindrome(str);
}