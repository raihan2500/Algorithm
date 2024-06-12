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

void permutation(vector<string> &ans, string &str, string s, int &n, int i){

    if(i == n){
        ans.push_back(s);
        return;
    }

    if(str[i] < 65){
        s.push_back(str[i]);
        permutation(ans, str, s, n, i + 1);
    }
    else{
        s.push_back(str[i]);
        permutation(ans, str, s, n, i + 1);
        s.pop_back();
        if(str[i] < 97){
            s.push_back(str[i] + 32);
            permutation(ans, str, s, n, i + 1);            
        }
        else{
            s.push_back(str[i] - 32);
            permutation(ans, str, s, n, i + 1);
        }

    }

}

vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    int  n = s.size();
    permutation(ans, s, {}, n , 0);
    return ans;
}


int32_t main()
{
    fast_in_out;
    string str;
    cin>>str;
    print(letterCasePermutation(str));

    cout<<(char)('Z' + 32);
    
    
}