#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define print(v)        for(auto i : v)cout << i << " ";cout << endl;

const int M = 1e9 + 7;
const int N = 2e5 + 10;


int32_t main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;
    while(n > 0){

        int m = (1 << n);
        int mx = 0, bit = 0;
        for(int i = 1; i < m; i++){
            bool flg = 0;
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    sum += v[j];
                }
                // if(sum == x)break;
                if(sum > x){flg = true; break;}
            }
            if(sum > x)continue;
            
            if(sum > mx){
                mx = sum;
                bit = i;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                v.erase(v.begin() + i - cnt);
                cnt++;
            }
        }
        ans++;
        n -= cnt;
        cout << mx << endl;
    }

    cout << ans << endl;
    
}