#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int fact[N];

int mmiOfX(int a, int b = M - 2){
    int ans = 1;

    while(b > 0){
        if(b & 1)ans = ((ans % M) * (a % M)) % M;
        b >>=  1;
        a = ((a % M) * (a % M)) % M;
    }
    return ans;
}


int32_t main(){

    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = ((i % M) * (fact[i - 1] % M)) % M;
    }


    string str;
    cin >> str;
    int n = str.size();
    int arr[26] = {0};
    for(auto c : str)arr[c - 97]++;

    int ans = fact[n];

    for(int i = 0; i < 26; i++){
        if(arr[i] < 2)continue;
        
        int mmi = mmiOfX(fact[arr[i]]);
        ans = ((ans % M) * (mmi % M)) % M;
    }
    cout << ans << endl;
    
}