#include<bits/stdc++.h>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> countOfDevisors(n, 0);

    for(int i = 1; i * i <= r; i++){
        int st = ceil(l * 1.0 / i) * i;
        for(int j = st; j <= r; j += i){
            if(i * i > j)continue;
            countOfDevisors[j - l] += 2;
            if(i * i == j)countOfDevisors[j - l]--;
        }
    }
    int mx = *max_element(countOfDevisors.begin(), countOfDevisors.end());
    int ans = 1;

    for(int i = 0; i < n; i++){
        if(countOfDevisors[i] == mx){
            ans = l + i;
            break;
        }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n",l, r, ans, mx);

}

int32_t main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
    
}
//https://vjudge.net/problem/UVA-294