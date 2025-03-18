#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int sum = 0, unkn = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '+')sum++;
        else sum--;
        if(t[i] == '+')sum--;
        else if(t[i] == '-')sum++;
        else unkn++;
    }

    double ans = 0;

    for(int i = 0; i < (1 << unkn); i++){
        int cnt = __builtin_popcount(i);
        int cur = sum + (cnt - (unkn - cnt));
        if(cur == 0){
            ans += 1.0 / (1 << unkn);
        }
    }

    cout << fixed << setprecision(9) << ans << endl;
}