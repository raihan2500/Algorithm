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
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e3 + 100;
int n, m;
vector<string> v;
int vis[N][N];
int cnt = 0;
string big_string;

string recur(int i, int j){
    cnt++;
    // if(cnt > 10)return "*";

    if(i >= n || i < 0)return "*";
    if(j >= m || j < 0)return "*";
    if(v[i][j] == 'B')return "";
    if(v[i][j] == '#')return "*";

    v[i][j] = '#';
    vector<string> ans(4);


    ans[0] ="D" + recur(i + 1, j);
    ans[1] ="U" + recur(i - 1, j);

    ans[2] ="R" + recur(i, j + 1);
    ans[3] ="L" + recur(i, j - 1);



    string a = big_string;
    int ln = INF;
    
    for(auto it : ans){
        // bool ck = 0;
        // for(auto c : it)if(c == '*'){ck = 1; break;}
        // if(ck)continue;
        if(it.back() == '*')continue;
        if(it.size() < ln){
            ln = it.size();
            a = it;
        }
    }
    return a;
}


int32_t main()
{
    fast_in_out;
    for(int i = 0; i < n * m; i++)big_string.push_back('Z');


    cin >> n >> m;
    forn(i,n){
        string str;
        cin >> str;
        v.pb(str);
    }
    int i = 0, j = 0;
    for(; i < n; i++){
        bool ck = 0;
        for(j = 0; j < m; j++){
            if(v[i][j] == 'A'){
                ck = 1;
                break;
            }
        }
        if(ck)break;
    }
    if(v[i][j] != 'A'){
        no;
        return 0;
    }

    string ans = recur(i, j);

    if(ans == big_string || ans == "*"){
        no;
        return 0;
    }

    yes;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    
}