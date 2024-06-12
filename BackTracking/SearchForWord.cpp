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

int row, column;
bool check = 0;

void back(vector<vector<char>> &v, string& str, int i, int j, string ans){
    if(check)return;

    if(ans == str){

        check = 1;
        return;
    }

    if(i == row && j == column){
        // cout<<ans<<" ";
        return;
    }

    if(i < row){
        back(v, str, i + 1, j, ans);

        string s = ans;
        s.push_back(v[i][j]);
        back(v, str, i + 1, j, s);
    }

    if(j < column){

        back(v, str, i, j + 1, ans);    

        string s = ans;
        s.push_back(v[i][j]);
        back(v, str, i, j + 1, s);    
    }
}



bool exist(vector<vector<char>>& board, string word) {
    row = board.size();
    column = board[0].size();
    row--; column --;
    back(board, word, 0, 0, "");
    return check;    
}


int32_t main()
{
    fast_in_out;
    lin(n) lin(m);
    string word;
    cin>>word;
    vector<vector<char>> v(n);
    forn(i,n){
        forn(j,m){
            char ch;
            cin>>ch;
            v[i].push_back(ch);
        }
    }

    // for(auto a : v){
    //     print(a);
    // }
    cout<<(bool)exist(v, word);
    
    
}