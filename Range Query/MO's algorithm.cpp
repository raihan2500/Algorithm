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


int n, m, v[N];

const int BS = 400;
struct Q{int id, l, r; };
bool cmp(Q &a, Q &b){
    if(a.l / BS == b.l / BS)return a.r > b.r;
    return a.l / BS < b.l / BS;
}

int add(int i){
    return v[i];
}
int rem(int i){
    return v[i];
}

void Solve(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> v[i];

    vector<Q> query(m);
    for(int i = 0; i < m; i++){cin >> query[i].l >> query[i].r;  query[i].id = i;}
    sort(query.begin(), query.end(), cmp);

    vector<int> ans(m);
    int l = 0, r = 0, res = 0;
    for(auto q : query){
        while(r < q.r)res += add(++r);
        while(r > q.r)res -= rem(r--);

        while(l > q.l)res += add(--l);
        while(l < q.l)res -= rem(l++);
        ans[q.id] = res;
    }

    for(int i = 0; i < m; i++)cout << ans[i] << endl;
}




int32_t main(){
    Solve();
  
}