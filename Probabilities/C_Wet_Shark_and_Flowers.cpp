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


int32_t main(){
    int n, p;
    cin >> n >> p;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
    vector<double> prob;

    for(auto &[a, b] : v){
        int tot = b - a + 1;
        int valid = b / p - (a - 1) / p;
        prob.push_back(valid * 1.0 / tot);
    }

    clog << prob << endl;
    double ans = 0, not_ok = 1;
    for(auto p : prob){
        ans += not_ok * p;
        not_ok *= (1.0 - p);
        clog << not_ok << endl;
    }

    cout << ans * (n * 2) * 1000 << endl;
}