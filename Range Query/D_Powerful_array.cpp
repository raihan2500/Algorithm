#include<bits/stdc++.h>
using namespace std;


#define all(v) v.begin(), v.end()
#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct Q{
    int id, l, r;
};

int n, v[N];
int rootN;

int sq(int n){
    return n * n;
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int queries;
    cin >> n >> queries;
    for(int i = 1; i <= n; i++)cin >> v[i];
    rootN = sqrtl(n);

    vector<Q> q(queries);
    for(int i = 0; i < queries; i++){
        q[i].id = i;
        cin >> q[i].l >> q[i].r;
    }

    sort(all(q), [](Q &a, Q &b){
        if(a.l / rootN == b.l / rootN){
            return a.r > b.r;
        }
        return a.l / rootN < b.l / rootN;
    });

    int ans[queries];
    int cur_l = 1, cur_r = 0, l, r, x;
    vector<int> mp(1e6 + 10);
    int sum = 0;

    for(auto it : q){
        l = it.l;
        r = it.r;

        while(cur_r < r){
            x = v[++cur_r];
            sum -= sq(mp[x]) * x;
            mp[x]++;
            sum += sq(mp[x]) * x;
        }
        while(cur_r > r){
            x = v[cur_r--];
            sum -= sq(mp[x]) * x;
            mp[x]--;
            sum += sq(mp[x]) * x;
        }

        while(cur_l > l){
            x = v[--cur_l];
            sum -= sq(mp[x]) * x;
            mp[x]++;
            sum += sq(mp[x]) * x;
        }

        while(cur_l < l){
            x = v[cur_l++];
            sum -= sq(mp[x]) * x;
            mp[x]--;
            sum += sq(mp[x]) * x;
        }
        ans[it.id] = sum;
    }

    for(int i = 0; i < queries; i++){
        cout << ans[i] << endl;
    }

}