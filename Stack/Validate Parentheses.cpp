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


bool isValid(string s) {
    stack<char> st;
    st.push(s[0]);
    
    for(int i = 1; i < s.size(); i++){

        if(s[i] == ')'){
            if(st.top() == '('){
                st.pop();
                continue;
            }
        }
        if(s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
                continue;
            }
        }
        if(s[i] == ']'){
            if(st.top() == '['){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }

    if(st.empty())return true;
    return false;
        
}


int32_t main()
{
    fast_in_out;
    string str;
    cin>>str;
    // cout<<fixed<<(int)'{'<<(int)'}';
    cout<<isValid(str);

    
}