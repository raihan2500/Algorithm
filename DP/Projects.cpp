#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct grp{int l, r, p;};

int n;
vector<grp> v;
vector<int> st, dp(N, -1);

int recur(int ind){

    if(ind >= n)return 0;
    if(dp[ind] != -1)return dp[ind];

    int a = recur(ind + 1);
    int lb = lower_bound(all(st), v[ind].r + 1) - st.begin();
    int b = v[ind].p + recur(lb);

    return dp[ind] = max(a, b);    
}


int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r, p;
        cin >> l >> r >> p;
        v.push_back({l, r, p});
    }

    sort(v.begin(), v.end(),[](grp a, grp b){
        if(a.l < b.l)return true;
        if(a.l == b.l)return a.r < b.r;
        return false;
    });

    for(auto i : v)st.push_back(i.l);

    cout << recur(0) << endl;
}