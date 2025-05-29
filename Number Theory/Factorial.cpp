#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++)cin >> v[i].first, v[i].second = i;
    vector<int> ans(n, 1);
    sort(v.begin(), v.end());

    int fact = 1, i = 1;
    while(!v.empty() and v[0].first == 0)v.erase(v.begin());

    for(auto p : v){
        for(; i <= p.first; i++){
            fact = (uint64_t)fact * i % M;
        }
        ans[p.second] = fact;
    }
    for(int i = 0; i < n; i++)cout << ans[i] << endl;
  
}