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
#define printt(v)          for(int i = 97; i < 124; i++)cout<<v[i]<<" "; cout<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool checkInclusion(string s1, string s2) {
    fast_in_out;
    
    int n = s2.size(), m = s1.size();
    unordered_map<char, int> m1, m2;
    for(int i =0; i < m; i++){
        m1[s1[i]]++;
    }        

    for(int i = 0; i < n; i++){
        m2[s2[i]]++;
        if(i >= m){
            m2[s2[i - m]]--;
            if(m2[s2[i - m]] == 0){
                m2.erase(s2[i - m]);
            }
        }
        if(m1 == m2)return true;
    }

    return false;
    
}


int32_t main()
{
    fast_in_out;
    string s1, s2;
    cin>>s1>>s2;
    cout<<checkInclusion(s1, s2);

    
    
}