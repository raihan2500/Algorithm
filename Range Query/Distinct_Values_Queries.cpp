#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, v[N], mp[N], rootN;

int32_t main(){
    cin >> n >> m;
    map<int, int> hash;

    int cur_hash = 1;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(hash.find(v[i]) != hash.end()){
            v[i] = hash[v[i]];
        }else{
            hash[v[i]] = cur_hash;
            v[i] = cur_hash++;
        }
    }

    struct query{
        int id, l, r;
    };
    vector<query> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    rootN = sqrtl(n);
    sort(q.begin(), q.end(), [](query &a, query &b){
        if(a.l / rootN == b.l / rootN)return a.r > b.r;
        return a.l / rootN < b.l / rootN;
    });

    int ans[m];
    int dist = 0, cur_l = 0, cur_r = 0;
    for(auto i : q){
        while(cur_r < i.r){
            cur_r++;
            if(mp[v[cur_r]] == 0)dist++;
            mp[v[cur_r]]++;
        }
        while(cur_r > i.r){
            mp[v[cur_r]]--;
            if(mp[v[cur_r]] == 0)dist--;
            cur_r--;
        }

        while(cur_l > i.l){
            cur_l--;
            if(mp[v[cur_l]] == 0)dist++;
            mp[v[cur_l]]++;
        }
        while(cur_l < i.l){
            mp[v[cur_l]]--;
            if(mp[v[cur_l]] == 0)dist--;
            cur_l++;
        }
        ans[i.id] = dist;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
    

}