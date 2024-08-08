#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
#define all(v)      v.begin(), v.end()
const int M = 1e9 + 7;

int32_t main(){
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(all(a));
    sort(all(b));


    for(int i = 0, j = 0; i < m && j < n; i++){

        for(; j < n; j++){
            if(abs(b[i] - a[j]) <= k){
                ans++;
                j++;
                break;
            }
            if(a[j] > b[i]){
                break;
            }
        }

    }
    cout<<ans<<endl;  
}