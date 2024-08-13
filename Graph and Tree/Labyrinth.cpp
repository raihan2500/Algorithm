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

#define sz(x)              ((int)(x).size())
#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9 + 7;
int n, m;
vector<string> graph, store;
bool isFind = false;
string ANS;
int sgn = 0;

int cnt = 0;

void dfs(int i, int j, string ans){ 
    cnt++;
    if(i < 0 || j < 0)return;
    if(i >= n || j >= m)return;
    if(graph[i][j] == '#')return;

    if(graph[i][j] == 'B'){
        isFind = true;
        ANS = ans;
        return;
    }
    graph[i][j] = '#';

    if(sgn == 1){
        sgn = 0;
        dfs(i - 1, j, ans + 'U');
        return;
    }else if(sgn == 2){
        sgn = 0;
        dfs(i + 1, j, ans + 'D');
        return;
    }else if(sgn == 3){
        sgn = 0;
        dfs(i, j - 1, ans + 'L');
        return;
    }else if(sgn == 4){
        sgn = 0;
        dfs(i, j + 1, ans + 'R');
        return;
    }

    dfs(i, j - 1, ans + 'L');
    dfs(i, j + 1, ans + 'R');
    dfs(i - 1, j, ans + 'U');
    dfs(i + 1, j, ans + 'D');
}


int32_t main()
{
    fast_in_out;
    cin >> n >> m;
    forn(i,n){
        string str;
        cin >> str;
        graph.push_back(str);
    }
    store = graph;
    int i, j;
    for(i = 0; i < n; i++){
        bool ck = 0;
        for(j = 0; j < m; j++){
            if(graph[i][j] == 'A'){ck = 1; break;}
        }
        if(ck)break;
    }


    vector<string>ans;
    bool CK = 0;
    for(int x = 1; x <= 4; x++){
        ANS.clear();
        graph = store;
        isFind = 0;
        sgn = x;
        dfs(i, j, "");
        ans.push_back(ANS);
        CK |= isFind;
    }

    for(auto a : ans)cout<<a<<endl;
    sort(all(ans));
    if(CK){
        yes;
        cout<<ans.front().size()<<endl<<ans.front()<<endl;
    }
    no;

    cout<<cnt<<endl;
    
}