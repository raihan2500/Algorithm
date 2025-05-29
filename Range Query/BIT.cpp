#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct BIT{
    int n;
    vector<int> tree, v;
    BIT(vector<int> v) : v(v){
        n = v.size();
        tree.resize(n);
        for(int i = 1; i < n; i++)add(i, v[i]);
    }
    int query(int i){
        int ans = 0;
        for(; i > 0; i -= (i & -i))ans += tree[i];
        return ans;
    }
    int query(int l, int r){
        return query(r) - query(l - 1);
    }

    void add(int i, int val){
        for(; i < n; i += (i & -i))tree[i] += val;
    }
};

int32_t main(){
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++)cin >> v[i];
    BIT bit(v);

    cout << bit.query(2, 5) << endl;

}