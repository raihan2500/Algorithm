#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
#define print(arr)          for(auto x: arr)clog<<x<<" "; clog << endl;


#define int long long
const int N = 30005;

struct Q{
    int id, l, r, k;
};

int n, rootN;
int v[N];

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)cin >> v[i];

    rootN = sqrtl(n);
    int q; cin >> q;

    vector<Q> query(q);
    for(int i = 0; i < q; i++){
        cin >> query[i].l >> query[i].r >> query[i].k;
        query[i].id = i;
    }

    sort(query.begin(), query.end(),[](Q &a, Q&b){
        if(a.l / rootN == b.l / rootN)return a.r > b.r;
        return a.l / rootN < b.l / rootN;
    });
    vector<int> ans(q);

    int cur_l = 1, cur_r = 0, sz = 0;
    ordered_set s;

    for(auto q : query){
        while(cur_r < q.r){
            s.insert(v[++cur_r]);
            sz++;
        }
        while(cur_r > q.r){
            s.erase(s.upper_bound(v[cur_r--]));
            sz--;
        }
        while(cur_l > q.l){
            s.insert(v[--cur_l]);
            sz++;
        }
        while(cur_l < q.l){
            s.erase(s.upper_bound(v[cur_l++]));
            sz--;
        }
        // clog <<"Q: " << q.l <<" " << q.r << endl;
        // print(s);
        // clog << sz << endl << endl;

        ans[q.id] = sz - s.order_of_key(q.k + 1);
    }

    for(auto i : ans)cout << i << endl;
}