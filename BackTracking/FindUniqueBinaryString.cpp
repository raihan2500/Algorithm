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

bool check = false;
string A;
void backTracking(map<string, int> &m, string str, int & n){

    if(check)return;
    if(str.size() == n){
        if(!m[str]){
            A = str;
            check = true;
        }
        // cout<<str<<endl;
        return;
    }

    str.push_back('0');
    backTracking(m, str, n);
    str.pop_back();
    str.push_back('1');
    backTracking(m, str, n);
}



string findDifferentBinaryString(vector<string>& nums) {
    
    int n = nums.size();
    string ans;
    map<string, int>m;
    for(int i = 0; i < n; i++){
        m[nums[i]]++;
    }

    backTracking(m, {}, n);
    

    return A;
}



int32_t main()
{
    fast_in_out;
    lin(n);
    vector<string> nums(n);
    forn(i,n)cin>>nums[i];
    cout<<findDifferentBinaryString(nums); 
    
}